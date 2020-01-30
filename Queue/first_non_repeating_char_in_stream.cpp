/*
First non-repeating character in a stream
Given an input stream of N characters consisting only of lower case alphabets. The task is to find the first non repeating character, 
each time a character is inserted to the stream. If no non repeating element is found print -1.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer 
N denoting the size of the stream. Then in the next line are x characters which are inserted to the stream.

Output:
For each test case in a new line print the first non repeating elements separated by spaces present in the stream at every instinct when 
a character is added to the stream, if no such element is present print -1.

Constraints:
1 <= T <= 200
1 <= N <= 500

Example:
Input:
2
4
a a b c
3
a a c

Output:
a -1 b b
a -1 c
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	int n;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    char str[n];
	    unordered_map<char, int> hash;
	    queue<char> q;
	    
	    for (int i = 0; i < n; i++) {
	        cin >> str[i];
	        
	        hash[str[i]]++;
	        //if (q.emp)
	        if (hash[str[i]] == 1) {
	            q.push(str[i]);
	        }
	        if (hash[q.front()] == 1) {
	            cout << q.front() << " ";
	        }
	        else {
	            while (!q.empty() && hash[q.front()] > 1) {
	                q.pop();
	            }
	            if (!q.empty()) {
	                cout << q.front() << " ";
	            }
	            else {
	                cout << -1 << " ";
	            }
	        }
	    }
	    
	    cout << endl;
	}
	return 0;
}