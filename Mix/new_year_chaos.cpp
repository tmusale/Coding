#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::vector<int> v;
	int T;
	int n;
	int x;

	cin >> T;

	while (T--) {
		cin >> n;
		std::vector<int> count(n, 0);
		int f = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> x;
			int t = x - (i+1);
			if (t > 2) {
				f = 1;
				break;
			}
			v.push_back(x);
		}
		

		/*for (int i = 0; i < n; ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < n; ++i)
		{
			cout << count[i] << " ";
		}
		cout << endl;*/
		if (f == 1) {
			cout << "Too chaotic";
		}
		else {
			for (int k = 0; k < n-1; k++) {
				for (int i = 0; i < n-1; i++) {
					if (v[i] > v[i+1]) {
						int j = v[i] - 1;
						count[j]++;

						int temp = v[i+1];
						v[i+1] = v[i];
						v[i] = temp;
					}
			
				}
			}

			int sum = 0;
			//int flag = 0;
			for (int i = 0; i < n; ++i) {
				sum += count[i];
			}
			//cout << sum;
		}
		cout << endl;
		v.clear();
		count.clear();

	}

	return 0;
}