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
    int size;
    cin>>size;
    while (size-->0)
    {
        Node* new_node = new Node;
        cout<<"Enter data : ";
        int data;
        cin>>data;
        new_node->data = data;
        new_node->next = nullptr;
        new_node->prev = nullptr;
        if(head == nullptr)
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
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data)
{
    Node* newNode = createNode(data);
    tail->next = newNode;
    newNode->prev = tail;
    tail = tail->next;
}


void insertAtPosition(int data, int position)
{
    if (position < 1) 
    {
        cout << "Invalid position." << endl;
        return;
    }
    if (position == 1) 
    {
        insertAtBeginning(data);
    } 
    else 
    {
        Node* newNode = createNode(data);
        Node* temp = head;
        for (int i = 1; i < position - 1; i++) 
        {
            if (temp == nullptr) 
            {
                cout << "Invalid position." << endl;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->prev = newNode->next->prev;
    }
}

void deleteFromBeginning()
{
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd()
{
    Node* temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
}

// 1 <-> 2 <-> 3 <-> 4 <-> null
void deleteFromPosition(int position)
{
    if (position < 1) 
    {
        cout << "Invalid position." << endl;
        return;
    }
    if (position == 1) 
    {
        deleteFromBeginning();
    } 
    else 
    {
        Node* temp = head;
        for (int i = 1; i < position; i++) 
        {
            if (temp == nullptr) 
            {
                cout << "Invalid position." << endl;
                return;
            }
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
}

bool searchElement(int data)
{
    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->data == data)
        {
            return true;
        }
    }
    return false;
}

void display()
{
    if(head == nullptr)
    {
        cout<<"Doubly linked list not create yet."<<endl;
        return;
    }
    Node* temp = head;
    cout<<" NULL <-->";

    while(temp != NULL)
    {
        cout<<temp->data<<" <--> ";
        temp = temp->next;
    }
    cout<<" NULL "<<endl;
}

void getLength()
{
    int len = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    cout<<"Length of Doubly Linked List : "<<len<<endl;
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