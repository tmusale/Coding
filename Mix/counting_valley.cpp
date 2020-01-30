// counting valley - hackerrank

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	char x;
	int level;
	int count;

	cin >> n;

	string v;

	cin >> v;
	/*for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}*/
	level = 0;
	count = 0;

	for (int i = 0; i < n; i++) {
		if (v[i] == 'U') {
			level++;
			if (level == 0) {
				count++;
			}
		}
		if (v[i] == 'D') {
			level--;
		}
	}
	cout << count;
	cout << endl;

	return 0; 

}
