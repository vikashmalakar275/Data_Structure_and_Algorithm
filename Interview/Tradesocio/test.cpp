#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Order {
    std::string symbol;
    std::string type;  // "BL" = Buy Limit, "SL" = Sell Limit
    double order_price;
    int quantity;
    int id;
};

struct Tick {
    std::string symbol;
    double price;
    std::string timestamp;
};

class OrderProcessor {
private:
    std::map<std::string, std::multimap<double, Order, std::greater<double> > > buyOrders; // Buy: Highest price first
    std::map<std::string, std::multimap<double, Order, std::less<double> > > sellOrders;   // Sell: Lowest price first

public:
    void addOrder(const Order& order) {
        if (order.type == "BL") {
            buyOrders[order.symbol].insert({order.order_price, order});
        } else if (order.type == "SL") {
            sellOrders[order.symbol].insert({order.order_price, order});
        }
    }

    void newTick(const Tick& tick) {
        auto& buyQueue = buyOrders[tick.symbol];
        auto& sellQueue = sellOrders[tick.symbol];

        // Process Buy Limit Orders (tick.price >= order_price)
        while (!buyQueue.empty() && buyQueue.begin()->first >= tick.price) {
            auto it = buyQueue.begin();
            Order order = it->second;
            buyQueue.erase(it);

            std::cout << "Buy Order " << order.id << " executed at " << tick.timestamp
                      << ", Price: " << tick.price
                      << ", Quantity: " << order.quantity << "\n";
        }

        // Process Sell Limit Orders (tick.price <= order_price)
        while (!sellQueue.empty() && sellQueue.begin()->first <= tick.price) {
            auto it = sellQueue.begin();
            Order order = it->second;
            sellQueue.erase(it);

            std::cout << "Sell Order " << order.id << " executed at " << tick.timestamp
                      << ", Price: " << tick.price
                      << ", Quantity: " << order.quantity << "\n";
        }
    }
};

int main() {
    OrderProcessor processor;

    // Add orders
    processor.addOrder({"AAPL", "BL", 100, 10, 1});
    processor.addOrder({"AAPL", "BL", 105, 5, 2});
    processor.addOrder({"AAPL", "BL", 102, 15, 3});
    processor.addOrder({"AAPL", "BL", 98, 15, 4});
    processor.addOrder({"GOOG", "BL", 200, 10, 5});
    processor.addOrder({"GOOG", "BL", 201, 15, 6});

    // Process ticks
    processor.newTick({"AAPL", 106, "08:58"});
    processor.newTick({"AAPL", 104, "09:00"});
    processor.newTick({"AAPL", 102, "09:01"});
    processor.newTick({"AAPL", 98, "09:02"});
    processor.newTick({"GOOG", 200, "09:03"});

    return 0;
}
