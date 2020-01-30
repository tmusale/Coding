/*
Print Bracket Number

Given an expression exp of length n consisting of some brackets. The task is to print the bracket numbers when the expression is being parsed.

Input:
The first line contains an integer T, the number of test cases. For each test case, there is a string exp containing the expression.

Output:
For each test case, the output is the bracket numbers of the expression.

Constraints:
1<=T<=100
1<=S<=100

Example:
Input:
3​
(a+(b*c))+(d/e)​
((())(()))
((((()
Output:
1 2 2 1 3 3
1 2 3 3 2 4 5 5 4 1
1 2 3 4 5 5

Explanation:
Test case 1:The highlighted brackets in the given expression (a+(b*c))+(d/e) has been assigned the numbers as: 1 2 2 1 3 3.
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
	    int count = 0;
	    
	    for (int i = 0; str[i] != '\0'; i++) {
	        if (str[i] == '(') {
	            count++;
	            st.push(count);
	            cout << count << " ";
	        }
	        else if (str[i] == ')') {
	            cout << st.top() << " ";
	            st.pop();
	        } 
	    }
	    
	    if (!st.empty()) {
	        st.pop();
	    }
	    
	    cout << endl;
	}
	
	return 0;
}