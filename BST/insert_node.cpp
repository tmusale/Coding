/*
Insert a node in a BST

Given a BST and some keys, you need to insert the keys in the given BST. Duplicates are not inserted.

Input Format:
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. 
Each test case consists of three lines. Description of  test cases is as follows:
The First line of each test case contains an integer 'N' which denotes the no of nodes to be inserted in the BST.   .
The Second line of each test case contains 'N' space separated values of the nodes to be inserted in the BST.

Output Format:
For each testcase, in a new line, the inorder of the BST gets printed.

Your Task:
Since this is a function problem, you don't have to read anything. You have to complete the function insert 
that takes node and key as parameter.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input
3
7
2 81 87 42 66 90 45 
4
6 7 9 8
4
1 1 2 1
Output
2 42 45 66 81 87 90
6 7 8 9
1 2
*/


/* The structure of a BST node is as follows:
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
}; */
/* This function should insert a new node with 
  given data and return root of the modified tree  */
  
void find_pos(Node *root, Node * node)
{
    if (node->data < root->data && root->left == NULL){
        root->left = node;
    }
    else if (node->data < root->data && root->left != NULL) {
        find_pos(root->left, node);
    }
    else if (node->data > root->data && root->right == NULL) {
        root->right = node;
    }
    else {
        find_pos(root->right, node);
    }
}
  
Node* insert(Node* node, int data)
{
    // Your code here
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->left = newnode->right = NULL;
    newnode->data = data;
    
    if (node == NULL) {
        return newnode;
    }
    else if (node->data == data) {
        return node;
    }
    
    else if (data < node->data && node->left != NULL) {
        insert(node->left, data);
    }
    else if (data < node->data && node->left == NULL) {
        node->left = newnode;
    }
    else if (data > node->data && node->right != NULL) {
        insert(node->right, data);
    }
    else {
        node->right = newnode;
    }
    
    return node;
}
