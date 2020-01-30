/*
Sort in specific order
Given an array A of positive integers. Your task is to sort them in such a way that
 the first part of the array contains odd numbers sorted in descending order, 
 rest portion contains even numbers sorted in ascending order.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. Each test case contains an integer N denoting the size of the array.
 The next line contains N space separated values of the array.

Output:
For each test case in a new line print the space separated values of the modified array.

Constraints:
1 <= T <= 103
1 <= N <= 107
0 <= Ai <= 1018

Example:
Input:
2
7
1 2 3 5 4 7 10
7
0 4 5 3 7 2 1

Output:
7 5 3 1 2 4 10
7 5 3 1 0 2 4

Explanation:
Testcase1: Array elements 7 5 3 1 are odd and sorted in descending order, 
whereas 2 4 10 are even numbers and sorted in ascending order.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	//code
	int T;
	int n;
	int x;
	
	cin >> T;
	while (T--) {
	    cin >> n;
	    int arr[n];
	    
	    for (int i = 0; i < n; i++) {
	        cin >> arr[i];
	    }
	    
	    vector<int> even;
	    vector<int> odd;
	    
	    for (int i = 0; i < n; i++) {
	        if (arr[i]%2 == 0) {
	            even.push_back(arr[i]);
	        }
	        else {
	            odd.push_back(arr[i]);
	        }
	    }
	    sort(odd.begin(), odd.end(), greater<int>());
	    sort(even.begin(), even.end());
	    
	    for (auto i = odd.begin(); i != odd.end(); i++) {
	        cout << *i << " ";
	    }
	    for (auto i = even.begin(); i != even.end(); i++) {
	        cout << *i << " ";
	    }
	    cout << endl;
	    even.clear();
	    odd.clear();
	}
	return 0;
}