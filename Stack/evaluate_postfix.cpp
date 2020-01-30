/*
Evaluation of Postfix Expression

Given a postfix expression, the task is to evaluate the expression and print the final value. 
Operators will only include the basic arithmetic operators like *,/,+ and - . 

Input:
The first line of input will contains an integer T denoting the no of test cases . 
Then T test cases follow. Each test case contains an postfix expression.

Output:
For each test case, in a new line, evaluate the postfix expression and print the value.

Constraints:
1 <= T <= 100
1 <= length of expression <= 100

Example:
Input:
2
231*+9-
123+*8-
Output:
-4
-3
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	string str;
	stack<int> st;
	
	cin >> t;
	while (t--) {
	    cin >> str;
	    
	    for (int i = 0; str[i] != '\0'; i++) {
	        if (str[i] == '+') {
	            int second = st.top();
	            st.pop();
	            int first = st.top();
	            st.pop();
	            st.push(first+second);
	        }
	        else if (str[i] == '-') {
	            int second = st.top();
	            st.pop();
	            int first = st.top();
	            st.pop();
	            st.push(first-second);
	        }
	        else if (str[i] == '*') {
	            int second = st.top();
	            st.pop();
	            int first = st.top();
	            st.pop();
	            st.push(first*second);
	        }
	        else if (str[i] == '/') {
	            int second = st.top();
	            st.pop();
	            int first = st.top();
	            st.pop();
	            st.push(first/second);
	        }
	        else {
	            int temp = str[i] - '0';
	            st.push(temp);
	        }
	    }
	    
	    cout << st.top() << endl;
	    st.pop();
	    //st.clear();
	    //v.clear();
	}
	return 0;
}