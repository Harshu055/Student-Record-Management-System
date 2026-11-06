#include "student.h"

void stud_load(SLL **ptr)
{
	FILE *fp;
	SLL *new, *last = NULL;

	SLL s;

	fp = fopen("student.dat", "r");

	if(fp == NULL)
	{
		printf("\n--------------------------------------------------\n");
		printf("No previous records found\n");
		printf("--------------------------------------------------\n");
		return;
	}

	while(fscanf(fp,"%d %19s %f",&s.rollno, s.name, &s.percentage) == 3)
	{
		new = malloc(sizeof(SLL));

		if(new == NULL)
		{
		printf("\n--------------------------------------------------\n");
			printf("Memory allocation failed\n");
		printf("--------------------------------------------------\n");
			fclose(fp);
			return;
		}

		new->rollno = s.rollno;
		strcpy(new->name, s.name);
		new->percentage = s.percentage;
		new->next = NULL;

		if(*ptr == NULL)
			*ptr = new;
		else
			last->next = new;

		last = new;
	}

	fclose(fp);

	sleep(1);
	printf("Records loaded successfully...\n");
}

void stud_save(SLL *ptr)
{
	SLL s;
	FILE *fp =  fopen("student.dat", "w");

	if(fp == NULL)
	{
		printf("File cannot be opened\n");
		return;
	}

	while(ptr)
	{
		fprintf(fp,"Roll: %d | Name: %s | Percentage: %f\n",ptr->rollno,ptr->name,ptr->percentage);

		ptr=ptr->next;
	}

	fclose(fp);
}

void saveNexit(SLL **ptr)
{
	SLL *temp;

	sleep(1);
	printf("Records are saving...\n");
	stud_save(*ptr);

	/* Free all nodes */
	while(*ptr)
	{
		temp = *ptr;
		*ptr = (*ptr)->next;
		free(temp);
	}

	printf("Records saved...\n");
	sleep(1);
	printf("Memory released...\n");
	sleep(1);
	printf("Exiting...\n");
	sleep(1);
	exit(0);
}

void end(SLL**ptr)
{
	char op;
	printf("S/s : Save and exit\n");
	printf("E/e : Exit without saving\n");
	printf("Enter your choice:\n");
	scanf(" %c",&op);


	switch(op)
	{
		case 's':
		case 'S':
			 saveNexit(ptr);
			 break;

		case 'e':
		case 'E':
			 exit_without_save(ptr);
			 break;

		defualt: printf("Invalid choice\n");
			 
	}
}

void exit_without_save(SLL **ptr)
{
	SLL *temp;

	while(*ptr)
	{
		temp = *ptr;
		*ptr = (*ptr)->next;
		free(temp);
	}

	sleep(1);
	printf("All nodes are released without saving...\n");
	sleep(1);
	exit(0);
}
