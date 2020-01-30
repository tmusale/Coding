/*
Find all pairs with a given sum

Given two unsorted arrays A of size N and B of size M of distinct elements, the task is to find all pairs from both arrays whose sum is 
equal to X.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains 3 lines . 
The first line contains 3 space separated integers N, M, X. Then in the next two lines are space separated values of the array A and B 
respectively.

Output:
For each test case in a new line print the sorted space separated values of all the pairs u,v where u belongs to array A and v belongs 
to array B, such that each pair is separated from the other by a ',' without quotes also add a space after the ',' . If no such pair 
exist print -1.

Constraints:
1 <= T <= 100
1 <= N, M, X <= 106
-106 <= A, B <= 106

Example:
Input:
2
5 5 9
1 2 4 5 7
5 6 3 4 8
2 2 3
0 2
1 3
Output:
1 8, 4 5, 5 4
0 3, 2 1

Explanation:
Testcase 1: (1, 8), (4, 5), (5, 4) are the pairs which sum to 9.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	int n;
	int m;
	int x;
	
	cin >> t;
	while (t--) {
	    cin >> n >> m >> x;
	    int A[n];
	    int B[m];
	    
	    for (int i = 0; i < n; i++) {
	        cin >> A[i];
	    }
	    for (int j = 0; j < m; j++) {
	        cin >> B[j];
	    }
	    
	    int i = 0;
	    int j = 0;
	    
	    sort(A, A+n);
	    sort(B, B+m, greater<int>());
	    
	    int flag = 0;
	    int count = 0;
	    while (i < n && j < m) {
	        if (A[i] + B[j] == x) {
	            if (flag) {
	                cout << ", ";
	            }
	            cout << A[i] << " ";
	            cout << B[j];
	            i++;
	            flag = 1;
	        }
	        else if (A[i]+ B[j] > x) {
	            j++;
	        }
	        else if (A[i] + B[j] < x) {
	            i++;
	        }
	    }
	    if (flag == 0) {
	        cout << -1;
	    }
	    cout << endl;
	}
	return 0;
}