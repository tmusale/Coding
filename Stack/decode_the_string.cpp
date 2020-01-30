/*
Decode the string
An encoded string (s) is given, the task is to decode it. The pattern in which the strings were encoded were as follows
original string: abbbababbbababbbab 
encoded string : "3[a3[b]1[ab]]".

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains a string s.

Output:
For each test case in a new line print the required decoded string.

Constraints:
1<=T<=10
1<=length of the string <=30

Example:
Input:
2
1[b]
3[b2[ca]]

Output:
b
bcacabcacabcaca
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	string str;
	
	cin >> t;
	while (t--) {
	    cin >> str;
	    
	    stack<int> intst;
	    stack<char> charst;
	    
	    for (int i = 0; str[i] != '\0'; i++) {
	        if (str[i] >= '0' && str[i] <= '9') {
	            if (str[i+1] >= '0' && str[i+1] <= '9') {
	                 int first = str[i] - '0';
	                 int second = str[i+1] - '0';
	                 first = first * 10;
	                 second = second + first;
	                 //cout
	                 intst.push(second);
	                 //cout << intst.top() << endl;
	                 i++;
	            }
	            else {
	                intst.push(str[i] - '0');
	            }
	            
	        }
	        else if (str[i] == ']') {
	            string sub = "";
	            while (charst.top() != '[') {
	                sub = sub + charst.top();
	                charst.pop();
	            }
	            charst.pop();
	            
	            //cout << intst.top() << endl;
	            int count = intst.top();
	            intst.pop();
	            //cout << count << endl;
	            string res = "";
	            while (count--) {
	                res = res + sub;
	            }
	            
	            for (auto i = res.rbegin(); i != res.rend(); i++) {
	                charst.push(*i);
	            }
	        }
	        else {
	            charst.push(str[i]);
	        }
	    }
	    
	    string op = "";
	    while (!charst.empty()) {
	        //cout << charst.top();
	        op = charst.top() + op;
	        charst.pop();
	    }
	    cout << op << endl;
	}
	return 0;
}