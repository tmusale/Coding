/*
Minimize the sum of product
You are given two arrays, A and B, of equal size N. The task is to find 
the minimum value of A[0] * B[0] + A[1] * B[1] +…+ A[N-1] * B[N-1], where shuffling 
of elements of arrays A and B is allowed.

Input:
The first line of input contains an integer T denoting the no of test cases. 
Then T test cases follow. Each test case contains three lines. The first line 
contains an integer N denoting the size of the arrays. In the second line are 
N space separated values of the array A[], and in the last line are N space 
separated values of the array B[].

Output:
For each test case, print the minimum sum.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= A[] <= 1018

Example:
Input:
2
3 
3 1 1
6 5 4
5
6 1 9 5 4
3 4 8 2 4
Output:
23 
80

Explanation:
For testcase1: 1*6+1*5+3*4 = 6+5+12 = 23 is the minimum sum
For testcase2: 2*9+3*6+4*5+4*4+8*1 =18+18+20+16+8 = 80 is the minimum sum
*/

#include <bits/stdc++.h>
using namespace std;
#define  ll long long int

int main() {
	//code
	int t;
	ll n;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    vector<ll> v1;
	    vector<ll> v2;
	    ll x;
	    
	    for (int i = 0; i < n; i++) {
	        cin >> x;
	        v1.push_back(x);
	    }
	    
	    for (int i = 0; i < n; i++) {
	        cin >> x;
	        v2.push_back(x);
	    }
	    
	    sort(v1.begin(), v1.end());
	    sort(v2.begin(), v2.end(), greater<int>());
	    
	     long long int res= 0;
	    for (int i = 0; i < n; i++) {
	        res += v1[i] * v2[i];
	    }
	    
	    cout << res << endl;
	}
	return 0;
}