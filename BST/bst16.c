#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node * create()
{
	struct node *newnode;
	int x;
	
	printf("\nenter data (-1 for no data)");
	scanf("%d", &x);
	if (x == -1) {
		return NULL;
	}

	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = x;

	printf("enter left child of %d", x);
	newnode->left = create();

	printf("enter right child of %d", x);
	newnode->right = create();

	return newnode;

}

void preorder(struct node *root)
{
	if (root) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

int find_bst(struct node *root) 
{
	int l, r;
	if (root == NULL) {
		return 1;
	}
	if ((root->left == NULL) && (root->right == NULL)) {
		return 1;
	}
	if ((root->left == NULL) && (root->right != NULL)) {
		if (root->data < root->right->data) {
			r = find_bst(root->right);
			return r;
		}
		else {
			return 0;
		}
	}
	else if ((root->left != NULL) && (root->right == NULL)) {
		if (root->data >= root->left->data) {	
			l = find_bst(root->left);
			return l;
		}
		else {
			return 0;
		}
	}
	if (((root->data >= root->left->data)) && ((root->data < root->right->data))) {
		l = find_bst(root->left);
		r = find_bst(root->right);
		return (l && r);
	}
	else {
		return 0;
	}
}

int main() 
{
	struct node *root = NULL;
	int flag;

	root = create();
	//preorder(root);
	//printf("\n");
	flag = find_bst(root);
	if (flag) {
		printf("\nBST");
	}
	else {
		printf("\n not BST");
	}

	return 0;
}
