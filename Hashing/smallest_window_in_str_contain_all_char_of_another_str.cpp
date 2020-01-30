/*
Smallest window in a string containing all the characters of another string

Given a string S and text T. Output the smallest window in the string S having all characters of the text T. Both the string S and text T 
contains lowercase english alphabets.

Input:
First line of the input contains an integer T, denoting the number of test cases. Then T test case follows. Each test contains 2 lines 
having a string S and next line contains text T.

Output:
Output the smallest window of the string containing all the characters of the text. If such window doesn`t exist or this task can not be 
done then print -1.

Constraints: 
1 <= T <= 100
1 <= |N|, |X| <= 1000

Example:
Input:
2
timetopractice
toc
zoomlazapzo
oza

Output:
toprac
apzo

Explanation:
Testcase 1: "toprac" is the smallest substring in the given string S which contains every characters of T.
*/

#include <bits/stdc++.h>
using namespace std;

string find_window(string str, string pat)
{
    int len1 = str.length();
    int len2 = pat.length();
    string res;
    
    if (len1 < len2) {
        res = "-1";
        return res;
    }
    
    unordered_map<char, int> hash_str;
    unordered_map<char, int> hash_pat;
    
    int start = 0;
    int start_index = -1;
    int min_len = INT_MAX;
    
    for (int i = 0; i < len2; i++) {
        hash_pat[pat[i]]++;
    }
    int count = 0;
    
    for (int i = 0; i < len1; i++) {
        hash_str[str[i]]++;
        
        if (hash_pat.find(str[i]) != hash_pat.end()) {
            if (hash_str[str[i]] <= hash_pat[str[i]]) {
                count++;
            }
        }
        
        if (count == len2) {
            while (hash_str[str[start]] > hash_pat[str[start]] || hash_pat.find(str[start]) == hash_pat.end()) {
                if (hash_str[str[start]] > hash_pat[str[start]]) {
                    hash_str[str[start]]--;
                }
                start++;
            }
            
            int window = i - start + 1;
            if (window < min_len) {
                min_len = window;
                start_index = start;
            }
        }
    }
    if (start_index == -1) {
        res = "-1";
        return res;
    }
    res = str.substr(start_index, min_len);
    
    return res;
}

int main() {
	//code
	int t;
	string str;
	string pat;
	
	cin >> t;
	while (t--) {
	    cin >> str;
	    cin >> pat;
	    
	    cout << find_window(str, pat) << endl;
	}
	return 0;
}