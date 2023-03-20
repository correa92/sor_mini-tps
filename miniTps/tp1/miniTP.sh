#!/bin/bash

#si la ejecucion no tiene parametros entonces lanzo un error
if [ $# -eq 0 ]; then
	echo "Error, debe ingresar un parametro"
	exit

else 
	#creo el directorio
	$(mkdir $HOME/$1)
	
	#selecciono los elementos que necesito y los almaceno en un archivo especifico
	$(ls -a -l $HOME > $HOME/$1/contenido_home.txt)
	
	#muestro el contenido
	cat $HOME/$1/contenido_home.txt
	
	echo "Presione enter para terminar"
	read input
	
	#si no oprime solo el enter, vuelvo a pedirle al usuario que solo oprima enter
	while [[ $input != "" ]]; do
		echo "Por favor, presione enter para terminar"
		read input
		done
		
	echo "Adios!"
	exit
	
fi



