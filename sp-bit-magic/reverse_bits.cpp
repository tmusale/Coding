/*
Reverse Bits
Given a 32 bit number x, reverse its binary form and print the answer in decimal.

Input:
The first line of input consists T denoting the number of test cases. 
T testcases follow. Each test case contains a single 32 bit integer

Output:
For each test case, in a new line, print the reverse of integer.

Constraints:
1 <= T <= 100
0 <= x <= 4294967295

Example:
Input:
2
1
5
Output:
2147483648
2684354560

Explanation:
Testcase1:
00000000000000000000000000000001 =1
10000000000000000000000000000000 =2147483648
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void reverse_number(int n)
{
    vector<int> v(32, -1);
    long long int ans;
    
    int k = 0;
    while (n > 0) {
        if ((n%2) == 0) {
            v[k] = 0;
        }
        else {
            v[k] = 1;
        }
        k++;
        n = n / 2;
    }
    
    for (int i = 0; i < 32; i++) {
        if (v[i] == -1) {
            v[i] = 0;
        }
    }
    
    //for (int i = 0; i < 32; i++) {
        //cout << v[i];
    //}
    
    k = 0;
    ans = 0;
    for (int i = 31; i >= 0; --i) {
        ans += v[i] * pow(2, k);
        k++;
    }
    
    cout << ans;
    
    
    
    
}

int main() {
	//code
	int t;
	int n;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    reverse_number(n);
	    cout << endl;
	}
	return 0;
}