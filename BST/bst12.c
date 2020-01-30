#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

void find_pos(struct node *root, struct node *newnode);
void in_suc(struct node *root);
void in_pre(struct node *root);

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

void search(struct node *root, int k)
{
	if (root == NULL) {
		printf("\ntree is empty");
		return;
	}
	if(k == root->data) {
		in_suc(root);
		in_pre(root);
		return;
	}
	else if(k < root->data) {
		search(root->left, k);	
	}
	else{
		search(root->right, k);
	}
}

void in_pre(struct node *root) 
{
	struct node *temp;

	temp = root->left;
	while(temp->right) {
		temp = temp->right;
	}
	printf("\nPredecessor = %d", temp->data);

	return;
}

void in_suc(struct node *root) 
{
	struct node *temp;

	temp = root->right;
	while(temp->left) {
		temp = temp->left;
	}
	printf("\nsuccesor = %d", temp->data);
	
	return;
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
	search(root, k);

	return 0;
	
}
