/*
Find median in a stream
Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by 
each insertion of X to the new stream.

Input:
The first line of input contains an integer N denoting the number of elements in the stream. Then the next N lines contains integer x 
denoting the number to be inserted into the stream.
Output:
For each element added to the stream print the floor of the new median in a new line.
 
Constraints:
1 <= N <= 106
1 <= x <= 106
 
Example:
Input:
4
5
15
1 
3
Output:
5
10
5
4
 
Explanation:
Testcase 1:
Flow in stream : 5, 15, 1, 3 
5 goes to stream --> median 5 (5) 
15 goes to stream --> median 10 (5, 15) 
1 goes to stream --> median 5 (5, 15, 1) 
3 goes to stream --> median 4 (5, 15, 1, 3) 
*/

#include <bits/stdc++.h>
using namespace std;

void find_median(int arr[], int n)
{
    priority_queue<int> s;
    
    priority_queue<int, vector<int>, greater<int>> g;
    
    int med = arr[0];
    s.push(arr[0]);
    
    cout << med << endl;
    
    for (int i = 1; i < n; i++ ) {
        int x = arr[i];
        
        if (s.size() > g.size()) {
            if (x < med) {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else {
                g.push(x);
            }
            
            med = (s.top() + g.top()) / 2;
        }
        else if (s.size() == g.size()) {
            if (x < med) {
                s.push(x);
                med = s.top();
            }
            else {
                g.push(x);
                med = g.top();
            }
        }
        
        else {
            if (x > med) {
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else{
                s.push(x);
            }
            
            med = (s.top() + g.top()) / 2;
        }
        
        cout << med << endl;
    }
    
}

int main() {
	//code
	int t;
	int n;
	
 	    cin >> n;
	    int arr[n];
	    
	    for (int i = 0; i < n; i++) {
	        cin >> arr[i];
	    }
	    
	    find_median(arr, n);

	return 0;
}