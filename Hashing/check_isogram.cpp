/*
Check if a string is Isogram or not

Given a string S of lowercase aplhabets, check if it is isogram or not. 
An Isogram is a string in which no letter occurs more than once.

Input:
The first line of input contains an integer T denoting the number of test cases. 
T testcases follow. Each test case consist of one string in 'lowercase' only, in a separate line.

Output:
For each testcase, in a new line, Print 1 if string is Isogram else print 0.

Constraints:
1 <= T <= 100
1 <= |S| <= 103

Example:
Input:
2
machine
geeks
Output:
1
0

Explanation:
Testcase 2: geeks is not an isogram as 'e' appears twice. Hence we print 0.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	map<char, int> mp;
	string str;
	
	cin >> t;
	while (t--) {
	    cin >> str;
	    for (int i = 0; str[i] != '\0'; i++) {
	        if (mp.find(str[i]) == mp.end()) {
	            mp.insert({str[i], 1});
	        }
	        else {
	            auto it = mp.find(str[i]);
	            (it->second)++;
	        }
	    }
	    
	    int flag = 1;
	    for (auto i = mp.begin(); i != mp.end(); i++) {
	        if (i->second > 1) {
	            flag = 0;
	            break;
	        }
	    }
	    if (flag) {
	        cout << '1';
	    }
	    else {
	        cout << '0';
	    }
	    cout << endl;
	    mp.clear();
	}
	return 0;
}