/*
Kth smallest element


Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest element 
in the given array. It is given that all array elements are distinct.

Expected Time Complexity: O(n)

Input:
The first line of input contains an integer T, denoting the number of testcases. Then T test cases follow. Each test case 
consists of three lines. First line of each testcase contains an integer N denoting size of the array. Second line contains 
N space separated integer denoting elements of the array. Third line of the test case contains an integer K.

Output:
Corresponding to each test case, print the kth smallest element in a new line.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= arr[i] <= 105
1 <= K <= N

Example:
Input:
2
6
7 10 4 3 20 15
3
5
7 10 4 20 15
4

Output:
7
15

Explanation:
Testcase 1: 3rd smallest element in the given array is 7.
*/

#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = low;
    int i = low;
    int j = high;
    
    while (i < j) {
        while (arr[i] <= arr[pivot] && i <= high) {
            i++;
        }
        
        while (arr[j] > arr[pivot] && j >= low) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[pivot]);
    
    return j;
}

int quicksort(int arr[], int low, int high, int k)
{
    int pivot = partition(arr, low, high);
    
    if (pivot == (k-1)) {
        return arr[k-1];
    }
    else if (pivot > k-1) {
        return quicksort(arr, low, pivot, k);
    }
    else {
        return quicksort(arr, pivot+1, high, k);
    }
}

int main() {
	//code
	int t;
	int n;
	int k;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    int arr[n];
	    for (int i = 0; i < n; i++) {
	        cin >> arr[i];
	    }
	    cin >> k;
	    
	    cout << quicksort(arr, 0, n-1, k) << endl;
	}
	return 0;
}