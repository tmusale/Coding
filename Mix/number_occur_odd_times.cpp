/*
Find the numeber occuring odd number of times in an array given that exactly 
one  number occur odd number of times.
*/

#include <bits/stdc++.h>
using namespace std;

int findodd(int arr[], int n)
{
	int res = arr[0];
	for (int i = 1; i < n; i++) {
		res = res ^ arr[i];
	}
	return res;
}

int main()
{
	int n;
	
	cin >> n;
	
	int arr[n];

	for (int i =0; i < n; ++i) {
		cin >> arr[i];
	}
	int res = findodd(arr, n);
	cout << res << endl;

	return 0;
}