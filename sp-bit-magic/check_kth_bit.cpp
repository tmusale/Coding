/*
Check whether K-th bit is set or not
Given a number N and a bit number K, check if Kth bit of N is set or not. 
A bit is called set if it is 1. Position of set bit '1' should be indexed starting 
with 0 from LSB side in binary representation of the number. Consider N = 4(100):  0th bit = 0, 1st bit = 0, 2nd bit = 1.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. Each test case consists of two lines. The first line of
 each test case contain an integer  N. The second line of each test case contains an integer  K.

Output:
Corresponding to each test case, print "Yes" (without quotes) if Kth  bit is set else print "No" (without quotes) in a new line.

Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 109
0 ≤ K ≤ floor(log2(N) + 1)

Example:
Input:
3
4
0
4
2
500
3

Output:
No
Yes
No

Explanation:
Testcase 1: Binary representation of 4 is 100, in which 0th bit from LSB is not set. So, answer is No.
 
*/

#include <iostream>
#include <vector>
using namespace std;

void check(int n, int k)
{
    vector<int> v;
    while (n > 0) {
        if ((n%2) == 0) {
            v.push_back(0);
        }
        else {
            v.push_back(1);
        }
        n = n/2;
    }
    
    //for (auto i = v.begin(); i != v.end(); i++){
    //    cout << *i;
    //}
    
    if (v[k] == 1) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
}

int main() {
	//code
	int t;
	int n;
	int k;
	
	cin >> t;
	while (t--){
	    cin >> n;
	    cin >> k;
	    check(n, k);
	    cout << endl;
	}
	return 0;
}