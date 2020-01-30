/*
Palindrome String
Given a string S, check if it is palindrome or not.

Input:
The first line contains 'T' denoting the number of test cases. 
T testcases follow. Each testcase contains two lines of input. 
The first line contains the length of the string and the second line contains the string S.

Output:
For each testcase, in a new line, print "Yes" if it is a palindrome else "No". (Without the double quotes)

Constraints:
1 <= T <= 30
1 <= N <= 100

Example:
Input:
1
4
abba
Output:
Yes
*/

#include <bits/stdc++.h>
using namespace std;

bool check_palindrome(string str, int n)
{
    int i = 0;
    int j = n-1;
    
    while (i <= j) {
        if (str[i] != str[j]) {
            return false;
        }
        i++;
        j--;
    }
    
    return true;
}

int main() {
	//code
	int t;
	int n;
	string str;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    cin >> str;
	    
	    if (check_palindrome(str, n)) {
	        cout << "Yes";
	    }
	    else {
	        cout << "No";
	    }
	    cout << endl;
	}
	return 0;
}