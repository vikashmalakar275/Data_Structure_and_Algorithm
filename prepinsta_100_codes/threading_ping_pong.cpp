#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex mtx;
bool isPingTurn = true;
bool isPongTurn = false;

void ping() 
{
    while(1)
    {
        unique_lock<mutex> lock(mtx);
        if(isPingTurn)
        {
            cout<<"ping"<<endl;
            isPingTurn = false;
            isPongTurn = true;
        }
    }
}

void pong() {
    while(1)
    {
        unique_lock<mutex> lock(mtx);
        if(isPongTurn)
        {
            cout<<"pong"<<endl;
            isPingTurn = true;
            isPongTurn = false;
        }
    }
}

int main() {
    thread pingThread(ping);
    thread pongThread(pong);

    pingThread.join();
    pongThread.join();

    return 0;
}
