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

int main() 
{
	struct node *root = NULL;

	root = create();
	preorder(root);
	printf("\n");

	return 0;
}
