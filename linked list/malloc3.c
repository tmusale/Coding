#include <stdio.h>
#include <stdlib.h>

struct node {
	int x;
};

int main()
{
	struct node n;
	struct node *ptr_node = NULL;

	n.x = 10;

	ptr_node = &n;
	printf("n.x = %d; (*ptr_node).x = %d\n", n.x, (*ptr_node).x);

	ptr_node = (struct node *)malloc(sizeof(struct node));
	(*ptr_node).x = 20;
	printf("n.x = %d; (*ptr_node).x = %d\n", n.x, (*ptr_node).x);

	((*ptr_node).x)++;
	printf("n.x = %d; (*ptr_node).x = %d\n", n.x, (*ptr_node).x);

	(ptr_node->x)++;
	printf("n.x = %d; ptr_node->x = %d\n", n.x, ptr_node->x);

	n = (*ptr_node);
	printf("n.x = %d; ptr_node->x = %d\n", n.x, ptr_node->x);

	return 0;
}
