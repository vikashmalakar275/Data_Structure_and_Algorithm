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
#include <unordered_set>
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
Node *createLinkedList(Node* head,int size)
{
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

//Function to create a cycle
void createCycle(Node* &head,int pos) {
    Node* ptr = head;
    Node* temp = head;
    int cnt = 1;
    while(temp->next != NULL) 
    {
        if(cnt != pos) 
        {
            ++cnt;
            ptr = ptr->next;
        } 
        temp = temp->next;
    }
    temp->next = ptr;
}

// Function to display the linked list
void displayLinkedList(Node* head,int size) 
{
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) 
    {
        cout << temp->data << " -> ";
        temp = temp->next;
        count++;
        if(count == (size+1))
        {
            break;
        }
    }
    if( temp == nullptr)
    {
        cout << "nullptr" << endl;
    }
    cout<<endl;
}

//Time Complexity: O(N)
//Reason: Iterating the entire list once.
//Space Complexity: O(N)
//Reason: We store all nodes in a hash table.
Node *starting_point_of_loop_1(Node* head)
{
    Node* temp = head;
    unordered_set<Node*> st;
    while(temp != NULL) 
    {
        if(st.find(temp) != st.end())
        { 
            return temp;
        }
        st.insert(temp);
        temp = temp->next;
    }
    return NULL;
}

int getLoopStartingPostion(Node* head,Node* res)
{
    int pos = 1;
    while(head != res)
    {
        pos++;
        head = head->next;
    }
    return pos;
}

//Time Complexity: O(N)
//Reason: We can take overall iterations and club them to O(N)
//Space Complexity: O(1)
//Reason: No extra data structure is used.
Node* starting_point_of_loop_2(Node* head) 
{
    if(head == NULL||head->next == NULL)
    {
        return NULL;
    }   
    Node* fast = head;
    Node* slow = head;
    Node* entry = head;   
    while(fast->next != NULL && fast->next->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) 
        {
            while(slow != entry) 
            {
                slow = slow->next;
                entry = entry->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main() 
{
    int size;
    Node* head = nullptr;
    cout<<"Create a Linked List:"<<endl;
    cout<<"Enter the size of the newly created linked list."<<endl;
    cin>>size;
    head = createLinkedList(head,size);
    cout<<"Linked List After creation :"<<endl;
    displayLinkedList(head,size);
    cout<<"Creare Cycle in Linked List :"<<endl;
    createCycle(head,3);
    cout<<"Linked List After Cycle creation :"<<endl;
    displayLinkedList(head,size);

    Node* res = starting_point_of_loop_1(head);
    if(res != NULL)
    {
        cout<<"Loop started from position : "<<getLoopStartingPostion(head,res)<<endl;
    }
    else
    {
        cout<<"No Loop is there."<<endl;
    }

    Node* res1 = starting_point_of_loop_2(head);
    if(res1 != NULL)
    {
        cout<<"Loop started from position : "<<getLoopStartingPostion(head,res1)<<endl;
    }
    else
    {
        cout<<"No Loop is there."<<endl;
    }
    return 0;
}