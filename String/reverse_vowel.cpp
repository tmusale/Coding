/*
Reversing the vowels
Given a string, reverse only the vowels present in it and print the resulting string.

Input: First line of the input file contains an integer T denoting the number of test cases. 
Then T test cases follow. Each test case has a single line containing a string.

Output: Corresponding to each test case, output the string with vowels reversed.

Example:
Input:
4
geeksforgeeks
practice
wannacry
ransomware

Output:
geeksforgeeks
prectica
wannacry
rensamwora
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void reverse_vowel(string str)
{
    vector<char> vow;
    
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            vow.push_back(str[i]);
        }
    }
    
    int j = vow.size()-1;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            str[i] = vow[j];
            j--;
        }
    }
    
    cout << str << endl;
}

int main()
{
    int t;
    string str;
    
    cin >> t;
    while (t--) {
        cin >> str;
        
        reverse_vowel(str);
        
    }
    return 0;
}

