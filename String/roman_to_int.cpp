/*
Roman Number to Integer

Given an string in roman no format (s)  your task is to convert it to integer .

Input:
The first line of each test case contains the no of test cases T. Then T test cases follow. Each test case contains a 
string s denoting the roman no.

Output:
For each test case in a new line print the integer representation of roman number s. 

Constraints:
1<=T<=100
1<=roman no range<4000

Example:
Input
2
V
III 
Output
5
3
*/

#include <bits/stdc++.h>
using namespace std;

int value(char s)
{
    if (s == 'I') {
        return 1;
    }
    if (s == 'V') {
        return 5;
    }
    if (s == 'X') {
        return 10;
    }
    if (s == 'L') {
        return 50;
    }
    if (s == 'C') {
        return 100;
    }
    if (s == 'D') {
        return 500;
    }
    if (s == 'M') {
        return 1000;
    }
    
    return -1;
}

int main() {
	//code
	int t;
	string str;
	
	cin >> t;
	while (t--) {
	    cin >> str;
	    int num = 0;
	    
	    for (int i = 0; i < str.length(); i++) {
	        int s1 = value(str[i]);
	        
	        if (i+1 < str.length()) {
	            int s2 = value(str[i+1]);
	            
	            if (s1 < s2) {
	                num += s2 - s1;
	                i++;
	            }
	            else {
	                num += s1;
	            }
	        }
	        else {
	            num += s1;
	            i++;
	        }
	    }
	    
	    cout << num << endl;
	}
	return 0;
}