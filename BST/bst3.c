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

int identical(struct node *root1, struct node *root2) 
{
	if (root1 == NULL && root2 == NULL) {
		return 1;
	}
	else if (root1 != NULL && root2 != NULL) {
		return (root1->data == root2->data) && identical(root1->left, root2->left) && identical(root1->right, root2->right);
	}
	else {
		return 0;
	}
}

int main()
{
	struct node *root1;
	struct node *root2;
	int n;
	int i;
	int x;
	int T;
	int flag;

	scanf("%d%d", &T, &n);
	while (T > 0) {
		root1 = NULL;
		root2 = NULL;
		flag = 0;

		for (i = 0; i < n; i++) {
			scanf("%d", &x);
			root1 = insert(root1, x);
		}
		for (i ; i < (2*n); i++) {
			scanf("%d", &x);
			root2 = insert(root2, x);
		}

		flag = identical(root1, root2);
		if (flag == 1) {
			printf("y\n");
		}
		else {
			printf("n\n");
		}
		T--;
	}
}
