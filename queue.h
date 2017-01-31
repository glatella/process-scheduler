/*
# ----------------------------------------------------------------------------#
#                                    queue.h                                  #
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


void queueInit (queue * container);

bool queueEmpty (queue * container);

elemQueue * queueStart (queue * container);

elemQueue * queueNext(elemQueue * elem);

void enQueue (queue * container, elemQueue * elem);

elemQueue * deQueue(queue * container);

int queueLenght (queue * container);


