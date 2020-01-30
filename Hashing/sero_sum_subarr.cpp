/*
Zero Sum Subarrays
You are given an array A of size N. You need to print the total count of sub-arrays having their sum equal to 0

Input:
First line of the input contains an integer T denoting the number of test cases. Each test case consists of two lines. 
First line of each test case contains an Integer N denoting the size of the array, and the second line contains N space separated integers.

Output: 
For each test case, in a new line, print the total number of subarrays whose sum is equal to 0.

Constraints:    
1 <= T <= 100
1<= N <= 107
-1010 <= Ai <= 1010

Example:
Input:
2
6
0 0 5 5 0 0
10
6  -1 -3 4 -2 2 4 6 -12 -7

Output:
6
4
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	long int n;
	unordered_map<long long int, long long int> hash;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    long long int arr[n];
	    for (int i= 0; i < n; i++) {
	        cin >> arr[i];
	    }
	    long long int sum = 0;
	    long int count = 0;
	    
	    for (int i = 0; i < n; i++) {
	        //sum = 0;
	        sum += arr[i];
	        if (sum == 0) {
	            count++;
	        }
	        
	        if (hash.find(sum) != hash.end()) {
	            count += hash[sum];
	        }
	        
	        hash[sum]++;
	    }
	    
	    cout <<count<< endl;
	    hash.clear();
	}
	return 0;
}