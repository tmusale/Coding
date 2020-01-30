/*
Sort an array of 0s, 1s and 2s
Given an array A of size N containing 0s, 1s, and 2s; you need to sort the array in ascending order.

Input:
The first line contains an integer 'T' denoting the total number of test cases. Then T testcases follow. 
Each testcases contains two lines of input. The first line denotes the size of the array N. The second lines 
contains the elements of the array A separated by spaces.

Output: 
For each testcase, print the sorted array.

Constraints: 
1 <= T <= 500
1 <= N <= 106
0 <= Ai <= 2

Example:
Input :
2
5
0 2 1 2 0
3
0 1 0

Output:
0 0 1 2 2
0 0 1

Explanation:
Testcase 1: After segragating the 0s, 1s and 2s, we have 0 0 1 2 2 which shown in the output.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	int n;
	
	cin >> t;
	while (t--) {
	    //unordered_map<int, int> mp;
	    cin >> n;
	    int arr[n];
	    int count0 = 0;
	    int count1 = 0;
	    int count2 = 0;
	    
	    for (int i = 0; i < n; i++) {
	        cin >> arr[i];
	        if (arr[i] == 0) {
	            count0++;
	        }
	        else if (arr[i] == 1) {
	            count1++;
	        }
	        else if(arr[i] == 2) {
	            count2++;
	        }
	    }
	    
	    for (int i = 0; i < n; i++) {
	        if (count0 > 0) {
	            cout << 0 << " ";
	            count0--;
	        }
	        else if (count1 > 0) {
	            cout << 1 << " ";
	            count1--;
	        }
	        else if (count2 > 0) {
	            cout << 2 << " ";
	            count2--;
	        }
	    }
	    cout << endl;
	}
	return 0;
}