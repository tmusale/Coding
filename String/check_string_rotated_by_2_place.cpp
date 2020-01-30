/*
Check if string is rotated by two places

Given two strings a and b. The task is to find if a string 'a' can be obtained by rotating another string 'b' by 2 places.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. In the next two line are two string a and b.

Output:
For each test case in a new line print 1 if the string 'a' can be obtained by rotating string 'b' by two places else print 0.

Constraints:
1 <= T <= 50
1 <= length of a, b < 100

Example:
Input:
2
amazon
azonam
geeksforgeeks
geeksgeeksfor

Output:
1
0

Explanation:
Testcase 1: amazon can be rotated anti-clockwise by two places, which will make it as azonam.

Testcase 2: geeksgeeksfor can't be formed by any rotation from the given word geeksforgeeks.
*/

#include <bits/stdc++.h>
using namespace std;

int check_rotated(string str1, string str2)
{
    if (str1.length() != str2.length()) {
        return 0;
    }
    string cloc = "";
	string anti_clock = "";
	int len = str1.length();
	    
	anti_clock = anti_clock + str2.substr(len-2, 2) + str2.substr(0, len-2);
	
	cloc = cloc + str2.substr(2) + str2.substr(0, 2);
	
	return (str1.compare(cloc) == 0 || str1.compare(anti_clock) == 0);
}

int main() {
	//code
	int t;
	string str1;
	string str2;
	
	cin >> t;
	while (t--) {
	    cin >> str1;
	    cin >> str2;
	    
	    cout << check_rotated(str1, str2) << endl;
	    
	    
	}
	return 0;
}