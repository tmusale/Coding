/*
Kth largest element in BST

Given a Binary search tree. Your task is to complete the function which will return the Kth largest element 
without doing any modification in Binary Search Tree.
 

Input:
The first line of input contains an integer T, denoting the no of test cases. Then T test cases follow.
 Each test case consists of three lines. The first line of each test case contains an integer N denoting 
 the no of elements in BST. Then in the next line are N space separated values of the BST. The third line 
 of each test case contains an integer k for k largest element.
 

Output:
Print the kth largest element in each line.
 
Constraints:
1<=T<=20
1<=N , K<=20
 

Example(To be used only for expected output):
Input:
1
7
50 30 20 40 70 60 80
3
Output:
60
*/

/*The Node structure is defined as
struct Node
{
    int key;
    Node *left, *right;
}; */
/*Complete the function below*/

//int count = 0;

void find_k(Node *root, int &count, int k)
{
    if (root == NULL || (count > k)) {
        return;
    }
    
    //pq.push(root->data);
    
    find_k(root->right, count, k);
    count++;
    if (count == k) {
        cout << root->key << endl;
        return;
    }
    find_k(root->left, count, k);
}

void kthLargest(Node *root, int k)
{
    //Your code here
    //priority_queue<int> pq;
    //int arr[25];
    int count = 0;
    find_k(root, count, k);
    int i;
    
}