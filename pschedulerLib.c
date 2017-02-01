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


void crearProceso(proc * p,long pid, short prio) 
{

    p -> pid = pid;
    p -> prio = prio;
}

/*
#-------------------------------------------------------------------------# 
#                           InsertarProceso                               #    
#-------------------------------------------------------------------------#

    Allows you to insert a process in one of the priority queues. 
    The processes will be inserted at the end of the queue that corresponds.

    Parameters:
        - s is a pointer to the scheduler queues structure.
        - p is a pointer to the data structure that stores information of 
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

proc *ProxProceso(EstrucSched *s);

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

void CambiarEstado(EstrucSched *s, proc *p, char status); // anexar archivo readme

/*
#-------------------------------------------------------------------------# 
#                                InitQueue                                #    
#-------------------------------------------------------------------------#

    Initializes the queues structure.

    Parameters:
        -strucQueues is a pointer to the scheduler queues structure.   
*/

void initQueues(EstrucSched * structQueues)
{
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
*/

void loadQueues(char *filename, EstrucSched * scheduler)
{
    FILE * ifp = fopen(filename,"r");
    proc * elem;
    elem = (proc *)malloc(sizeof(proc));
    
    while (fscanf(ifp,"%li %c %hi %f %s", &elem -> pid, &elem -> status, 
        &elem -> prio, &elem -> ptime, elem -> command) != EOF);
    {
        InsertarProceso(scheduler, elem, elem -> prio);
        
        elem++;
        
        while((elem = (proc *)malloc(sizeof(proc)))==NULL) 
        //Check correct memory allocation
        {
            printf("Not enough memmory, waiting for more");
            sleep(3);
        }
    }
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
   
    initQueues(structQueues);

    loadQueues ("datos",structQueues);

    return structQueues;
}


/*
#-------------------------------------------------------------------------# 
#                                 Imprime                                 #    
#-------------------------------------------------------------------------#

    Prints the current status of the queue structure by the standard output.

    Parameters:
        - s is a pointer to the scheduler queues structure.
*/

void Imprime(EstrucSched *s);



int main (int argc, char * argv[])

{
    int numQueues = 6;  
    EstrucSched *structQueues = malloc(numQueues * sizeof(EstrucSched));
    proc * aux;

    //initQueues(structQueues);
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

    proc *item1 = (proc *)malloc(sizeof(proc));
    crearProceso(item1,1111,5);
    InsertarProceso(structQueues, item1, item1 -> prio);

    //loadQueues ("datos",structQueues);
    
    //EstrucSched *structQueues = Construye("datos");    
    
    aux = (proc *)deQueue(structQueues[5].prioQueues);
    printf("Proceso insertado correctamente: %li ", aux -> pid);

}