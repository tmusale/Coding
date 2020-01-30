/*
Check for BST

Given a binary tree, return true if it is BST, else false. For example, the following tree is not BST, 
because 11 is in left subtree of 10. The task is to complete the function isBST() which takes one argument, root of Binary Tree.

        10
     /     \
   7       39
     \
      11

Input:
The input contains T, denoting number of testcases. For each testcase there will be two lines. 
The first line contains number of edges. The second line contains two nodes and a character separated by space. 
The first node denotes data value, second node denotes where it will be assigned to the previous node which will 
depend on character 'L' or 'R' i.e. the 2nd node will be assigned as left child to the 1st node if character 
is 'L' and so on. The first node of second line is root node. The struct or class Node has a data part which 
stores the data, pointer to left child and pointer to right child. There are multiple test cases. 
For each test case, the function will be called individually.


Output:
The function should return 1 if BST else return 0.

User Task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function isBST().

Constraints:
1 <= T <= 30
1 <= Number of edges <= 100
1 <= Data of a node <= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
0
0

Explanation:
Testcases 1: The given binary tree is not BST, hence the answer is 0.
*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
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

bool checkBST(Node *root, int min, int max)
{
    if (root == NULL) {
        return true;
    }
    
    if (root->data > min && root->data < max) {
        return (checkBST(root->left, min, root->data) && checkBST(root->right, root->data, max));
    }
    else {
        return false;
    }
}

bool isBST(Node* root) {
    // Your code here
    
    int min = -1;
    int max = 9999;
    
    return checkBST(root, min, max);
}
