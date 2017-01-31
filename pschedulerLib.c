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


void InsertarProceso(EstrucSched *s, proc *p, short prio)
{
	
	switch(prio)
	{
		case 0:
			enQueue(&s -> prioQueues[0], &p -> header);
			break;

		default:
			break;
	}
}

int main (int argc, char * argv[])

{
	int numQueues = 6;	
	EstrucSched * structQueues = malloc(numQueues * sizeof(EstrucSched));
	queue q0;
	queue q1;
	queue q2;
	queue q3;
	queue q4;
	queue q5; 
	proc * item1;
	proc * item2;
	proc * item3;
	proc * aux;

	structQueues[0].prioQueues = &q0;
	structQueues[1].prioQueues = &q1;
	structQueues[2].prioQueues = &q2;
	structQueues[3].prioQueues = &q3;
	structQueues[4].prioQueues = &q4;
	structQueues[5].prioQueues = &q5;


	item1 = (proc *)malloc(sizeof(proc));
	item2 = (proc *)malloc(sizeof(proc));
	item3 = (proc *)malloc(sizeof(proc));

	crearProceso(item1,1111,0);
	crearProceso(item2,2222,2);
	crearProceso(item3,3333,3);
	InsertarProceso (structQueues,item1,item1 -> prio);

	aux = (proc *)deQueue(&structQueues -> prioQueues[0]);
	printf("Proceso insertado correctamente: %ld\n", aux -> pid);
/*
*/
	
}