/*
Merge two BST 's

Given two BST, you need to print the elements of both BSTs in sorted form.

Input Format:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. 
Each test case contains three lines. The first line of each test case contain's an integer N and M denoting 
the size of the two BST's. Then In the next two line are space separated values of the two BST's.

Output Format:
For each testcase, in a new line, print the elements of both BSTs in sorted form.

Your Task:
This is a function problem, you don't have to take any input. Just complete the function merge() that nodes of both BSTs as parameters.

Constraints:
1 <= T <= 100
1 <= N,M <= 100

Example:
Input:
2
3 3
1 33 4 
6 7 1
2 2
1 6
9 2

Output:
1 1 4 6 7 33
1 2 6 9

Explanation:
Testcase1: The BSTs look like

BST1:
                1
                  \
                    4
                       \
                         33

BST2:
                     6
                    /   \
                   1    7
The sorted elements of above BSTs are 1 1 4 6 7 33
 
*/


/* The structure of Node is
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};*/
/*You are required to complete below method */

void store(Node *root, vector<int> &v)
{
    if (root == NULL) {
        return;
    }
    store(root->left, v);
    v.push_back(root->data);
    store(root->right, v);
}

void inorder(Node *root)
{
    if (root == NULL) {
        return;
    }
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void find_pos(Node *root, Node *newnode)
{
    if (newnode->data <= root->data && root->left == NULL) {
        root->left = newnode;
    }
    else if (newnode->data <= root->data && root->left != NULL) {
        find_pos(root->left, newnode);
    }
    else if (newnode->data > root->data && root->right == NULL) {
        root->right = newnode;
    }
    else {
        find_pos(root->right, newnode);
    }
}

Node *insert1(Node *root, int x)
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

void merge(Node *root1, Node *root2)
{
   //Your code here
   vector<int> v;
   store(root2, v);
   
   for (auto i = v.begin(); i != v.end(); i++) {
       root1 = insert1(root1, *i);
   }
   
   inorder(root1);
   //cout << endl;
}