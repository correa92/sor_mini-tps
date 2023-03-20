#include <stdio.h>
#include <unistd.h>
#include <time.h>

int ejecuciones=1;

void calculo_aritmetico(){
	int contador=0;
	while(contador<2147483647){
		contador=contador+1;
	}
	printf("ejecucion n°: %d \n",ejecuciones);
	ejecuciones++;
	
}

int main(){
	calculo_aritmetico();
	calculo_aritmetico();
	calculo_aritmetico();
	calculo_aritmetico();
	calculo_aritmetico();
	return 0;

}
