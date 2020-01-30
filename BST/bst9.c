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
	struct node *newnode;

	newnode = (struct node *)malloc(sizeof(struct node));
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
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

/*void del_bst(struct node **root)
{
	struct node *t;
	if (*root) {
		del_bst(&((*root)->left));
		del_bst(&((*root)->right));
		printf("%d ", (*root)->data);
		*root = NULL;
	}
}*/

void del_bst(struct node *root)
{
	struct node *t;
	if (root) {
		del_bst(root->left);
		del_bst(root->right);
		printf("%d ", root->data);
		t = root->parent;
		if (t == NULL) {
			root = NULL;
		}
		else {
			if (root->data <= t->data) {
				t->left = NULL;
			}
			else {
				t->right = NULL;
			}
		}
	}
}

int main()
{
	struct node *root = NULL;
	int n;
	int i;
	int x;
	int flag;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		root = insert(root, x);
	}
	//inorder(root);
	del_bst(root);
	root = NULL;
	//inorder(root);
	if (root) {
		inorder(root);
	}
	printf("\n");
	
	return 0;
	
}
