#include <iostream>
using namespace std;



// 1 -> 2 -> 3 ->4;

struct node
{
    int data;
    node* Next;
};

void reverseLinkedList(node* Head)
{
    node* temp = Head;
    node* prev = Head->Next->Next;
    while(Head->Next != NULL)
    {
        Head->Next->Next = Head->Next;
        free(temp);
    }
}

int main()
{
    int n;
    cout<<"Enter the size of linkedlist :"<<endl;
    cin>>n;
    node* ll;
    node* head = ll;
    while(n>0)
    {
        int a;
        cin>>a;
        ll->data = a;
        ll->Next=NULL;
    }
    reverseLinkedList(head);
}