/*
Check if two arrays are equal or not
Given two arrays A and B of equal size N, the task is to find if given arrays are equal or not. 
Two arrays are said to be equal if both of them contain same set of elements, arrangements (or permutation) 
of elements may be different though.
Note : If there are repetitions, then counts of repeated elements must also be same for two array to be equal.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow.  
Each test case contains 3 lines of input. The first line contains an integer N denoting the size of the array. 
The second line contains element of array A[]. The third line contains elements of the array B[].

Output:
For each test case, print 1 if the arrays are equal else print 0.

Constraints:
1<=T<=100
1<=N<=107
1<=A[],B[]<=1018

Example:
Input:
2
5
1 2 5 4 0
2 4 5 0 1
3
1 2 5
2 4 15
Output:
1
0

Explanation:
Testcase1:
Input : A[] = {1, 2, 5, 4, 0}; B[] = {2, 4, 5, 0, 1};
Output : 1
Testcase2:
Input : A[] = {1, 2, 5}; B[] = {2, 4, 15};
Output : 0
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	unsigned long long int n;
	//unordered_map<unsigned long long int, unsigned long long int> hash;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    unsigned long long int arr1[n];
	    unsigned long long int arr2[n];
	    
	    for (int i = 0; i < n; i++) {
	        cin >> arr1[i];
	        //hash[arr1[i]]++;
	    }
	    for (int i = 0; i < n; i++) {
	        cin >> arr2[i];
	        //if (hash.find(arr2[i]) != hash.end())
	           // hash[arr2[i]]--;
	    }
	    
	    sort(arr1, arr1+n);
	    sort(arr2, arr2+n);
	    
	    int flag = 1;
	    for (int i = 0; i < n; i++) {
	        if (arr1[i] != arr2[i]) {
	            flag = 0;
	            break;
	        }
	    }
	    
	    if (flag) {
	        cout << "1" << endl;
	    }
	    else {
	        cout << "0" << endl;
	    }
	    //hash.clear();
	    //for (int i = )
	    
	}
	return 0;
}