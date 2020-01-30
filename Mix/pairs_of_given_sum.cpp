/*
given an array A and a number X find a pair (a, b) in A such that a+b = X.
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 10

void findpairs(int arr[], int n, int sum)
{
	int hash[MAX] = {0};
	int temp;

	for (int i = 0; i < n; ++i) {
		temp = sum - arr[i];

		if (temp >= 0 && hash[temp] == 1) {
			cout << "pair = " << arr[i] << temp << endl;
		}
		hash[arr[i]] = 1;
	}
}

int main()
{
	int n;
	int sum;

	cin >> n;
	cin >> sum;

	int arr[n];

	for (int i =0; i < n; ++i) {
		cin >> arr[i];
	}
	findpairs(arr, n, sum);

	return 0;
}
