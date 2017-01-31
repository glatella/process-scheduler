
pschedulerLib: pschedulerLib.o queue.o
	gcc -o pschedulerLib pschedulerLib.o queue.o

queue.o: queue.c queue.h
	gcc -c queue.c

pschedulerLib.o: pschedulerLib.c pschedulerLib.h
	gcc -c pschedulerLib.c