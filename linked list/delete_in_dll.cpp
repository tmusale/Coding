/*
Delete node in Doubly Linked List

Delete a node from given position in a doubly linked list.

Input:

In this problem, method takes two argument: the address of the head of the linked 
list and the node you have to delete . The function should not read any input from stdin/console.
The Node structure has a data part which stores the data and a next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, this method will be called individually.

Output:

Delete the node from the given doubly linked list and set *head_ref if required .

Constraints:
1<=T<=300
2<=N<=100
1<=x<=N

Example:

Input:
2
3                        //Size of Linked List
1  3 4                 //Elements of Linked List
3                        //Location of element to be deleted
4
1 5 2 9                    
1

Output:
1 3           
5 2 9
*/

/*struct Node
{
  int data;
  Node *next;
  Node *prev;
};
 */
void deleteNode(Node **head_ref, int x)
{
  //Your code here
  if ((*head_ref) == NULL) {
      return;
  }
  
  Node *ptr1 = *head_ref;
  Node *ptr2;
  
  if ((*head_ref)->next) {
      ptr2 = (*head_ref)->next;
  }
  
  int count = 1;
  
  if (count == x) {
      Node *temp = (*head_ref);
      *head_ref = (*head_ref)->next;
      (*head_ref)->prev = NULL;
      free(temp);
      
      return;
  }
  
  while (ptr2) {
      count++;
      
      if (count == x) {
          ptr1->next = ptr2->next;
          if (ptr2->next) {
            ptr2->next->prev = ptr1;
          }
          
          free(ptr2);
          
          return;
      }
      
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
  }
}