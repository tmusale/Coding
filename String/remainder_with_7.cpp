/*
Remainder with 7
Given a number as string(n) , your task is to complete the function remainderWith7 which 
returns an integer which denotes the remainder of the number when its divided by 7. 

Input:
The first line of input contains an integer T denoting the no of test cases then T test cases follow . 
Each test case contains a number represented as string.

Output:
For each test case in a new line print the remainder when the number is divided by 7.

Constraints:
1<=T<=100
1<=length of n <=300

Example(To be used only for expected output):
Input:
2
5
8
Output:
5
1
*/

{
#include <iostream>
using namespace std;
int remainderWith7(string );
int main() {
	// your code goes here
int t;
cin>>t;
while(t--)
{
string n;
cin>>n;
cout<<remainderWith7(n)<<endl;
}
	return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this method */
int remainderWith7(string n)
{
    //Your code here
    string rem;
    int i = 0;
    while (n[i] != '\0') {
        string temp;
        if (n[i+1] != '\0') {
            temp.push_back(n[0]);
            temp.push_back(n[1]);
            n.erase(0, 2);
        }
        else {
            break;
        }
        int r = stoi(temp);
        //cout << r <<" ";
        r = r%7;
        //rem = itos(r);
        //cout << r <<" ";
        char ch = r + '0';
        n = ch + n;
        //cout << n << " ";
    }
    //cout << n << " ";
    int res = stoi(n);
    res = res % 7;
    return res;
}