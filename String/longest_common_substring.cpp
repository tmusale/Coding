/*
Longest Common Substring
Given two strings X and Y. The task is to find the length of the longest common substring.

Input:
First line of the input contains number of test cases T. Each test case consist of three lines, first of which contains 
2 space separated integers N and M denoting the size of string X and Y strings respectively. The next two lines contains the string X and Y.

Output:
For each test case print the length of longest  common substring of the two strings .

Constraints:
1 <= T <= 200
1 <= N, M <= 100

Example:
Input:
2
6 6
ABCDGH
ACDGHR
3 2
ABC
AC

Output:
4
1

Example:
Testcase 1: CDGH is the longest substring present in both of the strings.
*/

#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return a>b ? a : b;
}

int lcs(char str1[],char str2[], int n, int m)
{
    int dp[n+1][m+1];
    int result = 0;
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (str1[i-1] == str2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                result = max(result, dp[i][j]);
                
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    return result;
}

int main() {
	//code
	int t;
	int n;
	int m;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    cin >> m;
	    char str1[n];
	    char str2[m];
	    cin >> str1;
	    cin >> str2;
	    
	    int count = 0;
	    int res = lcs(str1, str2, n, m);
	    cout << res << endl;
	}
	
	return 0;
}