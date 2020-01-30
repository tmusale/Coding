/*
Uncommon characters

Find and print the uncommon characters of the two given strings S1 and S2. Here uncommon character means that either the character is 
present in one string or it is present in other string but not in both. The strings contains only lowercase characters and can contain 
duplicates.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two 
strings in two subsequent lines.

Output:
For each testcase, in a new line, print the uncommon characters of the two given strings in sorted order.

Constraints:
1 <= T <= 100
1 <= |S1|, |S2| <= 105

Example:
Input:
1
characters
alphabets
Output:
bclpr
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	string str1;
	string str2;
	
	cin >> t;
	while (t--) {
	    cin >> str1;
	    cin >> str2;
	    
	    map<char, int> hash;
	    sort(str1.begin(), str1.end());
	    sort(str2.begin(), str2.end());
	    hash[str1[0]]++;
	    for (int i = 1; str1[i] != '\0'; i++) {
	        if (str1[i] != str1[i-1]) {
	            hash[str1[i]]++;
	        }
	    }
	    
	    hash[str2[0]]++;
	    for (int i = 1; str2[i] != '\0'; i++) {
	        if (str2[i] != str2[i-1]) {
	            hash[str2[i]]++;
	        }
	    }
	    
	    for (auto i = hash.begin(); i != hash.end(); i++) {
	        if ((*i).second == 1) {
	            cout << (*i).first;
	        }
	    }
	    
	    cout << endl;
	}
	return 0;
}