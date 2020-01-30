/*
Lucky Number

A n digit number has n*(n+1)/2 sub-numbers.  For example, all possible sub-numbers of 975 are 9 7 5 97 75 975. 
A number is called Lucky if all sub-numbers have different digit product.  Digit product of a number is product of its digits.  

For example, the number 23 is Lucky.  Subsequences of it are 2, 3 and 23 and digit products are 2, 3 and 6 
respectively (All digit products are different). 975 is also lucky.

 

Input:

The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains an integer N .
Output:

Print 1 if number is lucky else print 0.

Constraints:

1<=T<=100

1<=N<=1010
Example:

Input:

2
324
323

Output:

1
0
*/

#include <bits/stdc++.h>
using namespace std;

int check(vector<int> v)
{
    unordered_set<int> s;
    
    for (int i = 0; i < v.size(); i++) {
        int prod = 1;
        if (i > 0) {
            if (s.find(v[i]) != s.end()) {
                return 0;
            }
            else {
                s.insert(v[i]);
            }
        }
        for (int j = 0; j <= i; j++) {
            prod = prod * v[j];
        }
        if (s.find(prod) != s.end()) {
            return 0;
        }
        else {
            s.insert(prod);
        }
    }
    
    return 1;
}

void lucky_number(long long int n)
{
    vector<int> v;
    while (n > 0) {
        int temp = n % 10;
        v.push_back(temp);
        n = n / 10;
    }
    
    cout << check(v);
}

int main() {
	//code
	int t;
	long long int n;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    
	    lucky_number(n);
	    cout << endl;
	}
	return 0;
}