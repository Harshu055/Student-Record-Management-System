stud_exe: stud_main.o stud_add.o stud_show.o stud_del.o stud_mod.o stud_save.o student.h
	cc stud_main.o stud_add.o stud_show.o stud_del.o stud_mod.o stud_save.o -o stud_exe

stud_main.o:stud_main.c
	cc -c stud_main.c student.h

stud_add.o:stud_add.c
	cc -c stud_add.c student.h

stud_show.o:stud_show.c
	cc -c stud_show.c student.h

stud_del.o:stud_del.c
	cc -c stud_del.c student.h

stud_mod.o:stud_mod.c
	cc -c stud_mod.c student.h

stud_save.o:stud_save.c
	cc -c stud_save.c student.h

clear: 
	@echo "clearing up..."
	@rm -r *.o
