#include <stdio.h>
#include <stdlib.h>

//NOTA : 5 (no lo logré hacer todo lo que me pedian)
/*Escribir un programa que defina una estructura que permita almacenar datos de los productos a la venta de un almacen*
Nombre, numero de serie, precio, peso, volumen, cantidad disponible

1) Cree una funcion que pida por pantalla los datos al usuario y guarde la información en una estructura, por ejemplo: 

Nombre: Mermelada de naranaja pepito
Numero de serie: 543543
Precio: 384
Peso: 250
Volumen: 100
Cantidad disponible: 10

2) Cree una funcion que repita como parametro de entrada una estructura "Producto" e imprima por pantalla los valores de cada una de sus características

3) Implemente un menú en donde el usuario pueda 
	1. Ingresar un producto al sistema
	2. Listar todos los productos que estan en el sistema con disponibilidad
	3. Buscar un producto por su nombre o numero de serie y mostrar toda su información
	4. Cerrar el programa. El programa solo debe cerrar con esta opción (muestre un mensaje de despedida)

** Si el usuario muestra otra opción numérica indicar que esta opción no existe
** El programa debe volver a mostrar el menú de opciones y volver a funcionar en caso de usar una opción del 1 al 3 con una opción erronea */ 



struct producto{			// Se define el struct

	char*nombre;       // Genero un puntero a la direccion de memoria de nombre
	int numerodeserie; 
	int precio;
	int peso; 
	int volumen;
	int cant;
	
};

typedef struct producto prod;     //Al struct le doy un tipo de dato, que ahora se llamará prod

//Funcion pedir datos 

prod pedir(){			

	
	prod producto1;                                                //Al tipo de dato prod le coloco como nombre producto1
	producto1.nombre = (char*)malloc(sizeof(char)*70);              //Reservo una memoria para la variable nombre del producto1
	printf("Ingrese el nombre del producto: \n");
	scanf("%s", producto1.nombre);
	printf("Ingrese el numero de serie: \n");
	scanf("%d", &producto1.numerodeserie);
	printf("Ingrese el precio: \n");
	scanf("%d", &producto1.precio);
	printf("Ingrese el peso: \n");
	scanf("%d", &producto1.peso);
	printf("Ingrese el volumen: \n");
	scanf("%d", &producto1.volumen);
	printf("Ingrese la cantidad: \n");
	scanf("%d", &producto1.cant);

	return producto1;
}

// Imprimir por pantalla

void imprimir (prod a){
	
	printf("El nombre del producto es:%s \n",a.nombre);
	printf("El numerodeserie del producto es:%d \n",a.numerodeserie);
	printf("El precio del producto es:%d \n",a.precio);
	printf("El peso del producto es:%d \n",a.peso);
	printf("El volumen del producto es:%d \n",a.volumen);
	printf("El cantidad del producto es:%d \n",a.cant);

}

int main(){

	int salir=0;
	int eleccion; 
	prod producto_nuevo;
	prod mostrar_producto;
	char*producto;
	
		printf("\n");
		printf("MENU OPCIONES \n");
		printf(" \n");
		printf("1-Ingresar un producto \n");
		printf("2-Mostrar todos los productos \n");
		printf("3-Buscar un producto\n");
		printf("4-Cerrar\n");
		printf(" \n");
		printf("Ingrese una opcion: \n");
		
		scanf("%d", &eleccion);
		

	while (salir==0){
		

		//Ingresar un producto
		if(eleccion ==1){
		
			producto_nuevo=pedir();
		}
		
		//Mostrar los productos (por ahora solo muestra 1)
		else if (eleccion ==2){

			imprimir(producto_nuevo);

		}
		
		// Buscar un producto (esto no sé si esta bien, no alcancé a hacerlo)
		else if (eleccion ==3){

			char*nombrebuscado;
			int numerobuscado;

			printf("Ingrese el nombre del producto a buscar: ");
			scanf("%s", &nombrebuscado);
			printf("Ingrese el numero de serie: ");
			scanf("%d", &numerobuscado);


		}
		// Cerrar programa
		else if (eleccion==4){
			salir = 1;
		}
		
		else{  
			printf("El numero ingresado no es correcto. Intente nuevamente \n.");
		}
	}

return 0;
}