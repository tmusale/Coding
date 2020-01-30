/*
Arya's Long String

Arya has a string, S, of uppercase English letters. She writes down the string S on a paper K times.
She wants to calculate the occurence of a specific letter in the first N characters of the final string.

Input:

First line of input contains a single integer T denoting the number of test cases.
The first line of each test case contains a string S.
The second line contains 2 space-separated integers K and N, and an uppercase English letter C whose occurence needs to be counted.

Output:

For each test case, print the required answer in a new line.


Constraints:

1 <= T <= 150
1 <= |S| <= 500
1 <= K <= 10^5
1 <= N <= |S|*K


Example:

Input : 
2
ABA
3 7 B
BHD
4 6 E
Output : 
2
0

Explaination : 
Case 1 : Final string - ABAABAABA
Case 2 : Final string - BHDBHDBHDBHD

Example 2 :
Input : 
1
MMM
2 4 M
Output :
4

Explaination : 
Case 1 : Final string - MMMMMM

idea = We need to count the occurences of a certain character in a repeated string.
So first we count the occurence of that character in the original string and multiply that count with N/|S|.
Now we have the count of the character till ( N/|S|*N).
For example .. for 
ABA
3 7 B

B occurs 1 time.
For ABAABA ABA
Count = 1 * ( 7 / 3 ) = 2  [ till (N/|S|*|S|) = 6 ]

Now for the next N%|S| length .. 
We check the original string till N%|S| index and count the occurenes of the desired character and add it up to 'count';
We get the desired answer.



*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void long_string(string s, int k, int n, char c)
{
    int c_count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            c_count++;
        }
    }
    
    int len = s.length();
    int q = n / len;
    int r = n % len;
    
    int res;
    res = c_count * q;
    
    int r_count = 0;
    
    for (int i = 0; i < r; i++) {
        if (s[i] == c) {
            r_count++;
        }
    }
    
    res = res + r_count;
    
    cout << res << endl;
}

int main() {
	//code
	int t;
	string s;
	int k;
	int n;
	char c;
	
	cin >> t;
	while (t--) {
	    cin >> s;
	    cin >> k;
	    cin >> n;
	    cin >> c;
	    
	    long_string(s, k, n, c);
	}
	return 0;
}