//Given a sorted and rotated array, find if there is a pair with a given sum

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::vector<int> v;
	int n;
	int x;
	int k;
	int flag = 0;

	cin >> n;
	cin >> k;

	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		v.push_back(x);
	}

	for (int i = 0; i < n; ++i)
	{
		if (flag == 1) {
			break;
		}
		for (int j = 0; j < n; ++j)
		{
			if (i != j) {
				if ((v[i] + v[j]) == k) {
					cout << "True";
					flag = 1;
					break;
				}
			}
		}
	}
	if (flag == 0) {
		cout << "False";
	}
	cout << endl;

	return 0;
}