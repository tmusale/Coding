#include <stdio.h>
#include <stdlib.h>

#define VP (void *)

struct node {
	int data;
	struct node *next;
};

int main()
{
	struct node *p1 = NULL;
	struct node *p2 = NULL;
	struct node *p3 = NULL;
	struct node *p4 = NULL;
	struct node *tmp = NULL;

	p4 = (struct node *)malloc(sizeof(struct node));
	(*p4).data = 10;
	(*p4).next  = NULL;
	
	p3 = (struct node *)malloc(sizeof(struct node));
	(*p3).data = 20;
	(*p3).next = p4;

	p2 = (struct node *)malloc(sizeof(struct node));
	(*p2).data = 30;
	(*p2).next = p3;

	p1 = (struct node *)malloc(sizeof(struct node));
	(*p1).data = 40;
	(*p1).next = p2;

	for (tmp = p1; tmp->next != NULL; tmp = tmp->next) {
		printf("%d -> ", tmp->data);
	}

	printf("NULL\n");
}
