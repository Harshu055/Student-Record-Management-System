#include "student.h"
void stud_show(SLL*ptr)
{
	if(ptr==0)
	{
		printf("\n--------------------------------------------------\n");
		printf("No records found\n");
		printf("--------------------------------------------------\n");
		return;
	}

	printf("\n--------------------------------------------------\n");
	printf("Roll No. Name Percentage\n");
	printf("--------------------------------------------------\n");
	while(ptr)
	{
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
		ptr=ptr->next;

	}	
}
