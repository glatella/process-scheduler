#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char bool;
#define true 1
#define false 0


struct elemQueue
{
	struct elemQueue * next;
	
};
typedef struct elemQueue elemQueue;

typedef struct
{
	elemQueue * first;
	elemQueue * last;
	int lenght;
} queue;

typedef struct 
{
	elemQueue header;
	long  pid;
	char estated;
	short prio;
	float time;
	char comand[20];
}proc;

void queueInit (queue * container)
{
	container -> first = 0;
	container -> last = 0;
	container -> lenght = 0;
}

bool queueEmpty (queue * container)
{
	return 0 == container -> lenght;
}

elemQueue * queueStart (queue * container)
{
	return container -> first;
}

elemQueue * queueNext(elemQueue * elem)
{
	return elem -> next;
} 

void enQueue (queue * container, elemQueue * elem)
{
	if (queueEmpty(container))
	{
		container -> first = elem;
		container -> last = elem;
	}
	else 
	{
		container -> last -> next = elem;
		container -> last = elem;
	}

	elem -> next = 0;
	container -> lenght += 1;
}

elemQueue * deQueue(queue * container)
{
	elemQueue * elem = container -> first;
	container -> first = container -> first -> next;
	container -> lenght -= 1;
	return elem;
}

int queueLenght (queue * container)
{
	return(container -> lenght);
}

void crearProceso(proc * p,long pid) {

	p -> pid = pid;
}


int main (int argc, char * argv[])

{
	
	queue items;
	proc * item;
	proc * item1;
	proc * item2;
	proc * item3;
	
	queueInit(&items);

	item1 = (proc *)malloc(sizeof(proc));
	item2 = (proc *)malloc(sizeof(proc));
	item3 = (proc *)malloc(sizeof(proc));

	crearProceso(item1,1111);
	crearProceso(item2,2222);
	crearProceso(item3,3333);

	enQueue(&items,&item1->header);
	enQueue(&items,&item2->header);
	enQueue(&items,&item3->header);

	deQueue(&items);
	deQueue(&items);

	int numQueues = 6;
	int x;

	queue * EstrucSched = malloc(numQueues * sizeof(queue));

	for (x = 0; x < numQueues; x++)
	{
	    EstrucSched[x] = items;
	}


	for (item = (proc *)queueStart(&items); item;
		item = (proc *)queueNext(&item->header))
		printf("codigo del proceso: %ld\n", item -> pid);
}
