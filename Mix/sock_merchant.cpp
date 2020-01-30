//sock merchant - hackerrank
//John works at a clothing store. He has a large pile of socks that he must pair by color for sale. 
//Given an array of integers representing the color of each sock, 
//determine how many pairs of socks with matching colors there are.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sock_merchant(int n, std::vector<int> v)
{
	int flag;
	int result = 0;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != v[i-1]) {
			int c = count(v.begin(), v.end(), v[i]);
			c = c / 2;
			result = result + c;
		}

	}
	return result;	
}

int main()
{
	int n;
	int x;
	cin >> n;

	std::vector<int> v(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		v.push_back(x);
	}

	int result = sock_merchant(n, v);
	cout << result;
	cout << endl;

	return 0;
}