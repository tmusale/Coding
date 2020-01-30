/*
First element to occur k times

Given an array of N integers. The task is to find the first element that occurs K number of times. If no element occurs K times the print -1.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test 
case contains an integer N denoting the size of an array and the number K. The second line of each test case contains N space separated 
integers denoting elements of the array A[ ].

Output:
For each test case in a new line print the required answer.

Constraints:
1 <= T <= 100
1 <= N, K <= 105
1<= A <= 106

Example:
Input :
1
7 2
1 7 4 3 4 8 7
Output :
7

Explanation:
Both 7 and 4 occur 2 times. But 7 is the first that occurs 2 times.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	int n;
	int k;
	unordered_map<int, int> hash;
	vector<int> v;
	int x;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    cin >> k;
	    
	    for (int i = 0; i < n; i++) {
	        cin >> x;
	        v.push_back(x);
	        hash[x]++;
	    }
	    
	    int flag = 1;
	    for (int i = 0; i < n; i++) {
	        if (hash[v[i]] == k) {
	            cout << v[i] << endl;
	            flag = 0;
	            break;
	        }
	    }
	    if (flag) {
	        cout << "-1" << endl;
	    }
	    v.clear();
	    hash.clear();
	}
	return 0;
}