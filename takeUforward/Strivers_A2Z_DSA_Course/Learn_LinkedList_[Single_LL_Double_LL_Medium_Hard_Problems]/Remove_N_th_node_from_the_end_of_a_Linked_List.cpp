/*
Problem Statement: Given a linked list and an integer N, the task is to delete the Nth node from the end of the linked list and print the updated linked list.

Examples
Example 1:
Input Format: 5->1->2, N=2
Result: 5->2
Explanation: The 2nd node from the end of the linked list is 1. Therefore, we get this result after removing 1 from the linked list.

Example 2:
Input Format: 1->2->3->4->5, N=3
Result: 1->2->4->5
Explanation: The 3rd node from the end is 3, therefore, we remove 3 from the linked list.
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

Node* remove_Nth_node_from_end_1(Node* head,int n)
{
    if(head == NULL)
    {
        return NULL;
    }
    int len = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    cout<<"Length of LinkedList = "<<len<<endl;
    
    if(len == n)
    {
        Node* newHead = head->next;
        delete (head);
        return newHead;
    }

    int Nth_node = len-n;
    temp = head;
    cout<<"Position from front = "<<Nth_node+1<<endl;
    while(temp != NULL)
    {
        Nth_node--;
        if(Nth_node == 0)
        {
            break;
        }
        temp = temp->next;
    }
    Node* del = temp->next;
    temp->next = temp->next->next;
    delete(del);
    return head;
}

Node* remove_Nth_node_from_end_2(Node* head,int n)
{
    Node* fast = head;
    Node* slow = head;

    for(int i=0;i<n;i++)
    {
        fast = fast->next;
    }
    if(fast == NULL)
    {
        return head->next;
    }

    while(fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    Node* del = slow->next;
    slow->next = slow->next->next;
    delete(del);
    return head;
}

int main() 
{
    Node* head = nullptr; // Initialize the head of the linked list
    cout<<"Create a Linked List:"<<endl;
    head = createLinkedList(head);
    cout<<"Linked List After creation :"<<endl;
    displayLinkedList(head);

    int n;
    cout<<"Enter the position you want to delete from END :"<<endl;
    cin>>n;

    Node* res_head1 = remove_Nth_node_from_end_1(head,n);
    cout<<"Linked List after delete Nth Node from the end"<<endl;
    displayLinkedList(res_head1);

    Node* res_head2 = remove_Nth_node_from_end_2(head,n);
    cout<<"Linked List after delete Nth Node from the end"<<endl;
    displayLinkedList(res_head2);

    return 0;
}
