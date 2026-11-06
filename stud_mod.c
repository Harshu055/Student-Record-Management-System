#include "student.h"

void stud_mod(SLL*ptr)
{
	char op;
	printf("R/r : Search by roll number\n");
	printf("N/n : Search by name\n");
	printf("P/p : Search by percentage\n");
	scanf(" %c",&op);

	switch(op)
	{
		case 'R':
		case 'r':
			mod_by_roll(ptr);
			break;

		case 'N':
		case 'n':
			mod_by_name(ptr);
			break;

		case 'p':
		case 'P':
			mod_by_percentage(ptr);
			break;

		default:
			printf("Enter a valid option\n");
			break;
	}
}

void mod_by_roll(SLL *ptr)
{
	int roll;
	SLL *mod = ptr;

	if(ptr == NULL)
	{
		printf("No records found\n");
		return;
	}

	printf("Enter the roll no to be modified:\n");
	scanf("%d", &roll);

	while(mod)
	{
		if(roll == mod->rollno)
		{

			printf("Enter modified name and percentage:\n");
			scanf("%19s %f", mod->name, &mod->percentage);
			sleep(1);
			printf("Records modified successfully...\n");
			return;
		}

		mod = mod->next;
	}

	printf("Roll no not found\n");
}



void mod_by_name(SLL *ptr)
{
	char name[20];
	SLL *mod = ptr;

	if(ptr == NULL)
	{
		printf("No records found\n");
		return;
	}

	printf("Enter the name to be modified:\n");
	scanf("%s", name);

	while(mod)
	{
		if(strcmp(name,mod->name)==0)
		{

			printf("Enter modified roll no and percentage:\n");
			scanf("%d %f", &mod->rollno, &mod->percentage);

			printf("Records modified successfully...\n");
			return;
		}

		mod = mod->next;
	}
}


void mod_by_percentage(SLL *ptr)
{
	float percentage;
	SLL *mod = ptr;

	if(ptr == NULL)
	{
		printf("No records found\n");
		return;
	}

	printf("Enter the percentage to be modified:\n");
	scanf("%f", &percentage);

	while(mod)
	{
		if(percentage == mod->percentage)
		{

			printf("Enter modified roll no and name:\n");
			scanf("%d %19s", &mod->rollno, mod->name);

			printf("Records modified successfully...\n");
			return;
		}

		mod = mod->next;
	}
}

void stud_sort(SLL*ptr)
{
	char op;
	printf("N/n : Sort with name\n");
	printf("P/p : Sort with percentage\n");
	printf("Enter your choice\n");
	scanf(" %c", &op);

	switch(op)
	{
		case 'n':
		case 'N': 
			sort_by_name(ptr);
			break;
		case 'p':
		case 'P':
			sort_by_percentage(ptr);
			break;
		default: printf("Invalid opetion\n");
			 break;
	}
}


void sort_by_name(SLL *ptr)
{
	SLL *p1, *p2, t;
	int i, j, c = count_node(ptr);

	for(i = 0; i < c-1; i++)
	{
		p1 = ptr;

		for(j = 0; j < c-1-i; j++)
		{
			p2 = p1->next;

			if(strcmp(p1->name, p2->name) > 0)
			{
				t.rollno = p1->rollno;
				strcpy(t.name, p1->name);
				t.percentage = p1->percentage;

				p1->rollno = p2->rollno;
				strcpy(p1->name, p2->name);
				p1->percentage = p2->percentage;

				p2->rollno = t.rollno;
				strcpy(p2->name, t.name);
				p2->percentage = t.percentage;
			}

			p1 = p1->next;
		}
	}
}

void sort_by_percentage(SLL *ptr)
{
	SLL *p1, *p2, t;
	int i, j, c = count_node(ptr);

	for(i = 0; i < c-1; i++)
	{
		p1 = ptr;

		for(j = 0; j < c-1-i; j++)
		{
			p2 = p1->next;

			if(p1->percentage > p2->percentage)
			{
				t.rollno = p1->rollno;
				strcpy(t.name, p1->name);
				t.percentage = p1->percentage;

				p1->rollno = p2->rollno;
				strcpy(p1->name, p2->name);
				p1->percentage = p2->percentage;

				p2->rollno = t.rollno;
				strcpy(p2->name, t.name);
				p2->percentage = t.percentage;
			}

			p1 = p1->next;
		}
	}
}

int count_node(SLL*ptr)
{
	int c=0;

	while(ptr)
	{
		c++;
		ptr=ptr->next;
	}
	return c;
}

void stud_reverse(SLL** ptr)
{
	if(*ptr == 0)
	{
		printf("No records found\n");
		return;
	}

	int c= count_node(*ptr);
	int i;
	if(c>1)
	{
		SLL *t=*ptr;
		SLL **a=malloc(sizeof(SLL*)*c);

		for(i=0;i<c;i++)
		{
			a[i]=t;
			t=t->next;
		}

		for(i=c-1;i<0;i--)
		{
			a[i]->next=a[i-1];
			a[0]->next=0;
			*ptr=a[c-1];
		}
	}
}


