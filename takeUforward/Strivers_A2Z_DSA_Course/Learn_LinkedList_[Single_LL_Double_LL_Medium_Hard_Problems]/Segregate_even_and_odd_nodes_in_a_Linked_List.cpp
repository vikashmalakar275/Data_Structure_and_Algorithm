/*
Given a Linked List of integers, write a function to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list. Also, keep the order of even and odd numbers the same.

Examples: 

Input: 17->15->8->12->10->5->4->1->7->6->NULL
Output: 8->12->10->4->6->17->15->5->1->7->NULL

Input: 8->12->10->5->4->1->6->NULL
Output: 8->12->10->4->6->5->1->NULL

// If all numbers are even then do not change the list

Input: 8->12->10->NULL
Output: 8->12->10->NULL

// If all numbers are odd then do not change the list

Input: 1->3->5->7->NULL
Output: 1->3->5->7->NULL
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

//Linked List Creation Logic End


Node* segregateEvenOdd(Node* head)
{  
    Node* end = head;  
    Node* prev = NULL;  
    Node* curr = head;

    while (end->next != NULL)
    {
        end = end->next;
    }  
    
    Node* new_end = end;

    while(curr->data % 2 != 0 && curr != end)  
    {  
        new_end->next = curr;  
        curr = curr->next;  
        new_end->next->next = NULL;  
        new_end = new_end->next;  
    }

    if(curr->data %2 == 0)  
    {
        head = curr;  
        while(curr != end)  
        {  
            if((curr->data) % 2 == 0)  
            {  
                prev = curr;  
                curr = curr->next;  
            }  
            else
            {
                prev->next = curr->next;
                curr->next = NULL;
                new_end->next = curr;
                new_end = curr;
                curr = prev->next;  
            }  
        }  
    }
    else
    {
        prev = curr;
    }  
  
    if (new_end != end && (end->data) % 2 != 0)  
    {  
        prev->next = end->next;  
        end->next = NULL;  
        new_end->next = end;  
    }  
    return head;  
} 

int main() 
{
    Node* head = nullptr; // Initialize the head of the linked list
    cout<<"Create a Linked List:"<<endl;
    head = createLinkedList(head);
    cout<<"Linked List After creation :"<<endl;
    displayLinkedList(head);

    Node* res_head = segregateEvenOdd(head);
    cout<<"Resulted Linked List :"<<endl;
    displayLinkedList(res_head);
    return 0;
}