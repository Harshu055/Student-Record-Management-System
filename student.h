#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct student
{
	int rollno;
	char name[20];
	float percentage;
	struct student *next;
}SLL;

void stud_add(SLL**);
void stud_del(SLL**);
void stud_show(SLL*);
void stud_mod(SLL*);
void stud_save(SLL*);
int count_node(SLL*);
void stud_reverse(SLL**);
void del_by_name(SLL**);
void del_by_roll(SLL**);
void stud_sort(SLL*);
void sort_by_name(SLL*);
void sort_by_percentage(SLL*);
void del_all(SLL**);
void mod_by_roll(SLL*);
void mod_by_name(SLL*);
void mod_by_percentage(SLL*);
void stud_load(SLL**);
void end(SLL**);
void saveNexit(SLL**);
void exit_without_save(SLL**);
