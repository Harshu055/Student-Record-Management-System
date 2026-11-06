#include "student.h"
void stud_del(SLL **ptr)
{
	char op;

	printf("R/r : Delete by roll number\n");
	printf("N/n : Delete by name\n");
	printf("Enter your choice:\n");
	scanf(" %c", &op);

	switch(op)
	{
		case 'R':
		case 'r':
			del_by_roll(ptr);
			break;

		case 'N':
		case 'n':
			del_by_name(ptr);
			break;

		default:
			printf("Enter a valid option\n");
			break;
	}
}

void del_by_roll(SLL **ptr)
{
	int num;
	SLL *del = *ptr, *prev = NULL;

	if(*ptr == NULL)
	{

		printf("\n--------------------------------------------------\n");
		printf("No records found\n");
		printf("--------------------------------------------------\n");
		return;
	}

	printf("Enter roll no to delete:\n");
	scanf("%d", &num);

	while(del != NULL)
	{
		if(num == del->rollno)
		{
			if(del == *ptr)
				*ptr = del->next;
			else
				prev->next = del->next;

			free(del);

			printf("Record deleted successfully\n");
			return;
		}

		prev = del;
		del = del->next;
	}

	printf("Roll no not found\n");
}

void del_by_name(SLL **ptr)
{
	char name[20];
	SLL *del = *ptr, *prev = NULL;

	if(*ptr == NULL)
	{
		printf("No records found\n");
		return;
	}

	printf("Enter name to delete:\n");
	scanf("%s", name);

	while(del != NULL)
	{
		if(strcmp(name,del->name)==0)
		{
			if(del == *ptr)
				*ptr = del->next;
			else
				prev->next = del->next;

			free(del);

			printf("Record deleted successfully\n");
			return;
		}

		prev = del;
		del = del->next;
	}

	printf("Name not found\n");
}

void del_all(SLL **ptr)
{
	SLL *del = *ptr;
	int c = 1;

	while(del)
	{
		*ptr = del->next;

		printf("Node %d: deleted\n", c++);

		sleep(1);

		free(del);
		del = *ptr;
	}
	printf("All records are deleted successfully..\n");
}

