/*
Given an array A, find three elements such that their sum equals to X.
*/

#include <bits/stdc++.h>
using namespace std;

int findTriplets(int arr[], int n, int x)
{
	int left;
	int right;
	int sum; 

	sort(arr, arr+n);
	for (int i = 0; i < n-2; i++) {
		left = i+1;
		right = n-1;
		while (left < right) {
			sum = arr[i] + arr[left] + arr[right];
			if (sum == x) {
				cout << arr[i] << " " << arr[left] << " " << arr[right] << endl;
				return 1;
			}
			if (sum < x) {
				left++;
			}
			else {
				right--;
			}
		}
	}
	return 0;
}

int main()
{
	int n;
	int x;

	cin >> n;
	cin >> x;
	
	int arr[n];

	for (int i =0; i < n; ++i) {
		cin >> arr[i];
	}
	int res = findTriplets(arr, n, x);
	cout << endl;

	return 0;
}