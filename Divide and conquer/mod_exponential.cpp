/*
Modular Exponentiation for large numbers

Implement pow(A, B) % C.

In other words, given A, B and C, find (AB)%C.

 

Input:

The first line of input consists number of the test cases.

 The following T lines consist of 3 numbers each separated by a space and in the following order:

A B C

'A' being the base number, 'B' the exponent (power to the base number) and 'C' the modular.

 

Output:

In each separate line print the modular exponent of the given numbers in the test case.


Constraints:

1 ≤ T ≤ 70

1 ≤ A ≤ 10^5

1 ≤ B ≤ 10^5

1 ≤ C ≤ 10^5


Example:

Input:

3
3 2 4
10 9 6
450 768 517

Output:

1
4
34
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod_exp(ll a, ll b, ll c)
{
    if (b == 1) {
        return a%c;
    }
    if ((b%2) != 0) {
        return (mod_exp(a, 1, c) * mod_exp(a, b-1, c))%c;
    }
    else {
        return (mod_exp(a, b/2, c) * mod_exp(a, b/2, c))%c;
    }
}

int main() {
	//code
	int t;
	ll a;
	ll b;
	ll c;
	
	cin >> t;
	while (t--) {
	    cin >> a;
	    cin >> b;
	    cin >> c;
	    
	    cout << mod_exp(a, b, c) << endl;
	}
	return 0;
}