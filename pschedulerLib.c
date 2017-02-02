/*
# ----------------------------------------------------------------------------#
#                                pschedulerLib.c                              #
# ----------------------------------------------------------------------------#
#                         Universidad Simón Bolívar                           #
#            Departamento de Computación y Tecnología de la Información       #
#                     Laboratorio de Sistemas Operativos                      #
#              Profesora Angela Di Serio y Profesor Carlos Gomez              #
#                          Giuli Latella carnet: 08-10596                     #
#                        Honorio Rodriguez carnet: 09-11023                   #
#                                 Grupo: O                                    #
# ----------------------------------------------------------------------------#
# ----------------------------------------------------------------------------#
*/

#include "pschedulerLib.h"

/*
#-------------------------------------------------------------------------# 
#                           InsertarProceso                               #    
#-------------------------------------------------------------------------#

    Allows you to insert a process in one of the priority queues. 
    The processes will be inserted at the end of the queue that corresponds.

    Parameters:
        - s is a pointer to the scheduler queues structure.
        - p is a pointer to data structure that stores information of 
            the process to be inserted. 
        - prio is a number from 0 to 5 and corresponds to the priority of the process.
*/

void InsertarProceso(EstrucSched *s, proc *p, short prio)
{
    switch(prio)
    {
        case 0:
            enQueue(s[0].prioQueues, &p -> header);
            break;

        case 1:
            enQueue(s[1].prioQueues, &p -> header);
            break;

        case 2:
            enQueue(s[2].prioQueues, &p -> header);
                break;

        case 3:
            enQueue(s[3].prioQueues, &p -> header);
                break;

        case 4:
            enQueue(s[4].prioQueues, &p -> header);
                break;

        case 5:
            enQueue(s[5].prioQueues, &p -> header);
                break;

        default:
            break;
    }
}

/*

/*
#-------------------------------------------------------------------------# 
#                               ElimProceso                               #    
#-------------------------------------------------------------------------#

    Allows you to delete a process from the queue structure. 
    The scheduler will invoke it when a certain process has finished its 
    execution.

    Parameters:
        - s is a pointer to the scheduler queues structure.
        - pid  is an integer that corresponds to the process identifier.
        - prio is a number from 0 to 5 and corresponds to the priority of the process.
*/

void ElimProceso(EstrucSched *s, long pid, short prio);

/*
#-------------------------------------------------------------------------# 
#                              ElimProcesoE                               #    
#-------------------------------------------------------------------------#

    Allows to remove from the queue structure, the last process that was 
    chosen for execution, the only one that is assigned in its state the 
    value in execution.

    Parameters:
        - s is a pointer to the scheduler queues structure.
*/

void ElimProcesoE(EstrucSched *s);

/*
#-------------------------------------------------------------------------# 
#                              ProxProceso                                #    
#-------------------------------------------------------------------------#

    Returns the next process to be scheduled.

    Parameters:
        - s is a pointer to the scheduler queues structure.
*/

proc *ProxProceso(EstrucSched *s)
{
	proc *procEjec;

	if (!queueEmpty(s[0].prioQueues))
	{
		procEjec = (proc *)deQueue(s[0].prioQueues);
		procEjec -> status = 'E';
		enQueue(s[0].prioQueues, &procEjec -> header);
	}

	if (!queueEmpty(s[1].prioQueues))
	{
		procEjec = (proc *)deQueue(s[1].prioQueues);
		procEjec -> status = 'E';
		enQueue(s[1].prioQueues, &procEjec -> header);
	}

	if (!queueEmpty(s[2].prioQueues))
	{
		procEjec = (proc *)deQueue(s[2].prioQueues);
		procEjec -> status = 'E';
		enQueue(s[2].prioQueues, &procEjec -> header);
	}
 
	if (!queueEmpty(s[3].prioQueues))
	{
		procEjec = (proc *)deQueue(s[3].prioQueues);
		procEjec -> status = 'E';
		enQueue(s[3].prioQueues, &procEjec -> header);
	}

	if (!queueEmpty(s[4].prioQueues))
	{
		procEjec = (proc *)deQueue(s[4].prioQueues);
		procEjec -> status = 'E';
		enQueue(s[4].prioQueues, &procEjec -> header);
	}

	if (!queueEmpty(s[5].prioQueues))
	{
		procEjec = (proc *)deQueue(s[5].prioQueues);
		procEjec -> status = 'E';
		enQueue(s[5].prioQueues, &procEjec -> header);

	}

	return procEjec;
}

