
/*
Is Binary Number Multiple of 3
Given a binary number, write a program that prints 1 if given binary number is a multiple of 3. 
 Else prints 0. The given number can be big upto 2^100. It is recommended to finish the task using one traversal of input binary string.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases. 
Each case contains a string containing 0's and 1's.

Output:
For each test case, output a 1 if string is multiple of 3, else 0.

Constraints:
1<=T<=100
1<=Length of Input String<=100

Example:
Input:
2
011
100

Output:
1
0

logic:
Just count the even places where the bit is set and odd places where the bit is set.
if abs(odd-even)%3==0 then the number is divisible. :)
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	string str;
	
	cin >> t;
	while (t--) {
	    //getline(cin, str);
	    cin >> str;
	    //cout << str << endl;
	    int size = str.size();
	    
	    int k = 0;
	    int even_count = 0;
	    int odd_count = 0;
	    for (int i = size-1; i >= 0; --i) {
	        if ((str[i] == '1') && ((k%2) == 0)) {
	            even_count++;
	        }
	        else if ((str[i] == '1') && ((k%2) != 0)) {
	            odd_count++;
	        }
	        k++;
	    }
	    int sub = abs(even_count - odd_count);
	    if ((sub%3) == 0) {
	        cout << "1";
	    }
	    else {
	        cout << "0";
	    }
	    cout << endl;
	}
	return 0;
}