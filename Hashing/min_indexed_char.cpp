/*
Minimum indexed character

Given a string str and another string patt. Find the character in patt that is present at the minimum index in str. If no character of patt 
is present in str then print ‘No character present’.

Input:
The first line of input contains an integer T denoting the number of test cases. Then the description of T test cases follow. Each test 
case contains two strings str and patt respectively.

Output:
Output the character in patt that is present at the minimum index in str. Print "$" (without quotes) if no character of patt is present in str.

Constraints:
1 <= T <= 105
1 <= |str|, |patt| <= 105

Example:
Input:
2
geeksforgeeks
set
adcffaet
onkl

Output:
e
$

Explanation:
Testcase 1: e is the character which is present in given patt "geeksforgeeks" and is first found in str "set".
*/

#include <bits/stdc++.h>
using namespace std;

void min_index_char(string str, string patt)
{
    unordered_map<char, int> hash;
    for (int i = 0; str[i] != '\0'; i++) {
        hash.insert({str[i], i});
    }
    int min = INT_MAX;
    int flag = 1;
    for (int i = 0; patt[i] != '\0'; i++) {
        if (hash.find(patt[i]) != hash.end()) {
            if (hash[patt[i]] < min) {
                min = hash[patt[i]];
                flag = 0;
            }
        }
    }
    if (flag) {
        cout << '$' << endl;
    }
    else {
        cout << str[min] << endl;
    }
}

int main() {
	//code
	int t;
	string str;
	string patt;
	
	cin >> t;
	while (t--) {
	    cin >> str;
	    cin >> patt;
	    
	    min_index_char(str, patt);
	    
	}
	return 0;
}