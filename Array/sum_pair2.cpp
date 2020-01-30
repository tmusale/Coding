//Given an array A[] and a number x, check for pair in A[] with sum as x

#include <iostream>
#include <vector>
#include <set>
using namespace std;

void print_pair(std::vector<int> v, int n, int sum)
{
	set<int> s;

	for (int i = 0; i < n; ++i)
	{
		int temp = sum - v[i];

		if (temp > 0 && s.find(temp) != s.end()) {
			cout << "pair of sum " << sum << " = (" << v[i] << ", " << temp << ")" << endl;
		}

		s.insert(v[i]);
	}
}

int main()
{
	std::vector<int> v;
	int n;
	int sum;
	int x;

	cin >> n;
	cin >> sum;

	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		v.push_back(x);
	}

	print_pair(v, n, sum);

	return 0;
}