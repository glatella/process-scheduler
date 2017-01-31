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

typedef struct 
{
	elemQueue header;
	long  pid;
	char estated;
	short prio;
	float time;
	char comand[20];
}proc;

typedef struct 
{
	queue *prioQueues; 
}EstrucSched;