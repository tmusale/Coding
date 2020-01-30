//Given an array A[] and a number x, check for pair in A[] with sum as x

#include <iostream>
#include <vector>
using namespace std;

bool find_pair(std::vector<int> v, int n, int sum)
{
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		if(v[i] > v[i+1]) {
			break;
		}
	}

	int l = (i+1)%n;
	int r = i;

	while (l != r) {
		if (v[l]+v[r] == sum) {
			return 1;
		}
		else if (v[l]+v[r] < sum) {
			l = (l + 1) % n;
		}
		else {
			r = (n + r - 1) % n;
		}
	}

	return 0;
}

int main()
{
	std::vector<int> v;
	int n;
	int x;
	int sum;

	cin >> n;
	cin >> sum;

	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		v.push_back(x);
	}

	if (find_pair(v, n, sum)) {
		cout << "true";
	}
	else {
		cout << "false";
	}
	cout << endl;

	return 0;
}