/*
Linked List Length Even or Odd?

Given a linked list of size N, your task is to complete the function isLengthEvenOrOdd() 
which contains head of the linked list and check whether the length of linked list is even or odd.

Input:
The input line contains T, denoting the number of testcases. Each testcase contains two lines. 
the first line contains N(size of the linked list). the second line contains N elements of the linked list separated by space.

Output:
For each testcase in new line, print "even"(without quotes) if the length is even else "odd"(without quotes) if the length is odd.

User Task:
Since this is a functional problem you don't have to worry about input, you just have to  complete the function isLengthEvenOrOdd().

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= A[i] <= 103

Example:
Input:
2
3
9 4 3
6
12 52 10 47 95 0

Output:
Odd
Even
*/

{
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node* next;
};
// Function to check the length of linklist
int isLengthEvenOrOdd(struct Node* head);
	
// Push function
void push(struct Node** head, int info)
{
	struct Node* node = (struct Node*) malloc(sizeof(struct Node));
	node->data = info;
	node->next = (*head);
	(*head) = node;
}
// Driver function
int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,tmp;
        struct Node* head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            push(&head, tmp);
        }
        if( isLengthEvenOrOdd(head) == 0) cout<<"Even
";
        else cout<<"Odd
";
    }
	return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/*structure of a node of the linked list is as
struct Node
{
	int data;
	struct Node* next;
};
*/
// Function should return 0 is length is even else return 1
int isLengthEvenOrOdd(struct Node* head)
{
     //Code here
     
     int length = 0;
     
     while (head) {
         length++;
         head = head->next;
     }
     
     if ((length%2) == 0) {
         return 0;
     }
     
     return 1;
}