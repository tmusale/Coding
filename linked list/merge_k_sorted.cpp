/*
Merge K sorted linked lists
Given K sorted linked lists of different sizes. The task is to merge them in such a way that 
after merging they will be a single sorted linked list.

Input Format:
First line of input contains number of testcases T. For each testcase, first line of input contains 
number of linked lists N and next line contains data of nodes of all K linked lists, with first element 
as M, the length of linked list and next M elements for the same linked list.

Output Format:
For each testcase, in a new line, print the merged linked list.

Your Task:
The task is to complete the function mergeKList() which merges the K given lists into a sorted one. 
The printing is done automatically by the driver code.

Constraints
1 <= T <= 50
1 <= N <= 103

Example:
Input:
2
4
3 1 2 3 2 4 5 2 5 6 2 7 8
3
2 1 3 3 4 5 6 1 8

Output:
1 2 3 4 5 5 6 7 8
1 2 3 4 5 6 8

Explanation :
Testcase 1: The test case has 4 sorted linked list of size 3, 2, 2, 2
1st    list     1 -> 2-> 3
2nd   list      4->5
3rd    list      5->6
4th    list      7->8
The merged list will be 1->2->3->4->5->5->6->7->8.
*/

Node * merge_sorted_list(Node *head1, Node *head2)
{
    Node *list1 = head1;
    Node *list2 = head2;
    Node *merge = NULL;
    
    if (list1->data <= list2->data) {
        merge = list1;
        list1 = list1->next;
    }
    else {
        merge = list2;
        list2 = list2->next;
    }
    
    Node *temp = merge;
    
    while (list1 && list2) {
        if (list1->data <= list2->data) {
            temp->next = list1;
            
            temp = temp->next;
            list1 = list1->next;
        }
        else {
            temp->next = list2;
            
            temp = temp->next;
            list2 = list2->next;
        }
    }
    
    if (list2 == NULL && list1 != NULL) {
        temp->next = list1;
    }
    
    else if (list1 == NULL && list2 != NULL) {
        temp->next = list2;
    }
    
    return merge;
}
  
Node * mergeKLists(Node *arr[], int N)
{
       // Your code here
       N = N-1;
       while (N) {
           int start = 0;
           int end = N;
           
           while (start < end) {
               arr[start] = merge_sorted_list(arr[start++], arr[end--]);
               
               if (start >= end) {
                   N = end;
               }
           }
       }
       
       return arr[0];
}
