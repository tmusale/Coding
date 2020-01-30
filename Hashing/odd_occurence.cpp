/*
Find the Odd Occurence
Given an array of positive integers where all numbers occur even number of times except one 
number which occurs odd number of times. Find the number.

Input:
The first line of input contains a single integer T denoting the number of test cases. 
Then T test cases follow. Each test case consist of two lines. The first line of each 
test case consists of an integer N, where N is the size of array. The second line of 
each test case contains N space separated integers denoting array elements.

 

Output:
Corresponding to each test case, print the number which occur odd number of times. If no such element exists, print 0.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
1 ≤ A[i] ≤ 106

Example:
Input:
1
5
8 4 4 8 23
Output:
23

Explanation:
Testcase 1: 23 is the element which occurs odd number of times.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	int n;
	vector<int> v;
	unordered_map<int, int> hash;
	int x;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    for (int i = 0; i < n; i++) {
	        cin >> x;
	        v.push_back(x);
	        hash[x]++;
	    }
	    
	    int flag = 1;
	    for (int i = 0; i < n; i++) {
	        if ((hash[v[i]]%2) == 1) {
	            cout << v[i] << endl;
	            flag = 0;
	            break;
	        }
	    }
	    if (flag) {
	        cout << "0" << endl;
	    }
	    hash.clear();
	    v.clear();
	}
	
	return 0;
}