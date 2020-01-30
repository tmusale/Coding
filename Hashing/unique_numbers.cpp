/*
Unique Numbers
In given range, print all numbers having unique digits. e.g. In range 1 to 20 should print all numbers except 11.

Input:
First line consists of T test cases.
The only line of every test case consists of two integers m and n separated by a space.

Output:
For each test case print all unique numbers separated by space.

Constraints:
1<=T<=100
1<=m,n<1000

Example:
Input:
1
10 20
Output:
10 12 13 14 15 16 17 18 19 20

** For More Input/Output Examples Use 'Expected Output' option **
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int check_unique(int n)
{
    unordered_set<int> s;
    
    while (n > 0) {
        int temp = n %10;
        if (s.find(temp) != s.end()) {
            return 0;
        }
        s.insert(temp);
        n = n / 10;
    }
    
    return 1;
}

int main() {
	//code
	int t;
	int m;
	int n;
	
	cin >> t;
	while (t--){
	    cin >> m;
	    cin >> n;
	    
	    for (int i = m; i <= n; i++) {
	        if (check_unique(i)) {
	            cout << i << " ";
	        }
	    }
	    cout << endl;
	}
	return 0;
}