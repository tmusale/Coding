// ADDREV - Adding Reversed Numbers

#include <iostream>
using namespace std;

int reverse(int);

int main()
{
	int N;
	int a;
	int b;

	cin >> N;
	while (N--) {
		cin >> a;
		cin >> b;

		int r1 = reverse(a);
		int r2 = reverse(b);

		r1 = r1 + r2;

		r1 = reverse(r1);

		cout << r1 << endl;
	}
}

int reverse(int a)
{
	int c;
	int b;
	c = 0;

	while (a > 0) {
		b = a % 10;
		c = (c * 10) + b;
		a = a / 10;
	}

	return c;
}