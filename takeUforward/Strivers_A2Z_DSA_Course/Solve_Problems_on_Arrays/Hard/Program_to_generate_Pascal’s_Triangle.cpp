/*
Problem Statement: This problem has 3 variations. They are stated below:

Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.

Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.

Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.

In Pascal’s triangle, each number is the sum of the two numbers directly above it as shown in the figure below:


Examples
Example 1:
Input Format: N = 5, r = 5, c = 3
Result: 6 (for variation 1)
1 4 6 4 1 (for variation 2)

1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1    (for variation 3)

Explanation: There are 5 rows in the output matrix. Each row is formed using the logic of Pascal’s triangle.

Example 2:
Input Format: N = 1, r = 1, c = 1
Result: 1 (for variation 1)
    1 (for variation 2)
    1  (for variation 3)
Explanation: The output matrix has only 1 row.
*/


#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int pascalTriangle(int r, int c) {
    int element = nCr(r - 1, c - 1);
    return element;
}

int main()
{
    int r = 5; // row number
    int c = 3; // col number
    int element = pascalTriangle(r, c);
    cout << "The element at position (r,c) is: "
            << element << "n";
    return 0;
}
        