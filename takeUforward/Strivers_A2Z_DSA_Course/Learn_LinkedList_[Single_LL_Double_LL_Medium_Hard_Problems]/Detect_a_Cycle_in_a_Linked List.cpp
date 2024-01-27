/*
Example 1:

Input Format:

LL: 1 2 3 4 5

             ^5^
           /   |
1 -> 2 -> 3    |
           \   |
             >4

Result: True

Explanation: The last node with the value of 5 has its ‘next’ pointer pointing back to a previous node with the value of 3. This has resulted in a loop, hence we return true.

Example 2:

Input Format:

LL: 1 2 3 4 9 9

1 -> 2 -> 3 -> 4 -> 9 -> 9

Result: False

Explanation: : In this example, the linked list does not have a loop hence returns false.
*/


#include <iostream>
#include <unordered_map>
using namespace std;

class Node 
{
    public:
    int data;        
    Node* next;
    Node(int data1, Node* next1) 
    {
        data = data1;
        next = next1;
    }
    Node(int data1) 
    {
        data = data1;
        next = nullptr;
    }
};

//Time Complexity: O(N * 2 * log(N) )The algorithm traverses the linked list once, performing hashmap insertions and searches in the while loop for each node. The insertion and search operations in the unordered_map have a worst-case time complexity of O(log(N)). As the loop iterates through N nodes, the total time complexity is determined by the product of the traversal (O(N)) and the average-case complexity of the hashmap operations (insert and search), resulting in O(N * 2 * log(N)). 
//Hashmaps and their time complexities are discussed in more detail here. 
//Space Complexity: O(N) The code uses a hashmap/dictionary to store encountered nodes, which can take up to O(N) additional space, where ‘n’ is the number of nodes in the list. Hence, the spacecomplexity is O(N) due to the use of the map to track nodes.
bool detectLoop(Node* head) 
{
    Node* temp = head;
    unordered_map<Node*, int> nodeMap;
    while (temp != nullptr)
    {
        if(nodeMap.find(temp) != nodeMap.end())
        {
            return true;
        }
        nodeMap[temp] = 1;
        temp = temp->next;  
    }
    return false;
}

//Time Complexity: O(N), where N is the number of nodes in the linked list. This is because in the worst-case scenario, the fast pointer, which moves quicker, will either reach the end of the list (in case of no loop) or meet the slow pointer (in case of a loop) in a linear time relative to the length of the list.
//The key insight into why this is O(N) and not something slower is that each step of the algorithm reduces the distance between the fast and slow pointers (when they are in the loop) by one. Therefore, the maximum number of steps needed for them to meet is proportional to the number of nodes in the list.
//Space Complexity : O(1) The code uses only a constantamount of additionalspace, regardless of the linked list’s length. This is achieved by using two pointers (slow and fast) to detect the loop without any significant extra memory usage, resulting in constantspace complexity, O(1).
bool detectCycle(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) 
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) 
        {
            return true;
        }
    }
    return false;
}

int main() 
{
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third; 

    if(detectLoop(head) && detectCycle(head))
    {
        cout<<"Loop detected in the linked list."<<endl;
    } 
    else 
    {
        cout<<"No loop detected in the linked list."<<endl;
    }
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;
    return 0;
}

