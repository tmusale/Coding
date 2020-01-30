#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

void display_path(int path[], int len);

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

void root_leaf(struct node *root, int path[], int pathlen)
{
	if (root == NULL) {
		return;
	}

	path[pathlen] = root->data;
	pathlen++;

	if (root->left == NULL && root->right == NULL) {
		display_path(path, pathlen);
	}
	else {
		root_leaf(root->left, path, pathlen);
		root_leaf(root->right, path, pathlen);
	}
}

void display_path(int path[], int len)
{
	int i;
	for (i = 0; i < len; i++) {
		printf("%d ", path[i]);
	}
	printf("\n");
}

int main()
{
	struct node *root = NULL;
	int n;
	int i;
	int x;
	int path[100];

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		root = insert(root, x);
	}
	root_leaf(root, path, 0);
	//inorder(root);
	//printf("\n");

	return 0;
}
