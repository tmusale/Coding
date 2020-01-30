/*
Permutations of a given string

Given a string S. The task is to print all permutations of a given string.

Input:
The first line of input contains an integer T, denoting the number of test cases. Each test case contains a single string S in capital letter.

Output:
For each test case, print all permutations of a given string S with single space and all permutations should be in 
lexicographically increasing order.

Constraints:
1 ≤ T ≤ 10
1 ≤ size of string ≤ 5

Example:
Input:
2
ABC
ABSG

Output:
ABC ACB BAC BCA CAB CBA 
ABGS ABSG AGBS AGSB ASBG ASGB BAGS BASG BGAS BGSA BSAG BSGA GABS GASB GBAS GBSA GSAB GSBA SABG SAGB SBAG SBGA SGAB SGBA

Explanation:
Testcase 1: Given string ABC has permutations in 6 forms as ABC, ACB, BAC, BCA, CAB and CBA .
*/

#include <bits/stdc++.h>
using namespace std;

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(char *str, int start, int end, vector<string> *s)
{
    if (start == end) {
        //cout << str << " ";
        (*s).push_back(str);
    }
    else {
        for (int i = start; i <= end; i++) {
            swap(&str[start], &str[i]);
            permutation(str, start+1, end, s);
            swap(&str[start], &str[i]);
        }
    }
}

int main() {
	//code
	int t;
	//string str;
	
	cin >> t;
	while (t--) {
	    char str[10];
	    cin >> str;
	    
	    vector<string> s;
	    permutation(str, 0, strlen(str)-1, &s);
	    sort(s.begin(), s.end());
	    for (auto i = s.begin(); i != s.end(); i++) {
	        cout << *i << " ";
	    }
	    cout << endl;
	}
	
	return 0;
}