/*
Given an array, find two elements whose sum is closest to 0.
*/

#include <bits/stdc++.h>
using namespace std;

void sumClosestToZero(int arr[], int n)
{
	int cur_sum;
	int closest_sum = INT_MAX;
	int l = 0;
	int r = n-1;
	int min_l = l;
	int min_r = n-1;

	//qsort(arr, n, sizeof(int), compareFun);
	sort(arr, arr+n);

	while (l < r) {
		cur_sum = arr[l] + arr[r];
		if (abs(cur_sum) < abs(closest_sum)) {
			closest_sum = cur_sum;
			min_l = l;
			min_r = r;
		}

		if (cur_sum < 0) {
			l++;
		}
		else {
			r--;
		}
	}

	cout << arr[min_l] << " " << arr[min_r] << endl;
}

int main()
{
	int n;
	
	cin >> n;
	
	int arr[n];

	for (int i =0; i < n; ++i) {
		cin >> arr[i];
	}
	sumClosestToZero(arr, n);
	cout << endl;

	return 0;
}