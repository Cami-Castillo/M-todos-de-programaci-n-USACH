#include<stdio.h>
#include <time.h> 

int pascal(int f, int c){  // funcion que dado una fila y una columna, entonces retorna el valor en esa posición
	
	if (f==c){              // significa que es el último entonces retorna 1
		
		return 1;
	}
	else if (c==1){         // significa que es el primero , entonces retorna 1
		
		return 1;
	}		
	else if (c>f){          // significa que la posicion buscada no es valida, ya que una fila tiene igual numero de columnas
		return 0;
	}
	
	else {                  // retorna las sumas de posiciones anteriores de f y c, con la posicion f-1, c hasta llegar al caso base
		return pascal(f-1,c-1) + pascal(f-1, c);
	}
	
}
	
int main (){
	
	int fila;
	int columna; 
	int resultado, resultado2;
	int k, i, j;
	int salida;
	int fact, fact2, fact3;
	int x=0;	
	
while (x==0){
	

	printf("Ingrese fila: "); 
	scanf("%i", &fila);
	printf("\n");
	
	printf("Ingrese columna: ");
	scanf ("%i", &columna);
	printf("\n");
	time_t ini1=time(NULL);
	resultado = pascal(fila, columna);
	time_t fin1=time(NULL);
	
	
		if (resultado ==0){ 
			printf("La posicion no existe \n");
		}
		else{
			printf("EL RESULTADO ES : %d \n", resultado);
		}
		
	printf("El tiempo utilizado en este resultado fue de : %f\n", difftime(fin1,ini1));
	printf("\n");
	
	for(i=1;i<=fila;i++){
	
		fact=fact*i;
	}
	for(j=1; j<=columna; j++){
		fact2=fact2*j;
	}
	for (k=1; k<=(fila-columna); k++){
		fact3=(fila-columna)*k;

	}	

	resultado2 = fact/fact2*fact3;

	time_t ini2=time(NULL);
	printf("El valor es: %i\n", resultado);
	time_t fin2=time(NULL);
	
	printf("El tiempo utilizado en este resultado fue de : %f\n", difftime(fin2,ini2));
	
	

	printf("SALIR?\n");
	printf("Pulse '1'  para SI\n");
	printf("Pulse '2'  para NO\n: ");
	scanf("%i", &salida);
	
	if (salida==1){
		x=1;
	}
	
	else if (salida==2){
		x=0;
		
	}
}
	return 0;
}

