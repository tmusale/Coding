#include <stdio.h>
#include <stdlib.h>

#define VP (void *)

struct node {
	int x;
	struct node *next;
};

int main()
{
	struct node *p1 = NULL;
	struct node *p2 = NULL;

	p1 = (struct node *)malloc(sizeof(struct node));
	(*p1).x = 10;
	(*p1).next = NULL;

	p2 = (struct node *)malloc(sizeof(struct node));
	(*p2).x = 20;
	(*p2).next = NULL;

	printf("p1 = %p; p2 = %p\n\n", VP p1, VP p2);

	printf("(*p1).x = %d; (*p1).next = %p\n", (*p1).x, VP (*p1).next);
	printf("(*p2).x = %d; (*p2).next = %p\n", (*p2).x, VP (*p2).next);

	printf("After p1->next = p2...\n");
	p1->next = p2;

	printf("(*p1).x = %d; ", (*p1).x);
	printf("(*p1).next = %p\n", VP (*p1).next);

	printf("p1->x = %d; ", p1->x);
	printf("p1->next = %p; \n", VP p1->next);

	printf("p1->next->x = %d; ", p1->next->x);
	printf("p1->next->next = %p\n; ", VP p1->next->next);

	return 0;
}
