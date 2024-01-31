/*
Check if the given Linked List is Palindrome
Examples

Example 1:
Input Format:
LL: 1  2  3  2  1
Output: True
Explanation: A linked list with values “1 2 3 2 1” is a palindrome because its elements read the same from left to right and from right to left, making it symmetrical and mirroring itself.

Example 2:
Input Format:
LL: 1 2 3 3 2 1 
Output: True
Explanation: A linked list with values “1 2 3 3 2 1” is a palindrome because it reads the same forwards and backwards.

Example 3:
Input Format:
LL: 1 2 3 2 3
Output: False
Explanation: The linked list “1 2 3 2 3” is not a palindrome because it reads differently in reverse order, where “3 2 3 2 1” is not the same as the original sequence “1 2 3 2 3.”
*/

#include <iostream>
#include <stack>
#include <string>
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
    cout << "NULL" << endl;
}

//Linked List Creation Logic End

//Time Complexity: O(2 * N) This is because we traverse the linked list twice: once to push the values onto the stack, and once to pop the values and compare with the linked list. Both traversals take O(2*N) ~ O(N) time.
//Space Complexity: O(N) We use a stack to store the values of the linked list, and in the worst case, the stack will have all N values,  ie. storing the complete linked list. 
bool is_LinkedList_Palindrome_1(Node* head)
{
    stack<int> st;
    Node* temp = head;
    while(temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL)
    {
        if(st.top() != temp->data)
        {
            return false;
        }
        st.pop();
        temp = temp->next;
    }
    return true;
}

int main() 
{
    Node* head = nullptr; // Initialize the head of the linked list
    cout<<"Create a Linked List:"<<endl;
    head = createLinkedList(head);
    cout<<"Linked List After creation :"<<endl;
    displayLinkedList(head);
    string ans = is_LinkedList_Palindrome_1(head) ? "Yes, Linked List is Palindrome." : "No, Linked List Not a Palindrome." ;
    cout<<ans<<endl;
    return 0;
}