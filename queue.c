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

/*
#-------------------------------------------------------------------------# 
#                                queueInit                                #    
#-------------------------------------------------------------------------#

    Initializes the queues structure.

    Parameters:
        - container is a pointer to a global queue.
*/

void queueInit (queue * container)
{
	container -> first = 0;
	container -> last = 0;
	container -> lenght = 0;
}

/*
#-------------------------------------------------------------------------# 
#                               queueEmpty                                #    
#-------------------------------------------------------------------------#

    Return True if the queue is empty, False otherwise.

    Parameters:
        - container is a pointer to a global queue.
*/

bool queueEmpty (queue * container)
{
	return 0 == container -> lenght;
}

/*
#-------------------------------------------------------------------------# 
#                               queueStart                                #    
#-------------------------------------------------------------------------#

    Returns the first element of queue.

    Parameters:
        - container is a pointer to a global queue.
*/

elemQueue * queueStart (queue * container)
{
	return container -> first;
}

/*
#-------------------------------------------------------------------------# 
#                                 queueNext                               #    
#-------------------------------------------------------------------------#

    Returns the next element in queue.

    Parameters:
        - elem is a pointer to the elemQueue structure.
*/

elemQueue * queueNext(elemQueue * elem)
{
	return elem -> next;
} 

/*
#-------------------------------------------------------------------------# 
#                                   enQueue                               #    
#-------------------------------------------------------------------------#

    Add elements to tail of queue.

    Parameters:
        - elem is a pointer to the elemQueue structure.
        - container is a pointer to a global queue.
*/

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

/*
#-------------------------------------------------------------------------# 
#                                   deQueue                               #    
#-------------------------------------------------------------------------#

    Extract an element at head of queue to use it.

    Parameters:
        - container is a pointer to a global queue.
*/

elemQueue * deQueue(queue * container)
{
	elemQueue * elem = container -> first;
	container -> first = container -> first -> next;
	container -> lenght -= 1;
	return elem;
}

/*
#-------------------------------------------------------------------------# 
#                                 queueLenght                             #    
#-------------------------------------------------------------------------#

    Returns the length of queue.

    Parameters:
        - container is a pointer to a global queue.
*/

int queueLenght (queue * container)
{
	return(container -> lenght);
}

