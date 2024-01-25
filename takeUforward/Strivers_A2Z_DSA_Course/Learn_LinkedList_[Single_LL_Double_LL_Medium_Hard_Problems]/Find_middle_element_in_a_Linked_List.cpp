/*
Problem Statement: Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.

Examples:

Input Format: 
( Pointer / Access to the head of a Linked list )
head = [1,2,3,4,5]

Result: [3,4,5]
( As we will return the middle of Linked list the further linked list will be still available )

Explanation: The middle node of the list is node 3 as in the below image.

Input Format: 
Input: head = [1,2,3,4,5,6]

Result: [4,5,6]

Explanation: 
Since the list has two middle nodes with values 3 and 4, we return the second one.
*/

#include <iostream>
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

//Linked List Creation Logic End

//Time Complexity: O(NlogN)
//Space Complexity: O(1)
Node *middleElemtLinkedList(Node* head)
{
    int lengthOfLL = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        lengthOfLL++;
        temp = temp->next;
    }
    temp = head;
    for(int i=0;i<lengthOfLL/2;i++)
    {
        temp = temp->next;
    }
    return temp;
}

//Time Complexity: O(N)
//Space Complexity: O(1)
Node *middleElemtLinkedList_1(Node* head)
{
    Node* fast = head;
    Node* slow = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() 
{
    Node* head = nullptr; // Initialize the head of the linked list
    cout<<"Create a Linked List:"<<endl;
    head = createLinkedList(head);
    cout<<"Linked List After creation :"<<endl;
    displayLinkedList(head);

    cout<<"Calling a function for place head at middle of element :"<<endl;
    Node* middleHead = nullptr;
    middleHead = middleElemtLinkedList(head);
    cout<<"Printing middle element in linked list :"<<endl;
    displayLinkedList(middleHead);

    cout<<"Calling a function for place head at middle of element :"<<endl;
    Node* middleHead1 = nullptr;
    middleHead1 = middleElemtLinkedList_1(head);
    cout<<"Printing middle element in linked list :"<<endl;
    displayLinkedList(middleHead1);
    return 0;
}
