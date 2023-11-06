/*
Doublu Linked List

operation:-
1. Create linked list.
2. Insert New Node at Beginning.
3. Insert New Node at End.
4. Insert New Node at Any position.
5. Delete from beginning.
6. Delete from End.
7. Delete from Any Position.
8. Search a Element on a Linked List.
9. Display Linked List.
10. Get Length of Linked List.
*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr; // Initialize the head of Doubly Linked List.
Node* tail = nullptr; //Initialize the tail of Duobly Linked List

Node* createNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void createDLL()
{
    cout<<"Enter the initial size of Double Linked List :"<<endl;
    int n;
    cin>>n;
    while (n-->0)
    {
        Node* new_node = new Node;
        cout<<"Enter data :";
        cin>>new_node->data;
        new_node->next = NULL;
        new_node->prev = NULL;
        if(head->next == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            new_node->prev = tail;
            tail = tail->next; 
        }
    }
    

}

void insertAtBeginning(int data)
{

}

void insertAtEnd(int data)
{

}

void insertAtPosition(int data, int position)
{

}

void deleteFromBeginning()
{

}

void deleteFromEnd()
{

}

void deleteFromPosition(int position)
{

}

bool searchElement(int data)
{

}

void display()
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<" <=> ";
        temp = temp->next;
    }
    cout<<" nullpte "<<endl;
}

void getLength()
{

}

int main()
{
    while (1) 
    {
        cout<<"==================================================\n";
        cout << "Enter your choice :" << endl;
        cout << "1. Create Doubly linked list.\n";
        cout << "2. Insert New Node at Beginning.\n";
        cout << "3. Insert New Node at End.\n";
        cout << "4. Insert New Node at Any position.\n";
        cout << "5. Delete from beginning.\n";
        cout << "6. Delete from End.\n";
        cout << "7. Delete from Any Position.\n";
        cout << "8. Search a Element on a Doubly Linked List.\n";
        cout << "9. Display Doubly Linked List.\n";
        cout << "10. Get Length of doubly Linked List.\n";
        cout << "11. Exit.\n";
        cout<<"==================================================\n";
        int choice;
        cin >> choice;
        switch (choice) 
        {
            case 1:
                createDLL();
                break;
            case 2:
                int data;
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                insertAtBeginning(data);
                break;
            case 3:
                cout << "Enter data to insert at the end: ";
                cin >> data;
                insertAtEnd(data);
                break;
            case 4:
                int position;
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter position to insert: ";
                cin >> position;
                insertAtPosition(data, position);
                break;
            case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                cout << "Enter position to delete: ";
                cin >> position;
                deleteFromPosition(position);
                break;
            case 8:
                cout << "Enter element to search: ";
                cin >> data;
                if (searchElement(data)) 
                {
                    cout << "Element found in the linked list." << endl;
                } else {
                    cout << "Element not found in the linked list." << endl;
                }
                break;
            case 9:
                display();
                break;
            case 10:
                getLength();
                break;
            case 11:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}