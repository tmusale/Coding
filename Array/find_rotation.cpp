/*
Find the Rotation Count in Rotated Sorted array
Consider an array of distinct numbers sorted in increasing order. 
The array has been rotated (clockwise) k number of times. Given such an array, find the value of k.

Examples:

Input : arr[] = {15, 18, 2, 3, 6, 12}
Output: 2
Explanation : Initial array must be {2, 3,
6, 12, 15, 18}. We get the given array after 
rotating the initial array twice.

Input : arr[] = {7, 9, 11, 12, 5}
Output: 4

Input: arr[] = {7, 9, 11, 12, 15};
Output: 0

Method 2 (Efficient Using Binary Search)
Here are also we find index of minimum element, but using Binary Search. The idea is based on below facts :

The minimum element is the only element whose previous is greater than it. If there is no previous element element, then there is no rotation (first element is minimum). We check this condition for middle element by comparing it with (mid-1)’th and (mid+1)’th elements.
If minimum element is not at middle (neither mid nor mid + 1), then minimum element lies in either left half or right half.
If middle element is smaller than last element, then the minimum element lies in left half
Else minimum element lies in right half.

*/

#include <iostream>
#include <vector>
using namespace std;

int count_rotation(std::vector<int> v, int n, int low, int high)
{
	if (high < low) {
		return 0;
	}
	if (high == low) {
		return low;
	}
	int mid = (low + high) / 2;

	if (mid < high && v[mid+1] < v[mid]) {
		return (mid+1);
	}

	if (mid > low && v[mid] < v[mid-1]) {
		return mid;
	}

	if (v[high] > v[mid]) {
		return count_rotation(v, n, low, mid-1);
	}

	return count_rotation(v, n, mid+1, high);
}

int main()
{
	std::vector<int> v;
	int n;
	int x;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}

	int res = count_rotation(v, n, 0, n-1);
	cout << res << endl;

	return 0;
}