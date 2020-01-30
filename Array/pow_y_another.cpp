/*
Check if a number is power of another number
Given two positive numbers x and y, check if y is a power of x or not.

Input:
First line contains an integer, the number of test cases 'T'. Each test case should contain two positive numbers x and y.


Output:
Print 1 if y is a power of x, else print 0.


Constraints: 
1<=T<=30
1<=x<=103
1<=y<=108


Example:
Input:
2
2 8
1 3

Output:
1
0

Explanation: 8 is a power of 2, but 3 is not a power of 1.
*/

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int t;
	int x;
	int y;
	
	cin >> t;
	while (t--) {
	    cin >> x;
	    cin >> y;
	    
	    float ex = log10(y) / log10(x);
	    float temp = ex - (int)ex;
	    if (temp > 0) {
	        cout << 0;
	    }
	    else {
	        cout << 1;
	    }
	    cout << endl;
	}
	return 0;
}