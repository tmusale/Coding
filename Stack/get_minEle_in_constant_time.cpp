/*
Get minimum element from stack
You are given N elements and your task is to Implement a Stack in which you can get minimum element in O(1) time.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow. 
First line of each test case contains an integer Q denoting the number of queries.
A Query Q may be of 3 Types:
    1. 1 x (a query of this type means  pushing 'x' into the stack)
    2. 2 (a query of this type means to pop element from stack and print the poped element)
    3. 3 (a query of this type means to print the minimum element from the stack)
The second line of each test case contains Q queries seperated by space.

Output:
The output for each test case will  be space separated integers having -1 if the stack is empty else the 
element poped out  or min element from the stack.

User Task:
You are required to complete the three methods push() which take one argument an integer 'x' to be pushed 
into the stack, pop() which returns a integer poped out from the stack and getMin() which returns the min element from the stack.

Constraints:
1 <= T <= 100
1 <= Q <= 100
1 <= x <= 100

Example:
Input:
1
6
1 2 1 3 2 3 1 1 3   

Output:
3 2 1

Explanation:
Testcase 1:
In the first test case for query 
1 2  the stack will be {2}
1 3  the stack will be {2 3}
2 poped element will be 3 the stack will be {2}
3 min element will be 2 
1 1 the stack will be {2 1}
3 min element will be 1 and
*/

{
#include<bits/stdc++.h>
using namespace std;
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int q;
       cin>>q;
        _stack *a = new _stack();
       while(q--){
       int qt;
       cin>>qt;
       if(qt==1)
       {
           //push
           int att;
           cin>>att;
           a->push(att);
       }
       else if(qt==2)
       {
           //pop
           cout<<a->pop()<<" ";
       }
       else if(qt==3)
       {
           //getMin
           cout<<a->getMin()<<" ";
       }
       }
       cout<<endl;
   }
}

}
/*This is a function problem.You only need to complete the function given below*/
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/
/*returns min element from stack*/
int _stack :: getMin()
{
   //Your code here
   if (s.empty()) {
       return -1;
   }
   
   return minEle;
}
/*returns poped element from stack*/
int _stack ::pop()
{
   //Your code here
   if (s.empty()) {
       return -1;
   }
   int temp;
   if (s.top() <minEle) {
       temp = minEle;
       minEle = minEle - s.top();
   }
   else {
       temp = s.top();
   }
   s.pop();
   
   return temp;
}
/*push element x into the stack*/
void _stack::push(int x)
{
   //Your code here
   if (s.empty()) {
       s.push(x);
       minEle = x;
       return;
   }
   if (x > minEle) {
       s.push(x);
   }
   else {
       s.push(x-minEle);
       minEle = x;
   }
}
