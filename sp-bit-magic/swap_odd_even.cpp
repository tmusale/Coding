/*
Swap all odd and even bits

Given an unsigned integer N. The task is to swap all odd bits with even bits.
 For example, if the given number is 23 (00010111), it should be converted to 43(00101011). 
 Here, every even position bit is swapped with adjacent bit on right side(even position bits 
 are highlighted in binary representation of 23), and every odd position bit is swapped with adjacent on left side.

Input:
The first line of input contains T, denoting the number of testcases. 
Each testcase contains single line.

Output:
For each testcase in new line, print the converted number.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100

Example:
Input:
2
23
2

Output:
43
1

Explanation:
Testcase 1: BInary representation of the given number; 00010111 after swapping 00101011.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int swap(int n)
{
    vector<int> v(8, -1);
    
    int k = 0;
    while (n > 0) {
        if ((n%2) == 0) {
            v[k] = 0;
        }
        else {
            v[k] = 1;
        }
        n = n / 2;
        k++;
    }
    
    for (int i = 0; i < 8; i++) {
        if (v[i] == -1) {
            v[i] = 0;
        }
    }
    
    for (int i = 0; i < 8; i++) {
        int temp = v[i];
        v[i] = v[i+1];
        v[i+1] = temp;
        i++;
    }
    
    k = 0;
    int res = 0;
    for (int i = 0; i < 8; i++) {
        res += v[i] * pow(2, k);
        k++;
    }
    //for (auto i = v.begin(); i != v.end(); ++i) {
        //cout << *i;
    //}
    //cout << endl;
    return res;
}

int main() {
	//code
	int t;
	int n;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    int res = swap(n);
	    cout << res << endl;
	}
	return 0;
}


/*
OR

from gfg

/ Function to swap even 
// and odd bits 
unsigned int swapBits(unsigned int x) 
{ 
    // Get all even bits of x 
    unsigned int even_bits = x & 0xAAAAAAAA;  
  
    // Get all odd bits of x 
    unsigned int odd_bits  = x & 0x55555555;  
  
    even_bits >>= 1;  // Right shift even bits 
    odd_bits <<= 1;   // Left shift odd bits 
  
    return (even_bits | odd_bits); // Combine even and odd bits 
}
*/