pscheduler: pscheduler.o pschedulerLib.o queue.o options.o
	gcc -o pscheduler pscheduler.o pschedulerLib.o queue.o options.o

pscheduler.o: pscheduler.c 
	gcc -c pscheduler.c

queue.o: queue.c
	gcc -c queue.c

pschedulerLib.o: pschedulerLib.c pschedulerLib.h
	gcc -c pschedulerLib.c

options.o: options.c options.h
	gcc -c options.c

