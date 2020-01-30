/*
Check if frequencies can be equal

Given a string s which contains lower alphabetic characters, the task is to check if its possible to remove at most one character from 
this string in such a way that frequency of each distinct character becomes same in the string.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains a string s.

Output:
For each test case in a new line print 1 if its possible to make frequencies of all characters equal else print 0.

Constraints:
1 <= T <= 1000
1 <= length of strings <= 10000

Example:
Input:
2
xyyz
xxxxyyzz

Output:
1
0

Explanation:
Testcase 2: It is not possible to make frequency of each character same just by removing at most one character from above string.
 
*/

#include <bits/stdc++.h>
using namespace std;

int checkall(unordered_map<char, int> hash)
{
    auto j = hash.begin();
    int same = (*j).second;
    for (auto i = hash.begin(); i != hash.end(); i++) {
        if ((*i).second != same) {
            return 0;
        }
    }
    
    return 1;
}

int check_freq(string str)
{
    int len = str.length();
    
    unordered_map<char, int> hash;
    
    for (int i = 0; i < len; i++) {
        hash[str[i]]++;
    }
    
    if (checkall(hash)) {
        return 1;
    }
    
    for (char c = 'a'; c <= 'z'; c++) {
        if (hash.find(c) != hash.end()) {
            hash[c]--;
            if (hash[c] == 0) {
                hash.erase(c);
            }
            if (checkall(hash)) {
                return 1;
            }
            hash[c]++;
        }
    }
    
    return 0;
}

int main() 
{
	//code
	int t;
	string str;
	
	cin >> t;
	while (t--) {
	    cin >> str;
	    
	    cout << check_freq(str) << endl;
	    
	}
	return 0;
}