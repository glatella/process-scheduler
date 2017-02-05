/*
# ----------------------------------------------------------------------------#
#                                pschedulerLib.h                              #
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

/*
#-------------------------------------------------------------------------# 
#                                   proc                                  #    
#-------------------------------------------------------------------------#

	Process structure that defines the shape of the element to be used in 
	the queue.
*/

typedef struct 
{
	elemQueue header; // Pointer to the following items in the queue.
	long  pid;        // Integer that corresponds to the process identifier.
	char status;      // State of the process. Ready(L) or in execution (E).
	short prio;       // Is a number from 0 to 5.
	float ptime;       // Cumulative execution time, is a real number.
	char command[20]; // Command name.
}proc;

/*
#-------------------------------------------------------------------------# 
#                               EstrucSched                               #    
#-------------------------------------------------------------------------#

	Planner queue structure.
*/

typedef struct 
{
	queue *prioQueues; 
	proc  * pr_ejec;
}EstrucSched;


proc *  ProcEnEjec(EstrucSched * s);

void InsertarProceso(EstrucSched *s, proc *p, short prio);

void  ElimProceso(EstrucSched *s, long pid, short prio);

void ElimProcesoE(EstrucSched *s);

proc * ProxProceso(EstrucSched *s);

void CambiarEstado(EstrucSched *s, proc *p, char newstatus);

void loadQueues(char *filename, EstrucSched * scheduler, proc * elem);

EstrucSched *Construye(char *filename);

void imprQueue(queue *impqueue);

void Imprime(EstrucSched *s);

void writeFile (EstrucSched * s);