/*
Problem Statement: Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all the books to the students.
Allocate books in such a way that:

Each student gets at least one book.
Each book should be allocated to only one student.
Book allocation should be in a contiguous manner.
You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1

Examples
Example 1:
Input Format: n = 4, m = 2, arr[] = {12, 34, 67, 90}
Result: 113
Explanation: The allocation of books will be 12, 34, 67 | 90. One student will get the first 3 books and the other will get the last one.

Example 2:
Input Format: n = 5, m = 4, arr[] = {25, 46, 28, 49, 24}
Result: 71
Explanation: The allocation of books will be 25, 46 | 28 | 49 | 24.

We can allocate books in several ways but it is clearly said in the question that we have to allocate the books in such a way that the maximum number of pages received by a student should be minimum.


Assume the given array is {25 46 28 49 24} and number of students, M = 4. Now, we can allocate these books in different ways. Some of them are the following:


25 | 46 | 28 | 49, 24  → Maximum no. of pages a student receive = 73
25 | 46 | 28, 49 | 24  → Maximum no. of pages a student receive = 77
25 | 46, 28 | 49 | 24  → Maximum no. of pages a student receive = 74
25, 46 | 28 | 49 | 24  → Maximum no. of pages a student receive = 71

From the above allocations, we can clearly observe that the minimum possible maximum number of pages is 71.


When it is impossible to allocate books:


When the number of books is lesser than the number of students, we cannot allocate books to all the students even if we give only a single book to each student. So, if m > n, we should return -1.


Observations:


Minimum possible answer: We will get the minimum answer when we give n books of the array to n students(i.e. Each student will receive 1 book). Now, in this case, the maximum number of pages will be the maximum element in the array. So, the minimum possible answer is max(arr[]).
Maximum possible answer: We will get the maximum answer when we give all n books to a single student. The maximum no. of pages he/she will receive is the summation of array elements i.e. sum(arr[]). So, the maximum possible answer is sum(arr[]).

From the observations, it is clear that our answer lies in the range [max(arr[]), sum(arr[])].


How to calculate the number of students to whom we can allocate the books if one can receive at most ‘pages’ number of pages:


In order to calculate the number of students we will write a function, countStudents(). This function will take the array and ‘pages’ as parameters and return the number of students to whom we can allocate the books.


countStudents(arr[], pages):


1. We will first declare two variables i.e. ‘students’(stores the no. of students), and pagesStudent(stores the number of pages of a student). As we are starting with the first student, ‘students’ should be initialized with 1.
2. We will start traversing the given array.
3. If pagesStudent + arr[i] <= pages: If upon adding the pages with the existing number of pages does not exceed the limit, we can allocate this i-th book to the current student.
4. Otherwise, we will move to the next student(i.e. students += 1 ) and allocate the book.

Finally, we will return the value of ‘students’.
*/
#include <iostream>
#include <numeric>
using namespace std;

int countStudent(vector<int> book,int page)
{
    int student = 1;
    int pagesOfStudent = 0;
    for(int i=0;i<book.size();i++)
    {
        if(pagesOfStudent + book[i]<=page)
        {
            pagesOfStudent += book[i];
        }
        else
        {
            student++;
            pagesOfStudent = book[i];
        }
    }
    return student;
}

//Time Complexity: O(N * (sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
//Reason: We are using a loop from max(arr[]) to sum(arr[]) to check all possible numbers of pages. Inside the loop, we are calling the countStudents() function for each number. Now, inside the countStudents() function, we are using a loop that runs for N times.
//Space Complexity:  O(1) as we are not using any extra space to solve this problem.
int allocateMinimumNumberOfPages_1(vector<int> book,int student)
{
    int maxi = *max_element(book.begin(),book.end());
    int sum = accumulate(book.begin(),book.end(),0);
    for(int page=maxi;page<=sum;page++)
    {
        int count_student = countStudent(book,page);
        if(count_student==student)
        {
            return page;
        }
    }
    return -1;
}

//Time Complexity: O(N * log(sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
//Reason: We are applying binary search on [max(arr[]), sum(arr[])]. Inside the loop, we are calling the countStudents() function for the value of ‘mid’. Now, inside the countStudents() function, we are using a loop that runs for N times.
//Space Complexity:  O(1) as we are not using any extra space to solve this problem.
int allocateMinimumNumberOfPages_2(vector<int> book,int student)
{
    if(student>book.size())
    {
        return -1;
    }
    int low = *max_element(book.begin(),book.end());
    int high = accumulate(book.begin(),book.end(),0);
    while(low<=high)
    {
        int mid = (low+high)/2;
        int count_student = countStudent(book,mid);
        if(count_student > student)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    int n;
    cout<<"Enter the Size of Array :"<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the element of Array :"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    int student;
    cout<<"Enter the Number of Student :"<<endl;
    cin>>student;
    cout<<"maximum number of pages assigned to a student is minimum = "<<allocateMinimumNumberOfPages_1(arr,student)<<endl;
    cout<<"maximum number of pages assigned to a student is minimum = "<<allocateMinimumNumberOfPages_2(arr,student)<<endl;
}