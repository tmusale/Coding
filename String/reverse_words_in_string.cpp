/*
Reverse words in a given string

Given a String of length S, reverse the whole string without reversing the individual words in it. Words are separated by dots.

Input:
The first line contains T denoting the number of testcases. T testcases follow. Each case contains a string S containing characters.

Output:
For each test case, in a new line, output a single line containing the reversed String.

Constraints:
1 <= T <= 100
1 <= |S| <= 2000

Example:
Input:
2
i.like.this.program.very.much
pqr.mno

Output:
much.very.program.this.like.i
mno.pqr
*/

#include <bits/stdc++.h>
using namespace std;

void reverse_words(string str)
{
    vector<string> v;
    
    int i = 0;
    while (i < str.length() && str[i]) {
        string temp = "";
        while (str[i] != '.' && str[i]) {
            temp.push_back(str[i]);
            i++;
        }
        v.push_back(temp);
        i++;
    }
    
    //cout << str;
    
    for (int j = v.size()-1; j > 0; j--) {
        cout << v[j] <<".";
    }
    cout << v[0];
}

int main() {
	//code
	int t;
	string str;
	
	cin >> t;
	while (t--) {
	    cin >> str;
	    
	    reverse_words(str);
	    cout <<endl;
	}
	return 0;
}