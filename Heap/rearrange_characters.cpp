/*
Rearrange characters
Given a string S with repeated characters (only lowercase). The task is to rearrange characters in a string such that no 
two adjacent characters are same.

Note : It may be assumed that the string has only lowercase English alphabets.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
Each test case contains a single line containing a string of lowercase english alphabets.

Output:
For each test case in a new line print "1" (without quotes) if the generated string doesn't contains any same 
adjacent characters, else if no such string is possible to be made print "0" (without quotes).

Constraints:
1 <= T <= 100
1 <= length of string <= 104

Example:
Input:
3
geeksforgeeks
bbbabaaacd
bbbbb

Output:
1
1
0

Explanation:
Testcase 1: All the repeated characters of the given string can be rearranged so that no adjacent characters in the string is equal.
Testcase 3: Repeated characters in the string cannot be rearranged such that there should not be any adjacent repeated character.
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 26;

struct key {
    int freq;
    char ch;
    
    bool operator<(const key &k) const
    {
        return freq < k.freq;
    }
};

void rearrange(string str)
{
    int n = str.length();
    
    int count[MAX] = {0};
    
    for (int i =0; i < n; i++) {
        count[str[i] - 'a']++;
    }
    
    priority_queue<key> pq;
    for (char c = 'a'; c <= 'z'; c++) {
        if (count[c-'a']) {
            pq.push(key {count[c-'a'], c});
        }
    }
    
    str = "";
    
    key prev {-1, '#'};
    
    while (!pq.empty()) {
        key k = pq.top();
        pq.pop();
        
        str = str + k.ch;
        
        if (prev.freq > 0) {
            pq.push(prev);
        }
        
        (k.freq)--;
        prev = k;
    }
    if (n != str.length()) {
        cout << 0 << endl;
    }
    else {
        cout << 1 << endl;
    }
}

int main() {
	//code
	int t;
	
	cin >> t;
	while (t--) {
	    string str;
	    cin >> str;
	    
	    rearrange(str);
	}
	return 0;
}