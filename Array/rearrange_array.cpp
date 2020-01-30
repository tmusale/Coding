/*
Rearrange array such that arr[i] >= arr[j] if i is even and arr[i]<=arr[j] if i is odd and j < i
Given an array of n elements. Our task is to write a program to 
rearrange the array such that elements at even positions are greater 
than all elements before it and elements at odd positions
 are less than all elements before it.

 Input : arr[] = {1, 2, 3, 4, 5, 6, 7}
Output : 4 5 3 6 2 7 1

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rearrange(std::vector<int> v, int n)
{
	std::vector<int> temp(n);

	int even = n/2;
	int odd = n - even;

	for (int i = 0; i < n; i++) {
		temp[i] = v[i];
	}

	sort(temp.begin(), temp.end());

	int j = odd - 1;

	for (int i = 0; i < n; i = i+2) {
		v[i] = temp[j];
		j--;
	}

	j = odd;
	for (int i = 1; i < n; i = i+2) {
		v[i] = temp[j];
		j++;
	}

	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
}

int main()
{
	std::vector<int> v;
	int n;
	int x;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		v.push_back(x);
	}

	rearrange(v, n);
}