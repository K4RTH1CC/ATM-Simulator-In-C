project.exe: project_s.o project_c.o
	gcc project_s.o project_c.o -o project.exe
project_s.o: project_s.c project.h
	gcc -c project_s.c
project_c.o: project_c.c project.h
	gcc -c project_c.c