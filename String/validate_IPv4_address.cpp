/*
Validate an IP Address

Write a program to Validate an IPv4 Address. According to Wikipedia, IPv4 addresses 
are canonically represented in dot-decimal notation, which consists of four decimal numbers, 
each ranging from 0 to 255, separated by dots, e.g., 172.16.254.1 . The generalized form of 
an IPv4 address is (0-255).(0-255).(0-255).(0-255). Here we are considering numbers only from 
0 to 255 and any additional leading zeroes will be considered invalid.

Your task is  to complete the function isValid which returns 1 if the ip address is valid else returns 0. 
The function takes a string ip as its only argument .

Input:
The first line of each test case contains an integer T denoting the number of test case . 
Then T test cases follow . Each test case takes a string ip.

Output:
For each test case output will be 1 if the string is a valid ip address else 0.

Constraints:
1<=T<=100
1<=length of string <=50

Example(To be used only for expected output) :
Input
4
222.111.111.111
5555..555
0000.0000.0000.0000
1.2.3.04

Output
1
0
0
0

Note:The Input/Ouput format and Example given are used for system's internal purpose, 
and should be used by a user for Expected Output only. As it is a function problem, 
hence a user should not read any input from stdin/console. The task is to complete 
the function specified, and not to write the full code.
*/


#include <bits/stdc++.h>
using namespace std;
int isValid(char *);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		char s[10000];
		cin>>s;
		cout<<isValid(s)<<endl;
	}
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* The function returns 1 if 
IP string is valid else return 0 
You are required to complete this method */
int isValid(char *ip)
{
      //your code here
      int num;
      int dots = 0;
      char *ptr;
      
      if (ip == NULL) {
          return 0;
      }
      
      for (int i = 0; i < strlen(ip); i++) {
          if (ip[i] == '.') {
              dots++;
          }
      }
      
      if (dots != 3) {
          return 0;
      }
      
      dots = 0;
      ptr = strtok(ip, ".");
      
      if (ptr == NULL) {
          return 0;
      }
      
      while (ptr) {
         int i = 0;
         
         if (ptr == "") {
             return 0;
         }
         
         if (strlen(ptr) > 1) {
             if (ptr[0] == '0') {
                 return 0;
             }
         }
         
         //int i = 0;
         while (i < strlen(ptr)) {
             if (ptr[i] == '0' && ptr[i+1] == '0') {
                 return 0;
             }
             else if (ptr[i] >= '0' && ptr[i] <= '9' ){
                 //return 0;
             }
             else {
                 return 0;
             }
             i++;
         }
         
         num = atoi(ptr);
         //cout << num << endl;
         if ((num >= 0) && (num <= 255)) {
             ptr = strtok(NULL, ".");
             
             if (ptr != NULL) {
                 dots++;
             }
         }
         else {
             return 0;
         }
      }
      
      if (dots != 3) {
          return 0;
      }
      
      return 1;
}