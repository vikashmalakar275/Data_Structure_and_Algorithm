// C++ program to demonstrate default behaviour of
// sort() in STL.
#include <iostream>
using namespace std;

int main()
{
    string str;
    cout<<"Enter the string :"<<endl;
    cin>>str;
	sort(str.begin(), str.end());

	cout << "\nString after sorting\n";
    cout << str << " ";

	return 0;
}
