/*
Reversal algorithm for right rotation of an array

Given an array, right rotate it by k elements.
1, 2, 3, 4, 5, 6, 7, 8, 9, 10

After K=3 rotation
8, 9, 10, 1, 2, 3, 4, 5, 6, 7

Input: arr[] = {121, 232, 33, 43 ,5}
           k = 2
Output: 43 5 121 232 33

Algorithm:

rotate(arr[], d, n)
  reverseArray(arr[], 0, n-1) ;
  reverse(arr[], 0, d-1);
  reverse(arr[], d, n-1);

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int x;
	int k;
	std::vector<int> v;

	cin >> n;
	cin >> k;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}

	reverse(v.begin(), v.end());
	reverse(v.begin(), v.begin() + k-1);
	reverse(v.begin() + k, v.end());

	for (auto i = v.begin(); i < v.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;

	return 0;
}