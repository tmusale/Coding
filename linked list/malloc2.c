#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *ptr_int = NULL;
	ptr_int = (int *)malloc(sizeof(int));

	*ptr_int = 30;

	printf("*ptr_int = %d\n", *ptr_int);
	printf("*ptr_int = %d\n", ++(*ptr_int));
	printf("*ptr_int = %d\n", (*ptr_int)++);
	printf("*ptr_int = %d\n", *ptr_int);

	free(ptr_int);

	return 0;
}
