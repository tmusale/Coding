#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::vector<std::vector<int>> v(6);
	int sum = 0;
	int max = -99999;

	for (int i = 0; i < 6; i++) {
		v[i].resize(6);
		for (int j = 0; j < 6; j++) {
			cin >> v[i][j];
		}
	}

	/*or (int i = 0; i < 6; i++) {
		//v[i].resize(6);
		for (int j = 0; j < 6; j++) {
			cout <<"\t" <<v[i][j];
		}
		cout << endl;
	}*/

	for (int i = 0; i < 6; i++) {
		//v[i].resize(6);
		for (int j = 0; j < 6; j++) {
			sum = 0;
			if ((j+2 < 6) && (i+2 < 6)) {
				sum = v[i][j] + v[i][j+1] + v[i][j+2] + v[i+1][j+1] + v[i+2][j] + v[i+2][j+1] + v[i+2][j+2]; 

				if (sum > max) {
				max = sum;
				}
			}
			
		}
	}

	cout << max << endl;
	return 0;
}