/*
Problem Statement: Problem Statement: Given the head of a singly linked list, write a program to reverse the linked list, 
and return the head pointer to the reversed list.

Examples
Example 1:
Input Format:
LL: 1   3   2   4 
Output: 4 2 3 1
Explanation: After reversing the linked list, the new head will point to the tail of the old linked list.

Example 2:
Input Format:
LL: 4
Output: 4
Explanation: In this example, the linked list contains only one node hence reversing this linked list will result in the same list as the original.
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

//Time Complexity: O(2N) This is because we traverse the linked list twice: once to push the values onto the stack, and once to pop the values and update the linked list. Both traversals take O(N) time, hence time complexity  O(2N) ~ O(N).
//Space Complexity: O(N) We use a stack to store the values of the linked list, and in the worst case, the stack will have all N values,  ie. storing the complete linked list. 
Node *reverseLinkedList(Node* head)
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
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

//Time Complexity: O(N) The code traverses the entire linked list once, where ‘n’ is the number of nodes in the list. This traversal has a linear time complexity, O(n).
//Space Complexity: O(1) The code uses only a constant amount of additional space, regardless of the linked list’s length. This is achieved by using three pointers (prev, temp and front) to reverse the list without any significant extra memory usage, resulting in constant space complexity, O(1).
Node *reverseLinkedList_1(Node* head)
{
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL)
    {
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

//Time Complexity: O(N) This is because we traverse the linked list twice: once to push the values onto the stack, and once to pop the values and update the linked list. Both traversals take O(N) time.
//Space Complexity : O(1) No additional space is used explicitly for data structures or allocations during the linked list reversal process. However, it’s important to note that there is an implicit use of stack space due to recursion. This recursive stack space stores function calls and associated variables during the recursive traversal and reversal of the linked list. Despite this, no extra memory beyond the program’s existing execution space is allocated, hence maintaining a space complexity of O(1).
Node *reverseLinkedList_3(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    Node* newHead = reverseLinkedList_3(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

int main() 
{
    Node* head = nullptr; // Initialize the head of the linked list
    cout<<"Create a Linked List:"<<endl;
    head = createLinkedList(head);
    cout<<"Linked List After creation :"<<endl;
    displayLinkedList(head);

    cout<<"Calling function to Reverse Linked List :"<<endl;
    Node* reverseHead = nullptr;
    reverseHead = reverseLinkedList(head);
    cout<<"Printing Reverse linked list :"<<endl;
    displayLinkedList(reverseHead);

    cout<<"Calling function to Reverse Linked List :"<<endl;
    Node* reverseHead1 = nullptr;
    reverseHead1 = reverseLinkedList_1(head);
    cout<<"Printing Reverse linked list :"<<endl;
    displayLinkedList(reverseHead1);

    cout<<"Calling function to Reverse Linked List :"<<endl;
    Node* reverseHead2 = nullptr;
    reverseHead2 = reverseLinkedList_1(head);
    cout<<"Printing Reverse linked list :"<<endl;
    displayLinkedList(reverseHead2);

    return 0;
}
