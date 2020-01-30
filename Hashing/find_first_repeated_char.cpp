/*
Find first repeated character

Given a string S. The task is to find the first repeated character in it. We need to find the character that occurs more than once and 
whose index of first occurrence is smallest. S contains only lowercase letters.
Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains a string S.

Output:
For each test case in a new line print the first repeating character in the string. If no such character exist print -1.

Constraints:
1 <= T <= 100
1 <= |S| <=104

Example:
Input:
2
geeksforgeeks
hellogeeks

Output:
e
l
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	string str;
	
	cin >> t;
	while (t--) {
	    cin >> str;
	    
	    unordered_map<int, int> hash;
	    char res;
	    int flag = 0;
	    
	    for (int i = 0; str[i] != '\0'; i++) {
	        hash[str[i]]++;
	        if (hash[str[i]] > 1) {
	            res = str[i];
	            flag = 1;
	            break;
	        }
	    }
	    
	    
	    
	    
	    if (flag) {
	        cout << res << endl;
	    }
	    else{
	        cout << -1 << endl;
	    }
	}
	return 0;
}