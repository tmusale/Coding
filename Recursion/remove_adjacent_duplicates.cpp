/*
Recursively remove all adjacent duplicates

Given a string s, recursively remove adjacent duplicate characters from the string s. 
The output string should not have any adjacent duplicates.
 

Input:
The first line of input contains an integer T, denoting the no of test cases. 
Then T test cases follow. Each test case contains a string str.

Output:
For each test case, print a new line containing the resulting string.

Constraints:
1<=T<=100
1<=Length of string<=50

Example:
Input:
2
geeksforgeek
acaaabbbacdddd

Output:
gksforgk
acac
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char * remove_duplicate(char *str, int len)
{
    int k = 0;
    int i;
    for (i = 1; i < len; i++) {
        if (str[i-1] != str[i]) {
            str[k++] = str[i-1];
        }
        else {
            while (str[i-1] == str[i]) {
                i++;
            }
        }
    }
    
    str[k++] = str[i-1];
    str[k] = '\0';
    if (k != len) {
        return remove_duplicate(str, k);
    }
    
    return str;
}

int main() {
	//code
	int t;
	
	cin >> t;
	while (t--) {
	    char str[50];
	    cin >> str;
	    
	    int len = strlen(str);
	    cout << remove_duplicate(str, len) << endl;
	}
	return 0;
}