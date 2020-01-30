#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
	struct node *parent;
};

void find_pos(struct node *root, struct node *newnode);

struct node * insert(struct node *root, int x)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->parent = NULL;

	if (root == NULL) {
		return newnode;
	}
	else {
		find_pos(root, newnode);
	}

	return root;
}

void find_pos(struct node *root, struct node *newnode)
{
	if ((newnode->data <= root->data) && (root->left == NULL)) {
		root->left = newnode;
		newnode->parent = root;
	}
	else if ((newnode->data <= root->data) && (root->left != NULL)) {
		find_pos(root->left, newnode);
	}
	else if ((newnode->data > root->data) && (root->right == NULL)) {
		root->right = newnode;
		newnode->parent = root;
	}
	else {
		find_pos(root->right, newnode);
	}
}

void inorder(struct node *root)
{
	if (root) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

int sum_tree(struct node *root)
{
	if (root == NULL) {
		return 1;
	}
	if ((root->left == NULL) && (root->right == NULL)) {
		return 1;
	}
	if (root->left == NULL && root->right != NULL) {
		return 0;
	}
	else if (root->left != NULL && root->right == NULL) {
		if (root->data == root->left->data) {
			return 1;
		}	
		else {
			return 0;
		}
	}
	if (root->left != NULL && root->right != NULL) {
		if (root->data == (root->left->data + root->right->data)) {
			return 1;
		}
		else {
			return 0;
		}
	}

	return (sum_tree(root->left) && sum_tree(root->right));
}

int main()
{
	struct node *root = NULL;
	int n;
	int i;
	int x;
	int k;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		root = insert(root, x);
	}
	//inorder(root);
	//printf("\n");
	k = sum_tree(root);
	if (k) {
		printf("sum tree");
	}
	else {
		printf("not sum tree");
	}
	printf("\n");

	return 0;
	
}
