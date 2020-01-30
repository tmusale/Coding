/*
Construct BST from Postorder
Given postorder traversal of a Binary Search Tree, you need to complete the function constructTree() which will create a BST. 
The output will be the inorder of the constructed BST.

Input:
The constructTree() method consist of two arguments as input, the array consisting of the post order traversal and the size of the array.

Output:
Print the Inorder traversal of the constructed BST.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
6
1 7 5 50 40 10
9
216 823 476 429 850 93 18 975 862

Output:
1 5 7 10 40 50
18 93 216 429 476 823 850 862 975

Explanation:
Testcase 1: The BST for the given post order traversal is:


Thus the inorder traversal of BST is: 1 5 7 10 40 50.
*/

/*struct Node
{
	int data;
	Node *left, *right;
};*/

void find_pos(Node *root, Node *newnode)
{
    if (newnode->data < root->data && root->left == NULL) {
        root->left = newnode;
    }
    else if (newnode->data < root->data && root->left != NULL) {
        find_pos(root->left, newnode);
    }
    else if (newnode->data > root->data && root->right == NULL) {
        root->right = newnode;
    }
    else {
        find_pos(root->right, newnode);
    }
}

Node * insert(Node *root, int x)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = x;
    newnode->left = newnode->right = NULL;
    
    if (root == NULL) {
        return newnode;
    }
    else {
        find_pos(root, newnode);
    }
    
    return root;
}

Node *constructTree (int post[], int size)
{
//code here
    Node *root = NULL;
    for (int i = size-1; i >= 0; i--) {
        root = insert(root, post[i]);
    }
    
    return root;
}