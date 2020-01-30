/*
Linked List Insertion

Given a key (or data) to be inserted into the linked list of size N. 
The task is to insert the element at head or tail of the linked list depending on 
the input just before it p. If p is 0, then insert the element at beginning else insert at end.

Hint : When inserting at the end, make sure that you handle NULL explicitly.

Input Format:
First line of input contains number of testcases T. For each testcase, first line of 
input contains length of linked list N and next line contains 2*N integers, each element 
to be inserted into the list is preceded by a 0 or 1 which decide the place to be inserted.

Output Format:
For each testcase, there will be a single line of output which contains the linked list elements.

Your Task:
This is a function problem. You only need to complete the functions insertAtBeginning and insertAtEnd 
that returns head after successful insertion. The printing is done automatically by the driver code.

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input:
3
5
9 0 5 1 6 1 2 0 5 0
3
5 1 6 1 9 1
4
15 0 36 0 95 0 14 0

Output:
5 2 9 5 6
5 6 9
14 95 36 15

Explanation:
Testcase 1: After inserting the elements at required position, we have linked list as 5, 2, 9, 5, 6.
*/

/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */
// function inserts the data in front of the list
Node *insertAtBegining(Node *head, int newData) {
   // Your code here
   Node *newnode = (Node *)malloc(sizeof(Node));
   newnode->data = newData;
   newnode->next = NULL;
    
    if (head == NULL) {
        head = newnode;
        return head;
    }
    
    newnode->next = head;
    head = newnode;
    
    return head;
}
// function appends the data at the end of the list
Node *insertAtEnd(Node *head, int newData)  {
   // Your code here
   
   Node *newnode = (Node *)malloc(sizeof(Node));
   newnode->data = newData;
   newnode->next = NULL;
    
    if (head == NULL) {
        head = newnode;
        return head;
    }
    
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    
    return head;
}
