/*
Given a linked list of 0s, 1s and 2s, sort it.

Given a linked list of N nodes where nodes can contain values 0s, 1s and 2s only. 
The task is to segregate 0s, 1s and 2s linked list such that all zeros segregate to headside, 
2s at the end of the linked list and 1s in the mid of 0s and 2s.

Input Format:
First line of input contains number of testcases T. For each testcase, first line 
of input contains length of linked list and next line contains N elements as the data in the linked list.

Output Format:
For each testcase, segregate the 0s, 1s and 2s and display the linked list.

Your Task:
The task is to complete the function segregate() which segregate the nodes in 
the linked list as asked in the problem statement. The printing is done automatically by the driver code.

Constraints:
1 <= T <= 100
1 <= N <= 103

User Task:
The task is to complete the function sortList() which takes head reference as the argument and returns void.

Example:
Input:
2
8
1 2 2 1 2 0 2 2
4
2 2 0 1

Output:
0 1 1 2 2 2 2 2
0 1 2 2

Explanation:
Testcase 1: All the 0s are segregated to left end of the linked list, 2s to the right end of the list and 1s in between.


*/

Node* segregate(Node *head) {
    
    // Add code here
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    
    Node *temp = head;
    
    while (temp) {
        if (temp->data == 0) {
            count0++;
        }
        else if(temp->data == 1) {
            count1++;
        }
        else {
            count2++;
        }
        temp = temp->next;
    }
    
    temp = head;
    
    while (count0--) {
        temp->data = 0;
        temp = temp->next;
    }
    
    while (count1--) {
        temp->data = 1;
        temp = temp->next;
    }
    
    while (count2--) {
        temp->data = 2;
        temp = temp->next;
    }
    
    
    return head;
}
