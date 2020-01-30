/*
Remove duplicate element from sorted Linked List

Given a singly linked list consisting of N nodes. The task is to remove duplicates 
(nodes with duplicate values) from the given list (if exists).

Note: Try not to use extra space. Expected time complexity is O(N). The nodes are arranged in a sorted way.

Input:
First line of input contains number of testcases T. For each testcase, first line of 
input contains length of linked list and next line contains the linked list data.

Output:
For each testcase, there will be a single line of output which contains linked list with no duplicates.

User Task:
The task is to complete the function removeDuplicates() which should remove the duplicates from linked list. 
The printing is done automatically by the driver code.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
4
2 2 4 5
5
2 2 2 2 2

Output:
2 4 5
2

Explanation:
Testcase 1: In the given linked list 2 ->2 -> 4-> 5, only 2 occurs more than 1 time.
*/

Node *removeDuplicates(Node *root)
{
 // your code goes here
    unordered_set<int> s;
    
    Node *temp1 = root;
    if (temp1) {
        s.insert(temp1->data);
    }
    
    Node *temp2 = root->next;
    
    while (temp2) {
        if (s.find(temp2->data) != s.end()) {
            Node *del = temp2;
            temp2 = temp2->next;
            temp1->next = temp2;
            free(del);
        }
        else {
            s.insert(temp2->data);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    
    return root;
 
}