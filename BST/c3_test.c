#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
	struct node *parent;
};

void find_pos(struct node *root, struct node *newnode)
{
	if ((newnode->data < root->data) && (root->left == NULL)) {
		root->left = newnode;
		newnode->parent = root;
	}
	else if ((newnode->data < root->data) && (root->left != NULL)) {
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

struct node * insert(struct node *root, int x)
{
	struct node * newnode = (struct node *) malloc(sizeof(struct node));
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

void inorder(struct node *root) 
{
	int sum;
	sum = 0;
	if (root != NULL) {
		inorder(root->left);
		sum = root->data;
		if (root->parent != NULL) {
			sum = sum + root->parent->data;
		}
		if (root->left != NULL) {
			sum = sum + root->left->data;
		}
		if (root->right != NULL) {
			sum = sum + root->right->data;
		}

		printf("%d ", sum);
		inorder(root->right);
	}
}

int main()
{
	struct node *root = NULL;
	int n;
	int x;
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		root = insert(root, x);
	}
	inorder(root);
	printf("\n");

	return 0;
}
