#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

mutex mtx;

int num = 0;
int max_count = 20;
void even()
{
    while(num<=max_count)
    {
        if(num%2 == 0)
        {
            unique_lock<mutex> lock(mtx);
            cout<<"odd :"<<num<<endl;
            num++;
        }
    }
}

void odd()
{
    while(num<=max_count)
    {
        if(num%2 == 1)
        {
            unique_lock<mutex> lock(mtx);
            cout<<"even :"<<num<<endl;
            num++;
        }
    }
}

int main()
{
    thread even_thread(even);
    thread odd_thread(odd);

    even_thread.join();
    odd_thread.join();
    return 0;
}