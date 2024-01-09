/*
Problem statement
You are given a 0-indexed 2-D grid ‘g’ of size ‘n’ X ‘m’, where each cell contains a positive integer, and adjacent cells are distinct.



You need to find the location of a peak element in it. If there are multiple answers, find any of them.



A peak element is a cell with a value strictly greater than all its adjacent cells.



Assume the grid to be surrounded by a perimeter of ‘-1s’.



You must write an algorithm that works in O(n * log(m)) or O(m * log(n)) complexity.



Note:

In the output, you will see '0' or '1', where '0' means your answer is wrong, and '1' means your answer is correct.


Example:

Input: 'n' = 2, 'm' = 2
'g' = [[8, 6], [10, 1]]

Output: 1

Sample Explanation: Only one peak element is present at [1, 0].

Sample Input 1:
2 2
8 6
10 1
Sample Output 1:
1       
Explanation of sample output 1:
For g = [[8,6],[10,1]],
Answer = [1,0].
There is only one peak element that is present at [1,0].
Sample Input 2:
3 3
1 2 3
4 5 6
7 8 9   
Sample Output 2:
1
Explanation of sample output 2:
For g = [[1, 2, 3], [4, 5, 6], [7, 8, 9]],
Answer = [2,2].
There is only one peak element that is present at [2,2].
Constraints:
1 <= n, m <= 500    
1 <= g[i][j] <= 10^9    
Adjacent cells are distinct.
Time Limit: 1 sec
*/
#include <iostream>
using namespace std;

//Time Complexity: O(rows * columns) 
//Auxiliary Space: O(1)
pair<int,int> search_peak_1(vector<vector<int> > &arr)
{
    int row = arr.size();
    int column = arr[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++) 
        {
            if (i > 0)
            {
                if (arr[i][j] < arr[i - 1][j])
                {
                    continue;
                }
            }
            if (j < column - 1)
            {
                if (arr[i][j] < arr[i][j + 1])
                {
                    continue;
                }
            }
            if (i < row - 1)
            {
                if (arr[i][j] < arr[i + 1][j])
                {
                    continue;
                }
            }
            if (j > 0)
            {
                if (arr[i][j] < arr[i][j - 1])
                {
                    continue;
                }
            }
            return make_pair(i,j);
        }
    }
    return make_pair(-1,-1);
}

//Time Complexity: O(rows * log(columns)). We recur for half the number of columns. In every recursive call, we linearly search for the maximum in the current mid column.
//Auxiliary Space: O(columns/2) for Recursion Call Stack 
pair<int,int> search_peak_2(vector<vector<int> > &arr)
{
    int low = 0;
    int high = arr[0].size() - 1;
 
    while (low <= high)
    {
        int mid = (low + high)/2;
        int ansrow = 0;
        for (int r = 0; r < arr.size(); r++)
        {
            ansrow = arr[r][mid] >= arr[ansrow][mid] ? r : ansrow;
        }
        bool valid_left = mid - 1 >= low && arr[ansrow][mid - 1] > arr[ansrow][mid];
        bool valid_right = mid + 1 <= high && arr[ansrow][mid + 1] > arr[ansrow][mid];
        if (!valid_left && !valid_right)
        {
            return make_pair(ansrow, mid);
        }
        else if(valid_right)
        {
            low = mid+ 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return make_pair(-1,-1);
}

int main()
{
    int n,m;
    cout<<"Enter the number of Row :"<<endl;
    cin>>n;
    cout<<"Enter the number of Column :"<<endl;
    cin>>m;
    vector<vector<int> > arr(n);
    cout<<"Enter the Value in Array :"<<endl;
    for(int i=0;i<n;i++)
    {
        arr[i].resize(m);
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    pair<int,int> ans = search_peak_1(arr);
    cout<<"Peak Element found at index = ("<<ans.first<<" , "<<ans.second<<")"<<endl;
    pair<int,int> ans1 = search_peak_2(arr);
    cout<<"Peak Element found at index = ("<<ans1.first<<" , "<<ans1.second<<")"<<endl;
    return 0;
}