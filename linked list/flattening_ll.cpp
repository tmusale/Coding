/*
Flattening a Linked List

Given a Linked List of size N, where every node represents a linked list and contains two pointers of its type:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.

You have to flatten the linked list to a single linked list which is sorted.

       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
and after flattening it, the sorted linked list looks like:

 5-> 7-> 8- > 10 -> 19-> 20-> 22-> 28-> 30-> 35-> 40-> 45-> 50.

The  node structure has 3 fields as mentioned. A next pointer, a bottom pointer and a data part.
There are multiple test cases. For each test case, this function will be called individually.

Input (To be used for Expected Output):
The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow.
First line of each test case contains an integer N denoting the number of head nodes connected to each other.
Second line of each test case contains N space separated numbers (M1, M2...Mn) denoting number of elements in 
linked lists starting with each head. Third line of each test case contains all the elements of the linked list 
starting with 1st head node and covering all the elements through its down pointer, then 2nd head node and 
covering all its elements through down pointer and so on till the last head node of the linked list.

Output:
Return a pointer to the flattened linked list.

Constraints:
1 <= T <= 50
0 <= N <= 50
1 <= Mi <= 20
1 <= Element of linked list <= 1000

Example:
Input
1                   
4 
4 2 3 4                  
5 7 8 30 10 20 19 22 50 28 35 40 45

Output:
5 7 8 10 19 20 22 28 30 35 40 45 50


*/

Node * merge_ll(Node *head1, Node *head2)
{
    Node *list1 = head1;
    Node *list2 = head2;
    Node *merge = NULL;
    Node *nxt = head2->next;
    
    if (list1->data <= list2->data) {
        merge = list1;
        list1 = list1->bottom;
    }
    else {
        merge = list2;
        list2 = list2->bottom;
    }
    
    Node *temp = merge;
    while (list1 && list2) {
        if (list1->data <= list2->data){
            temp->bottom = list1;
            temp = temp->bottom;
            list1 = list1->bottom;
            //temp->bottom = list2;
        }
        else {
            temp->bottom = list2;
            temp = temp->bottom;
            list2 = list2->bottom;
        }
    }
    
    if (!list2) {
        temp->bottom = list1;
    }
    else if(!list1){
        temp->bottom = list2;
    }
    
    head1->next = NULL;
    head2->next = NULL;
    merge->next = nxt;
    
    return merge;
}

Node *flatten(Node *root)
{
   // Your code here
   while (root->next) {
       Node *temp = merge_ll(root, root->next);
       root = temp;
   }
   
   return root;
}