#include <stdio.h>
/*
Nombre: Camila Castillo
ACTIVIDAD: Utilizar variables para guardar, el nombre, la edad y el año de nacimiento. Luego hacer un print de esas variables con el texto:
"Hola (variable nombre), tu naciste en (variable año) y tu edad es (variable edad)"
*/


int main(){ 
	
	char* nombre="Camila";
	int edad=28;
	int fecha=1994;
	
	printf("Hola %s, tu naciste en %i y tu edad es %i\n", nombre, fecha, edad);
	return 0;
	
	
	
	
}