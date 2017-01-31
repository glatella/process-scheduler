/*
# ----------------------------------------------------------------------------#
#                                    queue.c                                  #
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

#include "queue.h"

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

