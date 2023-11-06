/*
Singly Linked List

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

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr; // Initialize the head of the linked list

// Function to create a new node
Node* createNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void create()
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
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(int data)
{
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(int data) 
{
    Node* newNode = createNode(data);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to insert a new node at a specific position in the linked list
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
    }
}

// Function to delete a node from the beginning of the linked list
void deleteFromBeginning() 
{
    if (head == nullptr) 
    {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Function to delete a node from the end of the linked list
void deleteFromEnd() 
{
    if (head == nullptr) 
    {
        cout << "List is empty." << endl;
        return;
    }
    if (head->next == nullptr) 
    {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) 
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

// Function to delete a node from a specific position in the linked list
void deleteFromPosition(int position) 
{
    if (head == nullptr) 
    {
        cout << "List is empty." << endl;
        return;
    }
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
        for (int i = 1; i < position - 1; i++) 
        {
            if (temp->next == nullptr) 
            {
                cout << "Invalid position." << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp->next == nullptr) 
        {
            cout << "Invalid position." << endl;
            return;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }
}

// Function to search for an element in the linked list
bool searchElement(int data) 
{
    Node* temp = head;
    int count = 0;
    while (temp != nullptr) 
    {
        count++;
        if (temp->data == data) 
        {
            cout<<"Element found at position = "<<count<<"."<<endl;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

//Function to get length of linked list
void getLength()
{
    Node* temp = head;
    int len = 0;
    while(temp->next != nullptr)
    {
        len++;
        temp = temp->next;
    }
    cout<<"Length of the linked list = "<<len+1<<endl;
}

// Function to display the linked list
void display() 
{
    Node* temp = head;
    while (temp != nullptr) 
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main() 
{
    while (1) 
    {
        cout<<"==================================================\n";
        cout << "Enter your choice :" << endl;
        cout << "1. Create linked list.\n";
        cout << "2. Insert New Node at Beginning.\n";
        cout << "3. Insert New Node at End.\n";
        cout << "4. Insert New Node at Any position.\n";
        cout << "5. Delete from beginning.\n";
        cout << "6. Delete from End.\n";
        cout << "7. Delete from Any Position.\n";
        cout << "8. Search a Element on a Linked List.\n";
        cout << "9. Display Linked List.\n";
        cout << "10. Get Length of Linked List.\n";
        cout << "11. Exit.\n";
        cout<<"==================================================\n";
        int choice;
        cin >> choice;
        switch (choice) 
        {
            case 1:
                create();
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
