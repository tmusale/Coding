/*
Anagram

Given two strings a and b consisting of lowercase characters. The task is to check whether two given strings are anagram of 
each other or not. An anagram of a string is another string that contains same characters, only the order of characters can
 be different. For example, “act” and “tac” are anagram of each other.

Input: 
The first line of input contains an integer T denoting the number of test cases. Each test case consist of two strings in 
'lowercase' only, in a single line.

Output:
Print "YES" without quotes if the two strings are anagram else print "NO".

Constraints:
1 ≤ T ≤ 300
1 ≤ |s| ≤ 1016

Example:
Input:
2
geeksforgeeks forgeeksgeeks
allergy allergic

Output:
YES
NO

Explanation:
Testcase 1: Both the string have same characters with same frequency. So, both are anagrams.
Testcase 2: Characters in both the strings are not same, so they are not anagrams.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	string str1;
	string str2;
	cin >> t;
	
	while (t--) {
	    cin >> str1;
	    cin >> str2;
	    
	    unordered_set<char> s;
	    int arr[26] = {0};
	    
	    for (int i = 0; i < str1.length(); i++) {
	        //s.insert(str1[i]);
	        int temp = str1[i] - 'a';
	        arr[temp]++;
	    }
	    
	    int flag = 0;
	    for (int i = 0; str2[i] != '\0'; i++ ) {
	        int temp = str2[i] - 'a';
	        arr[temp]--;
	    }
	    
	    for (int i = 0; i < 26; i++) {
	        if (arr[i] != 0) {
	            flag = 1;
	        }
	    }
	    
	    if (flag) {
	        cout << "NO";
	    }
	    else {
	        cout << "YES";
	    }
	    cout << endl;
	}
	return 0;
}