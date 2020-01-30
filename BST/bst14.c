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

void del_leaves(struct node *root) 
{
	struct node *t;
	if (root != NULL) {
		if ((root->left == NULL) && (root->right == NULL)) {
			t = root->parent;
			if (root->data <= t->data) {
				t->left = NULL;
			}
			else if (root->data > t->data) {
				t->right = NULL;
			}
		}
		del_leaves(root->left);
		del_leaves(root->right);
	}
	
}

void free_node(struct node *t) 
{
	free(t);
	t = NULL;
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
	if (n == 1) {
		root = NULL;
	}
	else {
		del_leaves(root);
	}
	inorder(root);
	printf("\n");


	return 0;
	
}
