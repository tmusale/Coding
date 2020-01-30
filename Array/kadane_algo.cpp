/*
Kadane's Algorithm
Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. 
The first line of each test case contains a single integer N denoting the size of array. The second line contains 
N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print the maximum sum of the contiguous sub-array in a separate line for each test case.

Constraints:
1 ≤ T ≤ 110
1 ≤ N ≤ 106
-107 ≤ A[i] <= 107

Example:
Input
2
5
1 2 3 -2 5
4
-1 -2 -3 -4
Output
9
-1

Explanation:
Testcase 1: Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray.
*/

#include <bits/stdc++.h>
using namespace std;

int kadane(int arr[], int n)
{
    int cur_max = 0;
    int max_so_far = -1;
    
    for (int i = 0; i < n; i++) {
        cur_max += arr[i];
        
        if (max_so_far < cur_max) {
            max_so_far = cur_max;
        }
        if (cur_max < 0) {
            cur_max = 0;
        }
    }
    
    if (max_so_far == -1) {
        auto it = std::max_element(arr, arr+n);
        int max = *it;
        return max;
    }
    return max_so_far;
}

int main() {
	//code
	int t;
	int n;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    int arr[n];
	    
	    for (int i = 0; i < n; i++) {
	        cin >> arr[i];
	    }
	    
	    cout << kadane(arr, n) << endl;
	}
	return 0;
}