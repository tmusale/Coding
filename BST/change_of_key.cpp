/*
Change of Key in BST

Given a Binary Search Tree of size N, your task is to complete the function changeKey() 
that change old key value present in the tree and changes it to new key value.
Example:

Input: Root of below tree
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 
     Old key value:  40
     New key value:  10

Output: BST should be modified to following
              50
           /     \
          30      70
         /       /  \
       20      60   80  
       /
     10

Input:
The function takes three arguments, reference pointer to the root node of the BST, old key value of the node and a new key value.
There will be T test cases and for each test case the function will be called separately.

Output:
For each test case output the Inorder traversal of the Tree.

Constraints:
1<=T<=100
1<=N<=500

Example:
Input:
1
7
20 8 22 4 12 10 14
8 1
Output:
1 4 10 12 14 20 22


*/

/*
Structure of the binary Search Tree is as
struct node
{
	int key;
	struct node *left, *right;
};
*/
// your task is to complete the Function
// Function is used to change a key value in the given BST
// Note: Function should return root node to the new modified BST

struct node * succesor(struct node *root)
{
    if (root == NULL) {
        return NULL;
    }
    struct node *temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    
    return temp;
}

struct node * delete_old(struct node *root, int oldval)
{
    if (root == NULL) {
        return root;
    }
    
    if (root->key > oldval) {
        root->left = delete_old(root->left, oldval);
    }
    else if (root->key < oldval) {
        root->right = delete_old(root->right, oldval);
    }
    else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        else {
            struct node *temp = succesor(root->right);
            root->key = temp->key;
            root->right = delete_old(root->right, temp->key);
        }
    }
    
    return root;
}

/*struct node * insert(struct node *root, int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->key = val;
    newnode->left = newnode->right = NULL;
    
    if (root == NULL) {
        return newnode;
    }
    
    if (val < root->key && root->left == NULL) {
        root->left = newnode;
    }
    else if (val < root->key && root->left != NULL) {
        root->left = insert(root->left, val);
    }
    else if (val > root->key && root->right == NULL) {
        root->right = newnode;
    }
    else {
        root->right = insert(root->right, val);
    }
    
    return root;
}*/

struct node *changeKey(struct node *root, int oldVal, int newVal)
{
	// Code here
	
	root = delete_old(root, oldVal);
	
	root = insert(root, newVal);
	
	return root;
}