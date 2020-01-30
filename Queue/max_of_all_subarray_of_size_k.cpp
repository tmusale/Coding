/*
Maximum of all subarrays of size k

Given an array A and an integer K. Find the maximum for each and every contiguous subarray of size K.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case contains a single 
integer N denoting the size of array and the size of subarray K. The second line contains N space-separated integers A1, A2, ..., AN 
denoting the elements of the array.

Output:
Print the maximum for every subarray of size k.

Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 107
1 ≤ K ≤ N
0 ≤ A[i] <= 107

Example:
Input:
2
9 3
1 2 3 1 4 5 2 3 6
10 4
8 5 10 7 9 4 15 12 90 13

Output:
3 3 4 5 5 5 6
10 10 10 15 15 90 90

Explanation:
Testcase 1: Starting from first subarray of size k = 3, we have 3 as maximum. Moving the window forward, maximum element are 
as 3, 4, 5, 5, 5 and 6.
*/

#include <bits/stdc++.h>
using namespace std;

void max_sub(int arr[], int n, int k)
{
    deque<int> dq;
    dq.push_back(0);
    for (int i = 1;i < k; i++) {
        if (arr[dq.back()] > arr[i]) {
            dq.push_back(i);
        }
        else {
            while (!dq.empty() && arr[dq.back()] < arr[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
    }
    cout << arr[dq.front()] << " ";
    
    for (int i = k; i < n; i++) {
        if (arr[dq.back()] > arr[i]) {
            dq.push_back(i);
        }
        else {
            while (!dq.empty() && arr[dq.back()] < arr[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        while (!dq.empty() && (i - dq.front()) >= k) {
            dq.pop_front();
        }
        cout << arr[dq.front()] << " ";
    }
}

int main() {
	//code
	int t;
	int n;
	int k;
	
	cin >> t;
	while (t--) {
	    cin >> n >> k;
	    int arr[n];
	    
	    for (int i = 0; i < n; i++) {
	        cin >> arr[i];
	    }
	    
	    max_sub(arr, n, k);
	    cout << endl;
	}
	return 0;
}