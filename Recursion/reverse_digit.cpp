/*
Reverse digits

Write a program to reverse digits of a number N.

Input:
The first line of input contains an integer T, denoting the number of test cases. 
T testcases follow. Each test case contains an integer N.

Output:
For each test case, print the reverse digits of number N .

Constraints:
1 ≤ T ≤ 104
1 ≤ N ≤ 1015

Example:
Input:
2
200
122
Output:
2
221
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void reverse_digit(long long int n, bool flag)
{
    if (n > 0) {
        int temp = n % 10;
        if (temp == 0 && flag) {
            //cout << temp;
            reverse_digit(n/10, true);
        }
        else {
            cout << temp;
            reverse_digit(n/10, false);
        }
    }
}

int main() {
	//code
	int t;
	long long int n;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    reverse_digit(n, true);
	    cout << endl;
	}
	return 0;
}