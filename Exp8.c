#include <stdio.h>
#include <stdlib.h>
#include <string.h> // libreria para usar strncpy
/*
Nombre: Camila Castillo
//NOTA: 5 (creo que nadie lo pudo hacer en el lab, pero si uno lo enviaba completo te subian la nota)

ACTIVIDAD: En el area de informatica de una farmaceutica necesitan revisar grandes listas de datos de sus clientes. La empresa necesita verificar si es que
existen clientes dentro de su base de datos que tengan edades determinadas. Para esto, se requiere crear un programa que reciba como entrada la edad a buscar, y que
entregue como salida un mensaje. Para el caso en que si encuentre a alguien con la edad especificada, debe escribir por consola "Si hay clientes de edad %d, el nombre 
de uno de ellos es %s" y en caso que no se encuentre a nadie, debe escribir por consola " No existen clientes de la edad %d". 
Este ejercicio se debe realiziar utilizando division y conquista. Para esto, suponga que cuenta con un arreglo de un tipo de dato "Persona" ordenado por edad. 

*/


struct persona {  // Se define el struct que contendrá un dato tipo char de nombre y un dato tipo entero de edad
	
	char nombre[50];
	int edad;
};

typedef struct persona pers; 

/*
Funcion llamada division que dado el puntero del arreglo de struct definido ahora como pers, el indice de inicio y del final y con un numero buscado
retorna el indice de donde se encuentra el elemento en coincidencia. Para esto divide los indices del arreglo de edad, buscando el punto medio del arreglo. Trabajando con la mitad
donde se puede encontrar el int buscado.   
*/

int division(pers *arreglo, int inicio, int fin, int buscado){ 
	
	int medio=(inicio+fin)/2; //punto medio

	if (inicio ==fin){ // por si hay solo un elemento 
		if (arreglo[0].edad==buscado){ // si es igual al buscado 
			return 0;   // entonces retorna el valor del indice = 0
		}
		return 22;  // si hay solo un elemento en el arreglo, y NO es igual, entonces retorna 22 (valor de retorno aleatorio y personal, y que mayor a los indices del arreglo)
	}

	else if (arreglo[medio].edad== buscado){ // si el de al medio justo es el buscado,
		return medio; 		// retorna el int medio 
	}
	
	else{  // en otro caso se volverá a llamar a la funcion siempre que 
		
		if(arreglo[medio].edad>buscado){ //si el del medio es mayor al buscado, se busca por el lado izquierdo del arreglo de edades
			return division(arreglo, inicio, medio, buscado); // ahora se llama la funcion pero solo con la parte izquierda 
		}
		else {     // caso contrario va por el lado derecho del arreglo
			return division (arreglo, (medio)+1, fin, buscado);  // ahora se llama la funcion pero solo con la parte derecha	
		}

	}
}



int main(){
	
	int edading, eleccion =1; 
	int resultado, salida;
	pers personas[8];   // un arreglo de struct que contendrá 8 personas
	
	strncpy(personas[0].nombre, "Ignacia Albornoz", 50); // se agrega el nombre al arreglo de strings nombre
	personas[0].edad= 8;                 // se agrega la edad al arreglo de enteros edad
	
	strncpy(personas[1].nombre, "Elias Gonzalez", 50);
	personas[1].edad= 24;
	
	strncpy(personas[2].nombre, "Pedrito Perez", 50);
	personas[2].edad= 30;
	
	strncpy(personas[3].nombre, "Francisca Castillo", 50);
	personas[3].edad= 14;
	
	strncpy(personas[4].nombre, "Zoila Cerda", 50);
	personas[4].edad= 44;
	
	strncpy(personas[5].nombre, "Juan Jimenez", 50);
	personas[5].edad= 45;
	
	strncpy(personas[6].nombre, "Elsa Pato", 50);
	personas[6].edad= 54;
	
	strncpy(personas[7].nombre, "Jorge Gonzalez", 50);
	personas[7].edad= 56;
	
while (eleccion==1){ // menu de eleccion solo para no iniciar el programa cada vez que se quiere ver si coincide alguna edad
 
	printf("Ingrese la edad:\n");
	scanf("%d", &edading);  // se guarda la edad ingresada en la variable edading

	if(personas[7].edad < edading){ // se coloca esta condicion para saber que si la edad ingresada es mayor al mayor del arreglo edad, entonces si se cumple de por si la edad no se encuentra (como esta vez es con datos de edad conocidos, se sabe cual es el mayor) 
		printf("No existen clientes de la edad %d", edading);
		printf("\n");
	}

	else{   // si edading es menor que el mayor del arreglo, entonces:
		
		resultado= division(personas, 0, 7, edading); // se guarda en resultado el valor retornado de la funcion division, con el arreglo, inicio, final, edading)
		

		if (resultado ==22){  // si resultado es 22, se sabe que no hay coincidencia
			printf("No existen clientes de la edad %d", edading);
			printf("\n");
			printf("\n");
		}
		else {  // si no es 22 entonces, existe una coincidencia, se obtiene el indice y se retorna, el nombre que refiere a el nombre de esa persona con ese indice
			printf("Si hay clientes de edad %d, el nombre de uno de ellos es %s", personas[resultado].edad, personas[resultado].nombre);
			printf("\n");
			printf("\n");
			
		}
	}

printf("PRESIONE 1 si desea SALIR del programa");  // se hace una opcion para salir del programa
printf("\n");
printf("PRESIONE 2 si desea CONTINUAR en programa"); // o para continuar...
printf("\n");
printf("->");
scanf("%d",&salida);


	if (salida==1){
		eleccion=0; // se termina el programa
	}
	else{
		eleccion=1; // sigue el ciclo while
	}
}
return 0;


}