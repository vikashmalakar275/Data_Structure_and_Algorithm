// C++ program to demonstrate default behaviour of
// sort() in STL.
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of array :"<<endl;
    cin>>n;
	int arr[n];
    cout<<"Enter the element of array :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
	sort(arr, arr + n);

	cout << "\nArray after sorting using "
			"default sort is : \n";
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";

	return 0;
}
