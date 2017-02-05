#include "pschedulerLib.h"
#include "options.h"



int main (int argc, char * argv[])
{
    int opt;
    int numQueues = 6;  
    EstrucSched *structQueues = malloc(numQueues * sizeof(queue) + sizeof(EstrucSched));
    structQueues -> pr_ejec = NULL;

    proc * aux = malloc( sizeof(proc));
    proc * pr_pruebas;

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
    loadQueues("datos",structQueues,aux);

    system("cls");
    system("clear");

    printf("                             dP                      dP          dP                   \n");   
    printf("                             88                      88          88                   \n");
    printf("  88d888b. .d8888b. .d8888b. 88d888b. .d8888b. .d888b88 dP    dP 88 .d8888b. 88d888b. \n");
    printf("  88    88 Y8ooooo. 88    ·· 88    88 88ooood8 88    88 88    88 88 88ooood8 88    88 \n");
    printf("  88.  .88       88 88.  ... 88    88 88.  ... 88.  .88 88.  .88 88 88.  ... 88       \n");
    printf("  88Y888P' `88888P' `88888P' dP    dP `88888P' `88888P8 `88888P' dP `88888P' dP       \n");
    printf(" ~88~ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n");
    printf("  dP                                                                                  \n");

    printf("                   ===============================================                    \n"); 
    printf("                  |            Planificador de procesos           |                   \n");
    printf("                   ===============================================                    \n"); 
    printf("                           Bienvenido al Menu de opcciones:                           \n");
    while(1)
    {
        printf(" \n");
        printf("==================================================================== \n"); 
        printf("| * Introduzca 0 para insertar                                      |\n");
        printf("| * Introduzca 1 para eliminar                                      |\n");
        printf("| * Introduzca 2 para eliminar proceso en ejecucion                 |\n");
        printf("| * Introduzca 3 para cambiar estado del proceso                    |\n");
        printf("| * Introduzca 4 para visulizar en pantalla el estado de las colas  |\n");
        printf("| * Introduzca 5 salir del programa                                 |\n");
        printf("==================================================================== \n"); 
        
        printf(" \n");
        printf("Introduzca una opcion \n");
        printf(">> \n");
        fflush(stdout); //vacíamos el buffer de salida
        scanf("%d", &opt);
        executeOption(opt,structQueues,argv[2]);
    }
	
}