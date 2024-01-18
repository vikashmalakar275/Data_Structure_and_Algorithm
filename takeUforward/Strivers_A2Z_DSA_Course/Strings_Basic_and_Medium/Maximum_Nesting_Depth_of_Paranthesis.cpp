/*
We are given a string having parenthesis like below 
     “( ((X)) (((Y))) )” 
We need to find the maximum depth of balanced parenthesis, like 4 in the above example. Since ‘Y’ is surrounded by 4 balanced parentheses. 
If parenthesis is unbalanced then return -1. 

Examples : 

Input : S = "( a(b) (c) (d(e(f)g)h) I (j(k)l)m)";
Output : 4

Input : S = "( p((q)) ((s)t) )";
Output : 3

Input : S = "";
Output : 0

Input : S = "b) (c) ()";
Output : -1 

Input : S = "(b) ((c) ()"
Output : -1 
*/
#include <iostream>
#include <stack>
using namespace std;

//Method - 1
//Time Complexity: O(N) where n is number of elements in given string. As, we are using a loop to traverse N times so it will cost us O(N) time 
//Auxiliary Space: O(N), as we are using extra space for stack.
int maximum_nesting_depth_1(string str)
{
    int count = 0;
    stack<int> st;

    for(int i=0;i<str.size();i++)
    {
        if(str[i] == '(')
        {
            st.push(i);
        }
        else if(str[i] == ')')
        {
            if(count < st.size())
            {
                count = st.size();
            }
            st.pop();
        }
    }
    return count;
}

//Method - 2
//Time Complexity: O(n) where n is number of elements in given string. As, we are using a loop to traverse N times so it will cost us O(N) time.
//Auxiliary Space: O(1), as we are not using any extra space.
int maximum_nesting_depth_2(string str)
{
    int current_max = 0;
    int max = 0;
    int n = str.length();
    for(int i=0;i<n;i++)
    {
        if(str[i] == '(')
        {
            current_max++;
            if(current_max > max)
            {
                max = current_max;
            }
        }
        else if (str[i] == ')')
        {
            if(current_max >0)
            {
                current_max--;
            }
            else
            {
                return -1;
            }
        }
    }
    if(current_max != 0)
    {
        return -1;
    }
    return max;
}

int main()
{
    string str;
    cout<<"Enter the string :"<<endl;
    getline(cin,str);
    cout<<"Maximum Nesting Depth of Parenthesis = "<<maximum_nesting_depth_1(str)<<endl;
    cout<<"Maximum Nesting Depth of Parenthesis = "<<maximum_nesting_depth_2(str)<<endl;
}