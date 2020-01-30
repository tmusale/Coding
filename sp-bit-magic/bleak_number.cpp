/*
Bleak Numbers
Given an integer, check whether it is Bleak or not.

A number ‘n’ is called Bleak if it cannot be represented as sum of 
a positive number x and set bit count in x, i.e., x + countSetBits(x) 
is not equal to n for any non-negative number x.

Examples :

3 is not Bleak as it can be represented
as 2 + countSetBits(2).

4 is t Bleak as it cannot be represented 
as sum of a number x and countSetBits(x)
for any number x.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. Each test case consists of a single line. The first line 
of each test case contains a single integer N to be checked for Bleak.

Output:
Print "1" or "0" (without quotes) depending on whether the number is Bleak or not.

Constraints:
1 <= T <= 1000
1 <= N <= 10000

Example:
Input:
3
4
167
3

Output:
1
0
0
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countSetBits(int x)
{
    int count = 0;
    
    while (x > 0) {
        if ((x%2) == 0) {
            
        }
        else {
            count++;
        }
        x = x / 2;
    }
    
    return count;
}

int main() {
	//code
	int t;
	int n;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    
	    int flag = 0;
	    for (int x = 1; x < n; x++) {
	        if (x + countSetBits(x) == n) {
	            flag = 1;
	            break;
	        }
	    }
	    
	    if (flag == 0) {
	        cout << "1";
	    }
	    else {
	        cout << "0";
	    }
	    cout << endl;
	    
	}
	return 0;
}