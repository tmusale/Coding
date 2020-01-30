/*
seperate Os and 1s in an array.
*/

#include <bits/stdc++.h>
using namespace std;

void seperate(int arr[], int n)
{
	int l = 0;
	int r = n-1;

	while (l < r) {
		while ((arr[l] == 0) && (l < r)) {
			l++;
		}
		while ((arr[r] == 1) && (r > l)) {
			r--;
		}
		
		if (l < r) {
			arr[l++] = 0;
			arr[r--] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

int main()
{
	int n;
	
	cin >> n;
	
	int arr[n];

	for (int i =0; i < n; ++i) {
		cin >> arr[i];
	}
	seperate(arr, n);
	cout << endl;

	return 0;
}