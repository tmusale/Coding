/*
Binary String
Given a binary string S. The task is to count the number of substrings that start and end with 1. 
For example, if the input string is “00100101”, then there are three substrings “1001”, “100101” and “101”.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Each test case consist of an integer 'N' denoting the string length and next line is followed by a binary string.

Output:
For each testcase, in a new line, print the number of substring starting and ending with 1 in a separate line.

Constraints:
1 ≤ T ≤ 100
1 ≤ |S| ≤ 104

Example:
Input:
2
4
1111
5
01101

Output:
6
3

Example:
Testcase 1: There are 6 substrings from the given string. They are 11, 11, 11, 111, 111, 1111.
Testcase 2: There 3 substrings from the given string. They are 11, 101, 1101.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int cal_substring(string str, int n)
{
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (str[i] == '1') {
            count++;
        }
    }
    
    count--;
    
    int res = count * (count+1);
    
    return (res/2);
}

int main() {
	//code
	int t;
	int n;
	string str;
	
	cin >> t;
	while(t--) {
	    cin >> n;
	    cin >> str;
	    
	    int count = cal_substring(str, n);
	    cout << count << endl;
	}
	return 0;
}