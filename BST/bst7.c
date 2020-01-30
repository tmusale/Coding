#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

void find_pos(struct node *root, struct node *newnode);

struct node * insert(struct node *root, int x)
{
	struct node *newnode;

	newnode = (struct node *)malloc(sizeof(struct node));
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

void find_pos(struct node *root, struct node *newnode)
{
	if ((newnode->data <= root->data) && (root->left == NULL)) {
		root->left = newnode;
	}
	else if ((newnode->data <= root->data) && (root->left != NULL)) {
		find_pos(root->left, newnode);
	}
	else if ((newnode->data > root->data) && (root->right == NULL)) {
		root->right = newnode;
	}
	else {
		find_pos(root->right, newnode);
	}

}

void inorder(struct node *root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

int main()
{
	struct node *root = NULL;
	int n;
	int i;
	int x;
	int *in;
	int *post;

	scanf("%d", &n);
	in = (int *)malloc(sizeof(int) * n);
	post = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	for (i = 0; i  < n; i++) {
		scanf("%d", &post[i]);
	}
	for (i = n-1; i >= 0; i--) {
		root = insert(root, post[i]);
	}

	inorder(root);
	printf("\n");
	return 0;
	
}
