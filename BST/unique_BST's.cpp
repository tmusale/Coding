/*
Unique BST's
Given an integer N, how many structurally unique binary search trees are there that store values 1...N?

Input:
First line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains a single line of input containing N.

Ouput:
For each testcase, in a new line, print the answer.

Constraints:
1<=T<=15
1<=N<=11

Example:
Input:
2
2
3
Output:
2
5

Explanation:

Testcase1:
for N = 2, there are 2 unique BSTs
     1               2  
      \            /
       2         1

Testcase2:
for N = 3, there are 5 possible BSTs
  1              3        3         2      1
    \           /        /           /    \      \
     3        2         1        1    3      2
    /       /                \                      \
   2      1               2                        3
*/

#include <bits/stdc++.h>
using namespace std;

long int catlan(int n, int k)
{
    if (k > (n-k)) {
        k = n-k;
    }
    long int res = 1;
    for (int i = 0; i < k; i++) {
        res *= (n-i);
        res /= (i+1);
    }
    
    return res;
}

int main() {
	//code
	int t;
	int n;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    
	    long int c = catlan(2*n, n);
	    
	    cout << c/(n+1) << endl;
	}
	return 0;
}