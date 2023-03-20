#include <stdio.h>

int sumar(int *a, int *b){
	return (*a + *b);
}

int restar(int *a, int *b){
	return (*a - *b);
}

int multiplicar(int *a, int *b){
	return (*a * *b);
}

double dividir(double *a, double *b){
	return (*a / *b);
}


void main(){

	int num1, num2;
	double numR1,numR2;
	
	printf("Ingrese el primer valor:");
	scanf("%d",&num1);
	printf("Ingrese el segundo valor:");
	scanf("%d",&num2);
	
	int suma=sumar(&num1,&num2);
	
	printf("Resultado: %d + %d = %d \n",num1,num2,suma);
		
	int resta= restar(&num1,&num2);
	
	printf("Resultado: %i - %i = %i \n",num1,num2,resta);
	
	int mult=multiplicar(&num1,&num2);
	
	printf("Resultado: %i X %i = %i \n",num1,num2,mult);
	
	numR1 = num1;
	numR2 = num2;
	
	double div=dividir(&numR1,&numR2);
	
	printf("Resultado: %i / %i = %lf \n",num1,num2,div);
}
