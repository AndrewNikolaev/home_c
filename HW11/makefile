all: report

report: report.o temp_function.o
	gcc -o report temp_function.o report.o
report.o:
	gcc -c --std=c99 -o report.o report.c
temp_function.o:
	gcc -c --std=c99 -o temp_function.o temp_function.c
clean:
	rm -rf *.o report.exe
