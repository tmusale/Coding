/*
Rightmost different bit
Given two numbers M and N. The task is to find the position of rightmost different bit in binary representation of numbers.

Input:
The input line contains T, denoting the number of testcases. Each testcase follows. First line of each testcase contains two space separated integers M and N.

Output:
For each testcase in new line, print the position of rightmost different bit in binary representation of numbers. If both M and N are same then print -1 in this case.

Constraints:
1 <= T <= 100
1 <= M <= 103
1 <= N <= 103

Example:
Input:
2
11 9
52 4

Output:
2
5

Explanation:
Tescase 1: Binary representaion of the given numbers are: 1011 and 1001, 2nd bit from right is different.
*/

#include <iostream>
#include <vector>
using namespace std;

void diff(int m, int n)
{
    vector<int> v;
    
    int res = m ^ n;
    //cout << res;
    while (res > 0) {
        if ((res%2) == 0) {
            v.push_back(0);
        }
        else {
            v.push_back(1);
        }
        res = res/2;
    }
    int k = 1;
    for (auto i = v.begin(); i != v.end(); i++) {
        //cout << *i;
        if ((*i) == 1) {
            break;
        }
        k++;
    }
    cout << k;
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
	    diff(m, n);
	    cout << endl;
	}
	return 0;
}