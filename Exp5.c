#include<stdio.h>
#include<stdlib.h>
// NOMBRE CAMILA CASTILLO
//NOTA: 3 (en el lab solo hice la recursion de pila, y después hice las demás en mi casa, el código está completo)
// Actividad: Crear una funcion que sea por recursion por cola y una por pila que muestre por pantalla los numeros de tribonacci hasta la posicion entregada por el usuario. 
// Además, hacer la funcion de tribonacci de manera recursiva

int tribo (int n){

    if (n==0 || n==1)
    	return 0;

    else if(n==2)
    	return 1;

    else 
    	return (tribo(n-1) + tribo(n-2)+ tribo(n-3));
}

int tribo2(int n,int t1,int t2, int t3)
{
    if(n==0||n==1)  //caso base
		return t1;
	else if (n==2) // caso base
		return t2;
	else 
		return tribo2(n-1,t2,t3,t1+t2+t3);         // igual que en la iteracion, t2 ahora es t1, t2 es t3 y el t3 es la suma de los anteriores.
}


int main (){

	int numero; 
	int respuesta;
	int respuesta2;
	int t1=0;
	int t2=1;
	int t3=1;
	int i=0;
	
	printf("Ingrese un numero: \n");
	scanf("%i", &numero);

	printf("Los numeros de Tribonacci son:");

// DE MANERA RECURSIVA

for(i; i<numero; i++){
		
	if (i==0 || i==1){ 					// caso base
		respuesta2=0;
		}
	else if(i==2){                     // caso base
		respuesta2=1;
	}
	else{
		
		respuesta2=t1+t2+t3; // siendo la respuesta2 inicial, se suman los 3 primeros, 0+0+1 =1 
		t1=t2; // t1 ahora es t2, se corre una posicion
		t2=t3;// t2 ahora es t3, se corre una posicion
		t3=respuesta2; // t2 ahora tendra el resultado (como un acumulador)
		}

	
	printf( " %i " , respuesta2);
    	
    
}
	printf("\n");
	respuesta = tribo(numero); // de pila con la funcion de arriba
	printf("EL numero de Tribonacci es: %i", respuesta );
	printf("\n");
	
	respuesta2 = tribo2(numero+1, 0, 0, 1); // por cola con la funcion de arriba
	printf("EL numero de Tribonacci es: %i", respuesta2 );
	

return 0;
}