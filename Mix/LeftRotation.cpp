#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::vector<int> v;
	int x;
	int n;
	int d;

	cin >> n;
	cin >> d;

	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	std::vector<int> v1(n);

	int temp = v[0];
	for (int i = 0; i < n; i++) {
		v1[i] = v[(i+d)%n];
	}

	for (int i = 0; i < n; i++) {
		cout << v1[i] << " ";
	}
	cout << endl;

	return 0;
}