/*
Input  : arr[] = {1, 2, 3}
Output : arr[] = {3, 2, 1}
*/

#include <iostream>
#include <vector>
using namespace std;

void reverse(std::vector<int> v, int n)
{
	int i = 0;
	int j = n-1;

	while (i < j) {
		int temp = v[i];
		v[i] = v[j];
		v[j] = temp;

		i++;
		j--;
	}

	for (int i = 0; i < n; i++) {
		cout << v[i] << " "; 
	}
	cout << endl;
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
		reverse(v, n);
}