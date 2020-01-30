/*
Count distinct pairs with difference k

Given an integer array and a non-negative integer k, 
count all distinct pairs with difference equal to k, i.e., A[ i ] - A[ j ] = k.


Input:

The first line of input consists number of the test cases. The description of T test cases is as follows:

The first line of each test case contains the size of the array, the second line has the elements of 
the array and the third line consists of the difference k.

Output:

In each separate line print the number of times difference k exists between the elements of the array.


Constraints:

1 ≤ T ≤ 100
1 ≤ N≤ 100
0≤K≤100
0 ≤ A[i] ≤ 10000


Example:

Input:

3
5 
1 5 4 1 2
0
3
1 1 1
0
3 
1 5 3
2

Output:

1
1
2
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	int n;
	int k;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    int arr[n];
	    unordered_map<int, int> s, mp;
	    int temp;
	    
	   int a1 = 0;
	    for (int i = 0; i < n; i++) {
	        cin >> temp;
	        mp[temp]++;
	        if (mp[temp] <= 2) {
	            arr[a1++] = temp;
	        }
	    }
	    cin >> k;
	    int count = 0;
	    
	    /*if (k != 0) {
	        for (int i= 0; i < n; i++) {
	            if (s.find(arr[i] - k) != s.end()) {
	                count++;
	            }
	        }
	    }
	    else {
	        for (auto i = s.begin(); i != s.end(); i++) {
	            if ((*i) > 1) {
	                count += (*i) / 2;
	            }
	        }
	    }*/
	    
	    for (int i = 0; i < n; i++) {
	        for (int j = i+1; j < n; j++) {
	            int diff = abs(arr[i] - arr[j]);
	            s[diff]++;
	        }
	    }
	    
	    //count = count/2;
	    cout << s[k] << endl;
	    s.clear();
	    
	}
	return 0;
}