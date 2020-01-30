/*
Longest Palindrome in a String

Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). 
Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, 
return the substring which occurs first ( with the least starting index ).

NOTE: Required Time Complexity O(n2).

Input:
The first line of input consists number of the testcases. The following T lines consist of a string each.

Output:
In each separate line print the longest palindrome of the string given in the respective test case.

Constraints:
1 ≤ T ≤ 100
1 ≤ Str Length ≤ 104

Example:
Input:
1
aaaabbaa

Output:
aabbaa

Explanation:
Testcase 1: The longest palindrome string present in the given string is "aabbaa".
*/

#include <bits/stdc++.h>
using namespace std;

bool check_palindrome(string str, int start, int end)
{
    while (start <= end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    
    return true;
}

int main() {
	//code
	int t;
	string str;
	
	cin >> t;
	while (t--) {
	    cin >> str;
	    
	    int start = -1;
	    int end = -1;
	    int cur_len;
	    int max_len = -1;
	    
	    for (int i = 0; i < str.length(); i++) {
	        for (int j = i+1; j < str.length(); j++) {
	            //start = i;
	            //end = j;
	            if (check_palindrome(str, i, j)) {
	                cur_len = j - i + 1;
	                if (max_len < cur_len) {
	                    max_len = cur_len;
	                    start = i;
	                    end = j;
	                }
	            }
	        }
	    }
	    //cout << start << endl;
	    //cout << end << endl;
	    //cout << max_len << endl;
	    if (max_len == -1) {
	        cout << str[0];
	    }
	    else {
	        for (int k = start; k <= end; k++) {
	            cout << str[k];
	        }
	    }
	    cout << endl;
	}
	return 0;
}