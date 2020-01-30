#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> v, int low, int high, int key)
{
	if (high < low) {
		return -1;
	}

	int mid = (low + high) / 2;

	if (v[mid] == key) {
		return mid;
	}

	if (key > v[mid]) {
		return binary_search(v, mid+1, high, key);
	}

	return binary_search(v, low, mid-1, key);
}

int find_pivot(vector<int> v, int low, int high)
{
	if(high < low) {
		return -1;
	}

	if (high == low) {
		return low;
	}

	int mid = (low + high) / 2;
	if (mid < high && v[mid] > v[mid+1]) {
		return  mid;
	}

	if (mid > low && v[mid] < v[mid-1]) {
		return mid-1;
	}

	if (v[low] >= v[mid]) {
		return find_pivot(v, low, mid-1);
	}

	return find_pivot(v, mid+1, high);
}

int pivotedBinarySearch(vector<int> v, int n, int key)
{
	int pivot = find_pivot(v, 0, n-1);

	if (pivot == -1) {
		return binary_search(v, 0, n-1, key);
	}

	if (v[pivot] == key) {
		return pivot;
	}

	if (v[0] <= key) {
		return binary_search(v, 0, pivot-1, key);
	}

	return binary_search(v, pivot+1, n-1, key);
}

int main()
{
	std::vector<int> v;
	int n;
	int x;
	int key;

	cin >> n;
	cin >> key;

	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		v.push_back(x);
	}

	int res = pivotedBinarySearch(v, n, key);
	cout << "Index := " << res << endl;
}

