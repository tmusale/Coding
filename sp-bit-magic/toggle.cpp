/*
Toggle bits given range
Given a non-negative number N and two values L and R. 
The problem is to toggle the bits in the range L to R in the binary representation of N, 
i.e, to toggle bits from the rightmost Lth bit to the rightmost Rth bit. A toggle operation flips a bit 0 to 1 and a bit 1 to 0.

Input:
First line of input contains a single integer T which denotes the number of test cases. 
Then T test cases follows. First line of each test case contains three space separated integers N, L and R.

Output:
For each test case , print the number obtained by toggling bits from the rightmost Lth bit 
to the rightmost Rth bit in binary representation of N.

Constraints:
1<=T<=100
1<=N<=1000
1<=L<=R
L<=R<= Number of bits(N)

Example:
Input:
2
17 2 3
50 2 5
Output:
23
44
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void toggle(int n, int l, int r)
{
    vector<int> v;
    while (n > 0) {
        if ((n%2) == 0) {
            v.push_back(0);
        }
        else if ((n%2) != 0) {
            v.push_back(1);
        }
        n = n/2;
    }
    
    for (int i = 0; i < v.size(); i++) {
        if ((i >= (l-1)) && (i <= (r-1))) {
            if (v[i] == 0) {
                v[i] = 1;
            }
            else {
                v[i] = 0;
            }
        }
    }
    int sum = 0;
    int k = 0;
    for (auto i = v.begin(); i != v.end(); i++){
        //cout << *i;
        sum += (*i) * pow(2.0, (k));
        k++;
    }
    cout << sum;
}

int main() {
    //code
    int t;
    int n;
    int l;
    int r;
    
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> l;
        cin >> r;
        
        toggle(n, l, r);
        cout << endl;
    }
    return 0;
}