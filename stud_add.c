#include "student.h"
void stud_add(SLL **ptr)
{
	SLL *new, *temp;
	int roll = 1;

	new = malloc(sizeof(SLL));

	if(new == NULL)
	{
		printf("Memory allocation failed...\n");
		return;
	}

	while(1)
	{
		temp = *ptr;

		while(temp != NULL)
		{
			if(temp->rollno == roll)
				break;

			temp = temp->next;
		}

		if(temp == NULL)
			break;

		roll++;
	}

	new->rollno = roll;

	printf("Enter student name and percentage:\n");
	scanf("%19s %f", new->name, &new->percentage);

	new->next = NULL;

	if(*ptr == NULL)
		*ptr = new;
	else
	{
		temp = *ptr;

		while(temp->next != NULL)
			temp = temp->next;

		temp->next = new;
	}
}
