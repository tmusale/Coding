/*
Convert to Roman No
Given an integer n your task is to complete the function convertToRoman 
which prints the corresponding roman number of n .

Input:
The first line of each test case contains the no of test cases T. Then T test cases follow. 
Each test case contains a single integer n.

Output:
For each test case in a new line output will be the roman number representation of n. 

Constraints:
1<=T<=100
1<=n<4000

Example:
Input
2
5
3
Output
V
III 
*/

#include <bits/stdc++.h>
using namespace std;
void convertToRoman(int ) ;
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		
	convertToRoman(N);
	cout<<endl;
		
	}
	return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
/*you are required to complete 
this function*/
void convertToRoman(int n) 
{
//Your code here
    vector<string> result;
    int ones = n %10;
    n = n / 10;
    string onestr[10] = { "", "I", "II","III","IV","V","VI","VII","VIII","IX"};
    result.push_back(onestr[ones]);
    
    int ten = n % 10;
    n = n / 10;
    string tenstr[10] = { "", "X", "XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    result.push_back(tenstr[ten]);
    
    int hundred = n % 10;
    n = n / 10;
    string hundredstr[10] = { "", "C", "CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    result.push_back(hundredstr[hundred]);
    
    int thousand = n % 10;
    n = n / 10;
    string thousandstr[10] = { "", "M", "MM","MMM","MV","V","VM","VMM","VMMM","MX"};
    result.push_back(thousandstr[thousand]);
    
    for (auto i = result.rbegin(); i != result.rend(); i++) {
        cout << *i;
    }
    