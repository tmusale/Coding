/*
Delete a node from BST

Given a Binary Search Tree (BST) and a node no 'x', your task is to delete the node 'x' from the BST.

Input Format:
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. 
Each test case consists of three lines. Description of  test cases is as follows:
The First line of each test case contains an integer 'N' which denotes the number of nodes in the BST.
The Second line of each test case contains 'N' space separated values  of the nodes in the BST.
The Third line of each test case contains an integer 'x' the value of the node to be deleted from the BST.

Output Format:
For each testcase, in a new line, print the inorder traversal.

Your Task:
You are required to complete the function deleteNode() which takes two arguments. The first being the root of the tree, 
and an integer 'x' denoting the node to be deleted from the BST. The function returns a pointer to the root of the modified BST.

Constraints:
1 <= T <= 50
1 <= N <= 50

Example:
Input:
2
7
2 81 87 42 66 90 45 
81
6
5 6 7 4 3 2
7
Output:
2 42 45 66 87 90
2 3 4 5 6

Explanation:
Testcase 1: After deleting 81 from BST, we have nodes left as 2 42 45 66 87 90.
*/


/* The structure of a BST Node is as follows:
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
}; 
*/

Node * successor(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    
    return temp;
}

Node *deleteNode(Node *root,  int x)
{
    // your code goes here
    if (root == NULL) {
        return root;
    }
    
    if (root->data > x) {
        root->left = deleteNode(root->left, x);
    }
    else if (root->data < x) {
        root->right = deleteNode(root->right, x);
    }
    else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else {
            Node *temp = successor(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    
    return root;
}
