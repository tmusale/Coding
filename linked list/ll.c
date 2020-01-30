#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node * add_last(struct node *head, int x);
void print_list(struct node *head);

int main()
{
	int i;
	struct node *head = NULL;

	print_list(head);
	printf("\n");

	for (i = -2; i < 10; i++) {
		head = add_last(head, i);
	}

	printf("\n");

	print_list(head);

	return 0;
}

struct node * add_last(struct node *head, int x)
{
	struct node *tmp;
	struct node *ptr_node;

	ptr_node = (struct node *)malloc(sizeof(struct node));
	ptr_node->data = x;
	ptr_node->next = NULL;

	if(head == NULL) {
		printf("creating head: %d\n", x);
		return ptr_node;
	}

	printf("   to add %d: (found) ", x);
	for (tmp = head; tmp->next != NULL; tmp = tmp->next) {
		printf(" %d", tmp->data);
	}
	printf("%d\n", tmp->data);

	tmp->next = ptr_node;

	return head;
}

void print_list(struct node *head)
{
	struct node *tmp;

	printf("traversing linked list: ");
	
	if(head == NULL) {
		printf(" (empty)\n");
		return;
	}

	for (tmp = head; tmp != NULL; tmp = tmp->next) {
		printf(" %d ", tmp->data);
	}
	printf("\n");

	return;
}
