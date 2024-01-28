/*
Problem Statement: Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that the tail’s next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

Examples:

Example 1:
Input:
 head = [1,2,3,4,3,6,10]
Output:
 tail connects to node index 2
Explanation:

Example 2:
Input:
 head = [1,2]
Output:
 no cycle
Explanation:

*/

#include <iostream>
#include <unordered_map>
using namespace std;

//Linked List Creation Logic Start
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

//Function to create a Linked List
Node *createLinkedList(Node* head)
{
    cout<<"Enter the size of the newly created linked list."<<endl;
    int size;
    cin>>size;
    while(size-->0)
    {
        Node* new_node = new Node;
        cout << "Enter data: ";
        cin >> new_node->data;
        new_node->next = NULL;
        if(head == NULL)
        {
            head = new_node;
        }
        else
        {
            Node* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
    return head;
}

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
    Node* head = nullptr;
    Node* Node1 = new Node();
    Node1 = createNode(1);
    head = Node1;

    Node* Node2 = new Node();
    Node2 = createNode(2);

    Node* Node3 = new Node();
    Node3 = createNode(3);

    Node* Node4 = new Node();
    Node4 = createNode(4);

    Node* Node5 = new Node();
    Node5 = createNode(5);

    Node5->next = Node3;

    if(detectLoop(head) && detectCycle(head))
    {
        cout<<"Loop detected in the linked list."<<endl;
    } 
    else 
    {
        cout<<"No loop detected in the linked list."<<endl;
    }
    return 0;
}

