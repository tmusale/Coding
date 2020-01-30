/*
Lazy Pasha

Pasha is a strange guy. He has a string of length N. He wants to perform 2 types of queries on the string.
Type 1- Rotate the string by K character from the end.
Type 2- Print the Character at the I'th index of the resulting string at that Instant.

Now, Pasha wants to perform the 2 types of queries, But he is too lazy to do it himself.
So, you need to help him.
Input:
The first line contains an integer T-denoting the test cases.
The first line of each test cases contains two integers- N (Length of the string) and Q(Number of queries),
The second line contains the String.
Then Each of the next Q lines contains Typ of the query and K or I.
Output:
For each query of Type 2, Output the character at the I'th index in a new line.
Constraints:
1<=T<=10
1<=N<=100000
1<=Q<=10000
1<=TYP<=2
1<=K<=1000000000
0<=I
Example:
Sample Input:
1
7 5
abcdefg
1 2
2 0
2 6
1 4
2 1

Sample output:
f
e
c
Explanation:
After First query String becomes -"fgabcde"
Second query returns - 'f'
Third query returns -'e'
After Fourth Query String becomes- "bcdefga"
Fifth Query returns -'c'
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*string rotate(string str, int d)
{
	//using different approach taking more time
	//here we actually rotate string so take more time of O(n)

    string temp;
    int len = str.length();
    int pos = len - d;
    
    for (int i = pos; str[i] != '\0'; i++) {
        temp.push_back(str[i]);
    }
    
    for (int i = 0; i < pos; i++) {
        temp.push_back(str[i]);
    }
    
    return temp;
}*/

int main() {
	//code
	int t;
	int n;
	int q;
	string str;
	int type_query;
	int d;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    cin >> q;
	    
	    cin >> str;
	    int pos = 0;
	    
	    while (q--) {
	        cin >> type_query;
	        cin >> d;
	        d = d%n;
	        if (type_query == 1) {
	            //str = rotate(str, d);
	            pos += n - d;
	        }
	        else if (type_query == 2) {
	            int loc = (d % n) + pos;
	            loc = loc % n;
	            cout << str[loc] << endl;
	        }
	    }
	}
	return 0;
}