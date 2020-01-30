// jumping on the clouds

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	int x;
	int count;

	cin >> n;

	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}

	int i = 0;
	count = 0;
	while (i < n) {
		if ((v[i+2] == 0) && (i+2 < n)) {
			i = i + 2;
			count++;
		}
		else if ((v[i+1] == 0) && (i+1 < n)) {
			i++;
			count++;
		}
	}
	cout << count; 
	cout << endl;

	return 0;
}