/*
#-------------------------------------------------------------------------# 
#                              CambiarEstado                              #    
#-------------------------------------------------------------------------#

    Assigns the state to the process it receives as a parameter. 
    The possible newest values ​​are ready (L) or in execution.
    Normally invoked by the scheduler to indicate that a process has
    stopped running and returns to the ready state.

    Parameters:
        - s is a pointer to the scheduler queues structure.
        - p is a pointer to the data structure that stores information of 
            the process to be inserted. 
        - status is the state of the process. Ready(L) or in execution (E).
*/

void CambiarEstado(EstrucSched *s, proc *p, char newstatus) // anexar archivo readme
{
	p -> status = newstatus;
}

/*
#-------------------------------------------------------------------------# 
#                               loadQueues                                #    
#-------------------------------------------------------------------------#

    Load test data.

    Parameters:
        - fileName is a text file that has in each line information about 
            process.
        - scheduler is a pointer to the scheduler queues structure.
        - elem is a pointer to data structure that stores information of 
            the process.
*/

void loadQueues(char *filename, EstrucSched * scheduler, proc * elem)
{
    char buf[40];
    FILE * ifp = fopen(filename,"r");

        
    do{
        fscanf(ifp,"%li %c %hi %f %s", &elem -> pid, &elem -> status, 
        &elem -> prio, &elem -> ptime, elem -> command);
        
        InsertarProceso(scheduler, elem, elem -> prio);
        printf("proceso: %li insertado\n", elem -> pid);
        
        elem++;
        while((elem = (proc *)malloc(sizeof(proc)))==NULL) {
        //Check correct memory allocation
            printf("Not enough memmory, waiting for more");
            sleep(3);
        }
    } while(fgets(buf,sizeof buf, ifp)!= NULL);
    
    
    fclose(ifp);
}


/*
#-------------------------------------------------------------------------# 
#                                Construye                                #    
#-------------------------------------------------------------------------#

    Receives the name of the test file builds in the memory the queue 
    structure of the scheduler. Once the structure of queues is constructed,
    it returns a pointer to it.

    Parameters:
        - filename is a text file that has in each line information about 
            process.
*/


EstrucSched *Construye(char *filename)
{
    int numQueues = 6;  
    EstrucSched *structQueues = malloc(numQueues * sizeof(EstrucSched));
   
    return structQueues;
}

/*
#-------------------------------------------------------------------------# 
#                               imprQueue                                 #    
#-------------------------------------------------------------------------#

    Prints the current status of queue.

    Parameters:
        - impqueue is a pointer to queues.
*/

void imprQueue(queue *impqueue)
{
	proc *aux;
	for (aux = (proc *)queueStart(impqueue);aux;
		 aux=(proc *) queueNext(&aux->header))
	{
		printf("%li %c %hi %f %s\n", aux-> pid, aux -> status, 
			aux -> prio, aux -> ptime, aux -> command);
	}
}

/*
#-------------------------------------------------------------------------# 
#                                 Imprime                                 #    
#-------------------------------------------------------------------------#

    Prints the current status of queue structure by the standard output.

    Parameters:
        - s is a pointer to the scheduler queues structure.
*/

void Imprime(EstrucSched *s)
{
	int i=0;

	while (i < 6)
	{
		if (!queueEmpty(s[i].prioQueues))
		{
			imprQueue(s[i].prioQueues);
		}
		i++;
	}
}


int main (int argc, char * argv[])

{
    int numQueues = 6;  
    EstrucSched *structQueues = malloc(numQueues * sizeof(EstrucSched));
    proc * aux = malloc( sizeof(proc));
    
    queue q0;
    queue q1;
    queue q2;
    queue q3;
    queue q4;
    queue q5; 
            
    queueInit(&q0);
    queueInit(&q1);
    queueInit(&q2);
    queueInit(&q3);
    queueInit(&q4);
    queueInit(&q5);

    structQueues[0].prioQueues = &q0;
    structQueues[1].prioQueues = &q1;
    structQueues[2].prioQueues = &q2;
    structQueues[3].prioQueues = &q3;
    structQueues[4].prioQueues = &q4;
    structQueues[5].prioQueues = &q5;
	
    loadQueues ("datos",structQueues, aux);

	

}