/*
Number is sparse or not
Given a number N, check whether it is sparse or not. A number is said to be a sparse number 
if in the binary representation of the number no two or more consecutive bits are set.

Input:
The first line of input contains an integer T denoting the number of test cases. 
The first line of each test case is number 'N'.

Output:
Print '1' if the number is sparse and '0' if the number is not sparse.

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input:
2
2
3

Output:
1
0

Explanation:
Testcase 1: Binary Representation of 2 is 10, which is not having consecutive set bits. So, it is sparse number.
Testcase 2: Binary Representation of 3 is 11, which is having consecutive set bits in it. So, it is not a sparse number.
*/

#include <iostream>
#include <vector>
using namespace std;

void check_parse(int n)
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
    int flag = 0;
    for(auto i = v.begin(); i != v.end(); i++) {
        //cout << *i;
    }
    //cout << endl;
    for (int i = 0; i < v.size()-1; i++) {
        if ((v[i] == 1) && (v[i+1] == 1)) {
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
    v.clear();
}

int main() {
	//code
	int t;
	int n;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    check_parse(n);
	    cout << endl;
	}
	return 0;
}