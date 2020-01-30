/*
Non-Repeating Element

Find the first non-repeating element in a given array A of N integers.
Note: Array consists of only positive and negative integers and not zero.

Input:
The first line of input is an integer T, denoting the number of test cases. 
Each test case has subsequent two lines of input. First line is an integer N, 
denoting size of integer array A. Second line consists of N space separated integers of the array A.

Output:
For each testcase, print the required answer. If no such element exists, then print 0

Constraints:
1 <= T <= 100;
1 <= N <= 107;
-1016 <= Ai <= 1016
{Ai !=0 }

Example:
Input:
4
5
-1 2 -1 3 2
6
9 4 9 6 7 4
3
1 1 1
2
-3 2
Output:
3
6
0
-3
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*void first_nonrepeating(vector<long long int> v, int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        if (mp.find(v[i]) == mp.end()) {
            mp.insert({v[i], 1});
        }
        else {
            auto it = mp.find(v[i]);
            (it->second)++;
        }
    }
    
    int min = INT_MAX;
    int val;
    for (int i = 0; i < n; i++) {
        auto it = mp.find(v[i]);
        if (it->second < min) {
            min = it->second;
            val = v[i];
        }
    }
    if (min == 1) {
        cout << val << endl;
    }
    else {
        cout << "0" << endl;
    }
    mp.clear();
}
*/
int main() {
	//code
	int t;
	long long int n;
	vector<long long int> v;
	unordered_map<int, int> hash;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    long long int x;
	    for (int i = 0; i < n; i++) {
	        cin >> x;
	        v.push_back(x);
	        hash[x]++;
	    }
	    
	    //first_nonrepeating(v, n);
	    int flag = 1;
	    for (int i = 0; i < n; i++) {
	        if (hash[v[i]] == 1) {
	            cout << v[i] << endl;
	            flag = 0;
	            break;
	        }
	    }
	    if (flag) {
	        cout << "0" << endl;
	    }
	    v.clear();
	    hash.clear();
	}
	return 0;
}