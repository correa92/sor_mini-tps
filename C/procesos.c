#include <sys/types.h>  
#include <sys/wait.h>
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h>

int main (int argc, char *argv[]) { 
	pid_t pid;
	
	//system call fork
	//fork() retorna cero al proceso hijo.
	//fork() retorna el id del hijo (un entero positivo) al proceso padre. 
	//fork() retorna un numero negativo si hubo un error
	pid = fork(); 
	
	//a partir de este punto dos procesos ejecutan las mismas instrucciones
	printf ("\n Hola \n"); 
		
	//Si soy el proceso hijo
	if (pid == 0){
		printf ("Soy el proceso hijo \n "); 
	}
	else if (pid > 0){
		printf ("\n Soy el proceso padre \n ");
    	}else{
		printf ("\n Hubo un error"); 	
	}

	//system call wait
	//espera a que el proceso hijo termine
	int status;
    	wait(&status); 
    	
	return 0; 
} 

//Compilar gcc ejercicio1a-Fork.c -o ejercicio1a-Fork
//Ejecutar ./ejercicio1a-Fork
