// Chef and Interactive Contests

#include <iostream>
using namespace std;

int main()
{
	int n;
	int r;
	cin >> n;
	cin >> r;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (arr[i] < r) {
			cout << "Bad boi\n";
		}
		else {
			cout << "Good boi\n";
		}
	}
	return 0;
}