/*
Josephus problem
Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle in a fixed 
direction.​
The task is to choose the safe place in the circle so that when you perform these operations starting from 1st place in the circle, you are 
the last one remaining and survive.

Input Format:
The first line of input contains an integer T denoting the number of test cases . Then T test cases follow. Each test case contains 2 
integers n and k .

Output Format:
For each test case, in a new line, output will be the safe position which satisfies the above condition.

Your Task:
This is a function problem. You are required to complete the function josephus that takes two parameters n and k and returns an integer 
denoting safe position .

Constraints:
1 <= T <= 100
1 <= k, n <= 20

Example:
Input:
2
3 2
5 3
Output
3
4

Explanation:
Testcase 1: There are 3 persons so skipping 1 person i.e 1st person 2nd person will be killed. Thus the safe position is 3.
*/

/*You are required to complete this method */

/*int f(vector<int> &v, int n, int k, int i)
{
    if (v.size() == 1){
        return v[0];
    }
    
    i = (i + (k-1)) % v.size();
    if (i > v.size()) {
        i = i%v.size();
    }
    v.erase(v.begin() + (i));
    
    return f(v, n, k, i);
}*/

int josephus(int n, int k)
{
   //Your code here
   //vector<int> v;
   if (n == 1) {
       return 1;
   }
   else {
       return (josephus(n-1, k) + k-1) % n+1;
   }
   
   /*vector<int> v(n);
   
   for (int i = 0; i < n; i++) {
       v.push_back(i+1);
   }
   
   return f(v, n, k, 0);*/
   
}
