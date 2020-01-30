/*
Stock buy and sell

The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell 
the stock so that in between those days your profit is maximum.

Input: 
First line contains number of test cases T. First line of each test case contains an integer value N denoting 
the number of days, followed by an array of stock prices of N days. 

Output:
For each testcase, output all the days with profit in a single line. And if there is no profit then print "No Profit".

Constraints:
1 <= T <= 100
2 <= N <= 103
0 <= Ai <= 104

Example
Input:
2
7
100 180 260 310 40 535 695
10
23 13 25 29 33 19 34 45 65 67

Output:
(0 3) (4 6)
(1 4) (5 9)

Explanation:
Testcase 1: We can buy stock on day 0, and sell it on 3rd day, which will give us maximum profit.
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
	    int arr[n];
	    
	    for (int i = 0; i < n; i++) {
	        cin >> arr[i];
	    }
	    
	    int start = 0;
	    int end = -1;
	    int flag = 0;
	    
	    for (int i = 1; i < n; i++) {
	        if (arr[i] < arr[i-1]) {
	            end = i-1;
	            if (start != end) {
	                cout << "(" << start << " ";
	                cout << end << ") ";
	                flag = 1;
	            }
	            start = i;
	        }
	    }
	    
	    if (arr[n-1] > arr[n-2]) {
	        end = n-1;
	        if (start != end) {
	            cout << "(" << start << " ";
	            cout << end << ") ";
	            flag = 1;
	        }
	    }
	    
	    if (flag == 0) {
	        cout << "No Profit";
	    }
	    
	    cout << endl;
	}
	return 0;
}