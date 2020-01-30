/*
Print Pattern

Print a sequence of numbers starting with N, without using loop, in which  A[i+1] = A[i] - 5,  
if  A[i]>0, else A[i+1]=A[i] + 5  repeat it until A[i]=N.

Input:
The first line contains an integer T, number of test cases. Then following T lines contains an integer N.

Output:
For each test case, print the pattern in newline with space separated integers.

Constraints:
0< N < 10000

Example:
Input:
2
16
10
Output: 
16 11 6 1 -4 1 6 11 16
10 5 0 5 10
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(int res, int n, bool flag)
{
    cout << res << " ";
    if (flag == false && res == n){
        //cout << res << " ";
        return;
    }
    if (flag) {
        if (res-5 > 0) {
            print(res-5, n, true);
        }
        else {
            print(res-5, n, false);
        }
    }
    else
        print(res+5, n, false);
    return;
}

int main() {
	//code
	int t;
	
	cin >> t;
	while (t--) {
	    int n;
	    cin >> n;
	    
	    print(n, n, true);
	    cout << endl;
	}
	return 0;
}