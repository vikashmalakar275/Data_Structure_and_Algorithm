/*
You’re given a linked list. The last node might point to null, or it might point to a node in the list, thus forming a cycle.

Find out whether the linked list has a cycle or not, and the length of the cycle if it does.

If there is no cycle, return 0, otherwise return the length of the cycle.

Example:
Input: Linked List: 4 -> 10 -> 3 -> 5 -> 10(at position 2)

Output: Length of cycle = 3

Explanation: The cycle is 10, 3, 5.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
4
4 10 3 5
2
Sample Output 1:
3
Explanation Of Sample Input 1 :
The cycle is 10, 3, 5.
Sample Input 2 :
4
4 10 3 5
0
Sample Output 2 :
0
Explanation Of Sample Input 2 :
Since ‘p’ = 0, the last node is pointing to null, so no cycle exists.


Constraints:
1 <= ‘n’ <= 100000
1 <= Data in linked list node <= 10^9
0 <= ‘p’ <= ‘n’
*/

#include <iostream>
#include <map>
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

//Time Complexity = O(N*logN)
//Space Complexity = O(N)
int length_of_loop_1(Node* head)
{
    map<Node*,int> mpp;
    Node* temp = head;
    int timer = 1;
    while(temp != NULL)
    {
        if(mpp.find(temp) != mpp.end())
        {
            int value = mpp[temp];
            return timer - value;
        }
        mpp[temp] = timer;
        timer++;
        temp = temp->next;
    }
    return 0;
}


int length_of_loop_2(Node* head) 
{
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            int count = 1;
            fast = fast->next;
            while(slow != fast)
            {
                count++;
                fast = fast->next;
            }
            return count;
        }
    }
    return 0;
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

    cout<<"Length of Loop = "<<length_of_loop_1(head)<<endl;
    cout<<"Length of Loop = "<<length_of_loop_2(head)<<endl;

    return 0;
}