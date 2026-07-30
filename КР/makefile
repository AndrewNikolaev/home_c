all: report.exe

report.exe: report.o temp_functions.o
	gcc -g -o report.exe report.o temp_functions.o

report.o: report.c temp_functions.h
	gcc -c --std=c99 -o report.o report.c

temp_functions.o: temp_functions.c temp_functions.h
	gcc -c --std=c99 -o temp_functions.o temp_functions.c

clean:
	del *.o report.exe