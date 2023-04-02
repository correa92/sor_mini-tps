#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

//Equipo AB
sem_t sem_A;
sem_t sem_B;

//Equipo CD
sem_t sem_C;
sem_t sem_D;

//Equipo EF
sem_t sem_E;
sem_t sem_F;

int posicion = 1;


void* calculo_aritmetico(void* parametro){
	int contador=0;
	while(contador<2147483647){
		contador=contador+1;
	};
};

void* corriendo(void* parametro){
	//printf("inicia el atleta %s \n\n",parametro);
	
	if(strcmp(parametro,"A")==0){
		sem_wait(&sem_A);
			calculo_aritmetico(parametro);
		sem_post(&sem_B);
		printf("El atleta '%s' llega a su destino",parametro);
		printf(" y habilita al atleta B\n");
	};
	
	if(strcmp(parametro,"B")==0){
		sem_wait(&sem_B);
			calculo_aritmetico(parametro);
			if(posicion == 1){
				printf("	Gano el equipo AB \n");
				posicion++;
			} else {
			printf("El equipo AB obtuvo la posicion %d \n",posicion);
			posicion++;
			};
	};
	
	if(strcmp(parametro,"C")==0){
		sem_wait(&sem_C);
			calculo_aritmetico(parametro);
		sem_post(&sem_D);
			printf("El atleta '%s' llega a su destino",parametro);
			printf(" y habilita al atleta D\n");

	};
	
	if(strcmp(parametro,"D")==0){
		sem_wait(&sem_D);
			calculo_aritmetico(parametro);
		if(posicion == 1){
				printf("	Gano el equipo CD \n");
				posicion++;
			} else {
			printf("El equipo CD obtuvo la posicion %d \n",posicion);
			posicion++;
			};
	};
	
	if(strcmp(parametro,"E")==0){
		sem_wait(&sem_E);
			calculo_aritmetico(parametro);
		sem_post(&sem_F);
			printf("El atleta '%s' llega a su destino",parametro);
			printf(" y habilita al atleta F\n");
	};
	
	if(strcmp(parametro,"F")==0){
		sem_wait(&sem_F);
			calculo_aritmetico(parametro);
		if(posicion == 1){
				printf("	Gano el equipo EF \n");
				posicion++;
			} else {
			printf("El equipo EF obtuvo la posicion %d \n",posicion);
			posicion++;
			};
	};

	pthread_exit(NULL);
};



void main(){
	// Atletas principales
	sem_init(&sem_A,0,1);
	sem_init(&sem_C,0,1);
	sem_init(&sem_E,0,1);
	
	// Atletas secundarios
	sem_init(&sem_B,0,0);
	sem_init(&sem_D,0,0);
	sem_init(&sem_F,0,0);
	

	//Nombre de los hilos
	pthread_t atleta_A;
	pthread_t atleta_B;
	pthread_t atleta_C;
	pthread_t atleta_D;
	pthread_t atleta_E;
	pthread_t atleta_F;
	
	char* atletaA = "A";
	char* atletaB = "B";
	char* atletaC = "C";
	char* atletaD = "D";
	char* atletaE = "E";
	char* atletaF = "F";
	
	printf("Comenzando Carrera...\n\n");
			
	//Creacion de los hilos
	pthread_create(&atleta_A,NULL,corriendo,atletaA);
	pthread_create(&atleta_B,NULL,corriendo,atletaB);
	pthread_create(&atleta_C,NULL,corriendo,atletaC);
	
	pthread_create(&atleta_D,NULL,corriendo,atletaD);
	pthread_create(&atleta_E,NULL,corriendo,atletaE);
	pthread_create(&atleta_F,NULL,corriendo,atletaF);
	
	
	//espera a que finalice el hilo
 	pthread_join(atleta_A,NULL);
	pthread_join(atleta_B,NULL); 
	pthread_join(atleta_C,NULL); 
	pthread_join(atleta_D,NULL); 
	pthread_join(atleta_E,NULL); 
	pthread_join(atleta_F,NULL); 
	
	printf("\n\nCarrera terminada... \n");
		
	return;

}
