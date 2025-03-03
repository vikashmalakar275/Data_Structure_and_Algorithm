/*
Problem Statement: Given the head of a linked list of integers, delete the middle node of the linked list and return the modified head. However, if the linked list has an even number of nodes, delete the second middle node.

Examples
Example 1:

Input Format:

LL: 1  2  3  4  5 


Output: 1 2 4 5


Explanation: Node with value 3 is at the middle node and deleted.

Example 2:

Input Format:

LL: 1  2  3  4


Output: 1 2 4


Explanation: In this example, the linked list has an even number of nodes hence we return the second middle node which is 3.
*/

#include <iostream>
#include <stack>
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

// Function to display the linked list
void displayLinkedList(Node* head) 
{
    Node* temp = head;
    while (temp != nullptr) 
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

//Delete the middle node of the linked list
Node *deleteMiddleNode(Node* head)
{
    int length = 0;
    Node* temp = head;
    while(temp != nullptr)
    {
        length++;
        temp = temp->next;
    }
    Node* newTemp = head;
    for(int i=0;i<length/2-1;i++)
    {
        newTemp = newTemp->next;
    }
    newTemp->next = newTemp->next->next;
    return head;
}

//optimal approach
//Delete the middle node of the linked list
Node *deleteMiddleNode1(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    fast = fast->next->next;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = slow->next->next;
    return head;
     
}

int main() 
{
    Node* head = nullptr; // Initialize the head of the linked list
    cout<<"Create a Linked List:"<<endl;
    head = createLinkedList(head);
    cout<<"Linked List After creation :"<<endl;
    displayLinkedList(head);

    Node* res_head = deleteMiddleNode(head);
    cout<<"Resulted Linked List :"<<endl;
    displayLinkedList(res_head);

    Node* res_head1 = deleteMiddleNode1(head);
    cout<<"Resulted Linked List 1:"<<endl;
    displayLinkedList(res_head1);
    return 0;
}