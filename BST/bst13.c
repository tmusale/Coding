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
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;

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
	if (root) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void ancestor(struct node *root, int k)
{
	if (root == NULL) {
		return;
	}
	if (k == root->data) {
		//printf("%d ", root->data);
		return;
	}
	if (k <= root->data) {
		printf("%d ", root->data);
		ancestor(root->left, k);
	}
	else if (k > root->data) {
		printf("%d ", root->data);
		ancestor(root->right, k);
	}
	else {
		printf("\nkey not found");
	}

	return;
}

int search(struct node *root, int k) {
	if (root == NULL) {
		return 0;
	}
	if (root->data == k) {
		return 1;
	}
	if (k <= root->data) {
		return search(root->left, k);
	}
	else if (k > root->data) {
		return search(root->right, k);
	}
	else {
		return 0;
	}
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
	scanf("%d", &k);
	x = search(root, k);
	if (x) {
		ancestor(root, k);
	}
	else {
		printf("element is not present");
	}
	printf("\n");

	return 0;
	
}
