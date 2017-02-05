/*
# ----------------------------------------------------------------------------#
#                                options.c                                    #
# ----------------------------------------------------------------------------#
#                         Universidad Simón Bolívar                           #
#            Departamento de Computación y Tecnología de la Información       #
#                     Laboratorio de Sistemas Operativos                      #
#              Profesora Angela Di Serio y Profesor Carlos Gomez              #
#                          Giuli Latella carnet: 08-10596                     #
#                        Honorio Rodriguez carnet: 09-11023                   #
#                                 Grupo: O                                    #
#		        Ult. Fecha de modificación: 4 de febrero 2017                 #
# ----------------------------------------------------------------------------#
# ----------------------------------------------------------------------------#
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/dir.h>
#include "pschedulerLib.h"
#include "options.h"



/*
#-------------------------------------------------------------------------# 
#                           executeOption                                 #    
#-------------------------------------------------------------------------#

    Allows to call the funtion for do the option to put into by user.
    Once identify de option, the case allows to call the funtion correct and
    obtain the necesary parameters.

    Parameters:
        - s is a pointer to the scheduler queues structure.
        - option is a string with de option and the diferents necesary parameters.
        - name is a string with the name of the file whit the out of the program.
*/

void executeOption(int opt, EstrucSched *s, char *name)
{
	int i;
	proc *p = malloc( sizeof(proc));
	long  pid;        // Integer that corresponds to the process identifier.
	char status;      // State of the process. Ready(L) or in execution (E).
	short prio;       // Is a number from 0 to 5.
	float ptime;       // Cumulative execution time, is a real number.
	char command[20]; // Command name.

   	switch (opt)
	{
		case 0:

			fflush(stdout);	

			printf("Introduzca por favor el proceso a insertar \n");
			printf("siguiendo el presente formato: \n");
			printf(">> Pid Prioridad Tiempo Comando \n");
			printf(" NOTA!: recuerde que la prioridad es una valor entre 0 y 5 ");
        	printf(">> ");	
			printf(" \n");
			
			i=0;

			p -> status = 'L';

			if (scanf ("%li %hi %f %s", &p -> pid, &p -> prio, 
				&p -> ptime, p -> command) == 4)
			{
				printf("Insertando proceso. Por favor espere... \n");
				
				InsertarProceso(s,p,p -> prio);
				
				sleep(3);
				printf("\n ¡Proceso insertado exitosamente! \n");

			}
			break;

		case 1:

			fflush(stdout);	

			printf("Introduzca por favor el proceso a eliminar \n");
			printf("siguiendo el presente formato: \n");
			printf(">> Pid Prioridad \n");
			printf(" NOTA!: recuerde que la prioridad es una valor entre 0 y 5 ");
        	printf(">> ");	
			printf(" \n");
			
			i=0;
			i = scanf ("%li %hi ", &p -> pid, &p -> prio); 
				
			if (i==2)
			{
				printf("Eliminando proceso. Por favor espere...\n");
				
				ElimProceso(s, p -> pid, p -> prio);
				
				sleep(3);
				printf("\n ¡Proceso eliminado exitosamente! \n");
			}
			break;
		
		case 2:

			fflush(stdout);	

			printf("Eliminando proceso en ejecucion. Por favor espere...\n");
				
			ElimProcesoE(s);
				
			sleep(3);
			printf("\n ¡Proceso en ejecucion eliminado exitosamente! \n");
			
			break;
		

		case 3:

			fflush(stdout);	

			printf(" Cambiando estado del proceso. Por favor espere... \n");
			printf(" \n");
									
			CambiarEstado(s,p,status);

			sleep(3);
			printf("\n ¡Estado del proceso modificado exitosamente! \n");

			break;
				
		case 4:

			fflush(stdout);	

			printf("El estado actual de las colas es: \n");
			printf(" \n");	
						
			Imprime(s);
			
			break;
				
		case 5:

			fflush(stdout);	

			writeFile(s);	
			
			exit(0);
			
		default:
            break;
	}
}