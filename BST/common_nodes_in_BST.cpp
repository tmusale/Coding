/*
Print Common Nodes in BST
Given two Binary Search Trees(without duplicates), you need to print the common nodes in them. In other words, 
find intersection of two BSTs.

BST1:

                 5
              /      \
            1         10
          /   \        /
         0     4    7
                    \
                     9

BST2:

               10
             /    \
            7     20
          /   \
         4     9

The common elements of above two BSTs are 4 7 9 10

Input Format:
The first line of the input contains an integer T, denoting the number of testcases. Then T test cases follow. 
Each testcase contains two lines of input. The first line contains number of nodes N. The second line contains values of nodes.

Output Format:
For each test case, in a new line, print the nodes common to both BSTs in sorted order.

Your Task:
This is a function problem. You only need to complete the function printCommon() that takes nodes of both BSTs as parameter.

Constraints:
1 <= T <= 50
1 <= N <= 50

Example:
Input:
2
7
5 1 10 0 4 7 9
5
10 7 20 4 9
5
10 2 11 1 3
3
2 1 3

Output:
4 7 9 10
1 2 3

Explanation:
Testcase1: 4 7 9 10 are the only common nodes.
*/

/*Node structure
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
/* Function should print common elements in given two trees */

void inorder(Node *root, unordered_set<int> &s)
{
    if (root == NULL) {
        return;
    }
    
    inorder(root->left, s);
    s.insert(root->data);
    inorder(root->right, s);
}

void printCommon(Node *root1, Node *root2)
{
     //Your code here
     unordered_set<int> s1, s2;
     
     inorder(root1, s1);
     inorder(root2, s2);
     
     priority_queue<int, vector<int>, greater<int>> pq;
     
     for (auto i = s2.begin(); i != s2.end(); i++) {
         if (s1.find(*i) != s1.end()) {
             //cout << *i << " ";
             pq.push(*i);
         }
     }
     
     while (!pq.empty()) {
         cout << pq.top() << " ";
         pq.pop();
     }
     cout << endl;
     
}
