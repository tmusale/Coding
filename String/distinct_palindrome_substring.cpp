/*
Distinct palindromic substrings

Given a string of lowercase ASCII characters, find all distinct continuous palindromic sub-strings of it.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. Each test case contains a string.

Output:
Print the count of distinct continuous palindromic sub-strings of it.

Constraints:
1<=T<=10^5
1<=length of string<=10^5

Example:
Input:
2
abaaa
geek

Output:
5
4
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check_palindrome(string str, int i, int j)
{
    while (i <= j) {
        if (str[i] != str[j]){
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
	string str;
	
	cin >> t;
	while (t--) {
	    cin >> str;
	    int count = 0;
	    unordered_set<string> s;
	    //string temp;
	    
	    for (int i = 0; i < str.length(); i++) {
	        for (int j = i; j < str.length(); j++) {
	            if (check_palindrome(str, i, j)) {
	                int len = j - i + 1;
	                string temp;
	                //str.copy(temp, len, i);
	                int l = 0;
	                for (int k = i; k < i+len; k++) {
	                    temp.push_back(str[k]);
	                    //l++;
	                }
	                //count++;
	                if (s.find(temp) == s.end()) {
	                    s.insert(temp);
	                    //cout << temp <<" ";
	                }
	                
	            }
	        }
	    }
	    count = s.size();
	    //for (auto i = s.begin(); i != s.end(); i++) {
	        //cout << *i << " ";
	    //}
	    //cout << endl;
	    cout << count << endl;
	}
	return 0;
}