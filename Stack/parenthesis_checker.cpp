/*
Parenthesis Checker

Given an expression string exp. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp = “[(])”

Input:
The first line of input contains an integer T denoting the number of test cases.  Each test case consists of a string of expression, 
in a separate line.

Output:
Print 'balanced' without quotes if the pair of parenthesis is balanced else print 'not balanced' in a separate line.

Constraints:
1 ≤ T ≤ 100
1 ≤ |s| ≤ 105

Example:
Input:
3
{([])}
()
([]

Output:
balanced
balanced
not balanced
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
	    stack<char> st;
	    int flag = 1;
	    
	    for (int i = 0; str[i] != '\0'; i++) {
	        if (str[i] == '{' || str[i] == '(' || str[i] == '[') {
	            st.push(str[i]);
	        }
	        else if (str[i] == '}' || str[i] == ')' || str[i] == ']')
	        {
	            if (st.empty()) {
	                flag = 0;
	                break;
	            }
	            else 
	                st.pop();
	        }
	    }
	    
	    if (!st.empty() || flag == 0) {
	        cout << "not balanced";
	    }
	    else {
	        cout << "balanced";
	    }
	    cout << endl;
	}
	return 0;
}