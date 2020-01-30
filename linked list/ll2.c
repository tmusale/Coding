#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node * insert_beginning(struct node *head, int x);
struct node * insert_end(struct node *head, int x);
struct node * insert_position(struct node *head, int x, int position);
struct node * delete_beginning(struct node *head);
struct node * delete_end(struct node *head);
struct node * delete_position(struct node *head, int position);
void display_list(struct node *head);

int main()
{
	struct node *head = NULL;
	int choice;
	int x;
	int position;

	while(1) {
		printf("enter choice\n");
		printf("1.Insert at beginning\n2.Insert at end\n3.Insert at given position\n4.Display list\n");
		printf("5.Delet at beginning\n6.Delete at end\n7.Delete at position\n8.Exit\n");
		scanf("%d", &choice);
		printf("\n\n");

		switch(choice) {
	
			case 1:
				printf("enter data to insert at beginning\n");
				scanf("%d", &x);
				head = insert_beginning(head, x);
				break;

			case 2:
				printf("enter data to insert at end\n");
				scanf("%d", &x);
				head = insert_end(head, x);
				break;

			case 3:
				printf("enter data to insert\n");
				scanf("%d", &x);
				printf("enter position at which data is to insert\n");
				scanf("%d", &position);
				head = insert_position(head, x, position);
				break;

			case 4:
				display_list(head);
				break;

			case 5:
				head = delete_beginning(head);
				break;

			case 6:
				head = delete_end(head);
				break;

			case 7:
				printf("enter position at which you want to delete a node\n");
				scanf("%d", &position);
				head = delete_position(head, position);
				break;

			case 8:
				exit(0);


			default:
				printf("wrong choice\n");
				exit(1);
		}
	}

	return 0;
}

struct node * insert_beginning(struct node *head, int x)
{
	struct node *newnode;

	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = x;
	newnode->next = NULL;

	if (head == NULL) {
		printf("creating head: %d\n", x);
		return newnode;
	}

	newnode->next = head;
	head = newnode;

	return head;
}

struct node * insert_end(struct node *head, int x)
{
	struct node *newnode;
	struct node *temp;

	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = x;
	newnode->next = NULL;

	if (head == NULL) {
		printf("creating head: %d\n", x);
	}

	temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = newnode;
	newnode = NULL;

	return head;
}

struct node * insert_position(struct node *head, int x, int position)
{
	struct node *newnode;
	struct node *temp;
	int i;
	int list_length = 0;

	if (position == 1) {
		head = insert_beginning(head, x);
		return head;
	}

	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = x;
	newnode->next = NULL;

	for (temp = head; temp != NULL; temp = temp->next) {
		list_length++;
	}

	if(position > list_length+1) {
		printf("list is small to insert at given position\n");
		return head;
	}

	temp = head;
	for(i = 1; i < (position - 1); i++) {
		temp = temp->next;
	}

	newnode->next = temp->next;
	temp->next = newnode;

	return head;
}

struct node * delete_beginning(struct node *head)
{
	struct node *temp;
	if (head == NULL){
		printf("list is empty\n");
		return head;
	}

	temp = head;
	head = head->next;
	free(temp);

	return head;
}

struct node * delete_end(struct node *head)
{
	struct node *temp;
	struct node *delete;

	if (head == NULL) {
		printf("list is empty\n");
		return head;
	}

	temp = head;
	while(temp->next->next != NULL) {
		temp = temp->next;
	}

	delete = temp->next;
	temp->next = NULL;
	free(delete);

	return head;
}

struct node * delete_position(struct node *head, int position)
{
	struct node *temp;
	struct node *delete;
	int length = 0;
	int i;

	if (head == NULL) {
		printf("list is empty\n");
		return head;
	}
	if (position == 1) {
		head = delete_beginning(head);
		return head;
	}
	
	for (temp = head; temp != NULL; temp = temp->next) {
		length++;
	}

	if (position > length) {
		printf("deletion not possible");
		return head;
	}

	temp = head;
	for (i = 1; i < (position -1); i++) {
		temp = temp->next;
	}
	delete = temp->next;
	temp->next = delete->next;
	free(delete);

	return head;
}

void display_list(struct node *head)
{
	struct node *temp;

	for (temp = head; temp != NULL; temp = temp->next) {
		printf("%d -> ", temp->data);
	}
	printf("NULL\n");

	return;
}





