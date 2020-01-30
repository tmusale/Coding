/*
Implement Atoi

Your task  is to implement the function atoi. The function takes a string(str) as argument and converts it to an integer and returns it.
 
Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. 
Each test case contains a string str .

Output:
For each test case in a new line output will be an integer denoting the converted integer, if the input string is not 
a numerical string then output will be -1.
 
Constraints:
1<=T<=100
1<=length of (s,x)<=10

Example(To be used only for expected output) :
Input:
2
123
21a

Output:
123
-1

*/

/*You are required to complete this method */
int atoi(string str)
{
    //Your code here
    int num = 0;
    
    int j = 0;
    int n= str.length();
    for (int i= n-1; i >= 0; i--) {
        if (str[i] >= '0' && str[i] <= '9') {
            int temp = str[i] - '0';
            num += temp * pow(10, j);
            j++;
        }
        else if (str[i] == '-') {
            num = num * (-1);
        }
        else {
            return -1;
        }
    }
    return num;
}