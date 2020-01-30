/*
Sequence of Sequence
Given two integers m & n, find the number of possible sequences of length n such that 
each of the next element is greater than or equal to twice of the previous element but less than or equal to m.

Input:
First line consists of test case T. Only line of every test case consists of 2 integers M and N.

Output:
Single line output, number of sequences possible.

Constraints:
1<=T<=100
1<=M,N<=100

Example:
Input:
2
10 4
5 2
Output:
4
6

Explanation:
Input : m = 10, n = 4
Output : 4
There should be n elements and value of last
element should be at-most m.
The sequences are {1, 2, 4, 8}, {1, 2, 4, 9},
                 {1, 2, 4, 10}, {1, 2, 5, 10}

Input : m = 5, n = 2
Output : 6
The sequences are {1, 2}, {1, 3}, {1, 4},
                  {1, 5}, {2, 4}, {2, 5}
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int sequence(int m, int n)
{
    if (m < n) {
        return 0;
    }
    
    if (n == 0) {
        return 1;
    }
    
    return sequence(m-1, n) + sequence(m/2, n-1);
}

int main() {
	//code
	int t;
	int m;
	int n;
	
	cin >> t;
	while (t--) {
	    cin >> m;
	    cin >> n;
	    
	    cout << sequence(m, n) << endl;
	}
	return 0;
}