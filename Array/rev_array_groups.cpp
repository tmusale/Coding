/*
Reverse array in groups
Given an array arr[] of positive integers of size N. Reverse every sub-array of K group elements.

Input:
The first line of input contains a single integer T denoting the number of test cases. 
Then T test cases follow. Each test case consist of two lines of input. 
The first line of each test case consists of an integer N(size of array) and an integer K separated by a space. 
The second line of each test case contains N space separated integers denoting the array elements.

Output:
For each test case, print the modified array.

Constraints:
1 ≤ T ≤ 200
1 ≤ N, K ≤ 107
1 ≤ A[i] ≤ 1018

Example:
Input
1
5 3
1 2 3 4 5

Output
3 2 1 5 4

Explanation:
Testcase 1: Reversing groups in size 3, first group consists of elements 1, 2, 3. 
Reversing this group, we have elements in order as 3, 2, 1.
*/

#include <iostream>
using namespace std;

void reverse(int v[], int l, int m)
{
	int i = l;
	int j = m-1;

	while (i < j) {
		int temp = v[i];
		v[i] = v[j];
		v[j] = temp;

		i++;
		j--;
	}

	
}

int main() {
	//code
	int T;
	int n;
	int d;
	
	cin >> T;
	while (T--) {
	    cin >> n;
	    cin >> d;
	    int arr[n];
	    for (int i = 0; i < n; i++) {
	        cin >> arr[i];
	    }
	    
	    int k;
	    if (n%d == 0) {
	        k = n / d;
	    }
	    else {
	        k = n / d;
	        k++;
	    }
	    //cout << k;
	    int l = 0;
	    int m = d;
	    for (int i = 0; i < k; i++) {
	        if (m > n) {
	            m = n;
	        }
	        reverse(arr, l, m);
	        l = l + d;
	        m = m + d;
	    }
	
	    for (int i = 0; i < n; i++) {
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	
	return 0;
}