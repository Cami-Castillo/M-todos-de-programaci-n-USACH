#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
/*Autores: Camila Castillo, Alvaro Troncoso*/


/*Este juego tiene dos modos, el manual y el automático, por ahora solo funciona el modo manual y los movimientos del jugador principal,
reduciendo los contadores y sus verificaciones necesarias. 
El jugador en el modo manual es por defecto el A, 
Los contadores, disminuyen acorde se mueven los jugadores, si hay un 0, entonces, ese bloque fue bombardeado
EL juego funciona con 2 archivos, el mapa.in y armas.in. 
En armas.in se encuentran solo 4 armas, pero puede ser modificado porque se opera con memoria dinámica.
La aletoriedad se puede ver modificada, cuando la semilla en mapa.in, se modifica. 
Si se desea jugar de nuevo, con distintos valores aleatorios, se debiese modificar la semilla,en el archivo mapas.in*/

typedef struct Arma{ 

    char nombre[100];
	int ID; 
    int dmg_1;
    int dmg_2;
    int dmg_3;
    int balas;
	int posX;
	int posY;
    int enfriamiento;
    char modo_disparo[100];
	
}Arma;

typedef struct Personaje{

    int ID;
    int posX;
    int posY;
    int vida; // 100 = total vida
    int blindaje; // 100 = total blindaje
    Arma* armas[2];
    char objetos;
    int direccion;
	int accion_realizada;
	int turnoIni;

}Personaje;

typedef struct ObjPos{ // para los objetos de blindaje y salud y obstaculos. 

    int ID;
    int posX;
    int posY;
	
}Obj;

typedef struct Mapa
{
	
    int**mapa_contadores; 	
	int**mapa_obstaculos;
	int**mapa_jugadores;
	int**mapa_armas; 
    int dimension;
    int can_Jugadores;
    int can_Obstaculos;
	int cantidad_Armas;
    int semilla;
	Arma* armas_Tablero;
    Personaje* jugadores;
	Obj* obstaculos; // para generar un arreglo de obstaculos
	Obj* objetos;  // para generar un arreglo de objetos 
	

}Mapa;


typedef struct EstadoTablero{
	
	Mapa**estadoMapa;//este es el tablero
	Personaje* jugadores;
	int jugadoresRestantes;//almacena cuantos jugadores quedan
	int estadoActual;//esta es la id del estado
	int estadoAnterior;//esta es la id del estado anterior
	char* transicion; // para saber el movimiento del jugador
	
}EstadoTablero;



void mostrar_simbolos(){
	
	printf("\n");
	printf("Jugadores= A, B, D, E, H, I, L, M \n");
	printf("Armas= J, K, P, C\n");
	printf("Obstaculos= ## \n");
	printf("Objetos= Y, Z\n");
	printf("Contadores= Cantidad de veces que se puede pasar por el bloque \n");
	
}

/*Funcion que se le entrega un mapa y retorna el print del cambio de posicion de mapa*/
void mostrar_Mapa(Mapa mapa){
	
int i, j ,h,k;
for (int i = 0; i < mapa.dimension; ++i){
		for (int j = 0; j < mapa.dimension; ++j){ 	
			if (mapa.mapa_obstaculos[i][j] !=0){
				printf(" ##"); // asi se muestran los obstaculos 
				}
			else if(mapa.mapa_jugadores[i][j]!=0){ // esto puede ser modificado, de acuerdo a la cantidad maxima de jugadores
					if(mapa.mapa_jugadores[i][j]==1){
						printf(" A ");
					} 
					else if(mapa.mapa_jugadores[i][j]==2){
						printf(" B ");
					}
					else if(mapa.mapa_jugadores[i][j]==3){
						printf(" D ");
					}
					else if(mapa.mapa_jugadores[i][j]==4){
						printf(" E ");
					}			
				}
			else if(mapa.mapa_armas[i][j]!=0){ // esto puede ser modificado, si se agregan mas armas, solo hay 4 en el archivo. 
				
					if(mapa.mapa_armas[i][j]==1){
						printf(" J ");
					} 
					else if(mapa.mapa_armas[i][j]==2){
						printf(" K ");
					}
					else if(mapa.mapa_armas[i][j]==3){
						printf(" P ");
					}
					else if(mapa.mapa_armas[i][j]==4){
						printf(" C ");
					}
				}
			else{
				printf(" %2d", mapa.mapa_contadores[i][j]);
				
				}
			
			
		}
		printf("\n");
	}

}

/*Verifica movimiento derecha*/
int verificarDer(Mapa mapa, int i){

	if (mapa.jugadores[i].posY+1 >=0 && mapa.jugadores[i].posY+1 <mapa.dimension){
		if (mapa.mapa_obstaculos[mapa.jugadores[i].posX][mapa.jugadores[i].posY+1] ==0 && mapa.mapa_jugadores[mapa.jugadores[i].posX][mapa.jugadores[i].posY+1] ==0 && mapa.mapa_contadores[mapa.jugadores[i].posX][mapa.jugadores[i].posY+1]!=0){
			return 1;
		}	
		else{
			return 0;}
	
}
}	

/*Movimiento derecha*/ 
void movDer(Mapa mapa, int numero_jugador){  // jugador A es el jugador 0 
				
		
		if ((verificarDer(mapa, numero_jugador)==1)){
			mapa.mapa_jugadores[mapa.jugadores[numero_jugador].posX][mapa.jugadores[numero_jugador].posY]= 0;
			mapa.mapa_jugadores[mapa.jugadores[numero_jugador].posX][mapa.jugadores[numero_jugador].posY+1]= numero_jugador+1;
			mapa.mapa_contadores[mapa.jugadores[numero_jugador].posX][mapa.jugadores[numero_jugador].posY]=mapa.mapa_contadores[mapa.jugadores[numero_jugador].posX][mapa.jugadores[numero_jugador].posY]-1;
			mapa.jugadores[numero_jugador].posY= mapa.jugadores[numero_jugador].posY +1;
			mapa.jugadores[numero_jugador].accion_realizada=4;
		
			
		}	
		else{
			printf("\n\n!!! NO ES POSIBLE HACER ESE MOVIMIENTO !!!\n\n");
			printf("Realiza otra accion\n\n");
			
		}
		mostrar_Mapa(mapa);
		mostrar_simbolos(mapa);



		
}
int verificarIzq(Mapa mapa, int i){
		
	if (mapa.jugadores[i].posY-1 >=0 && mapa.jugadores[i].posY-1 <mapa.dimension){
		if (mapa.mapa_obstaculos[mapa.jugadores[i].posX][mapa.jugadores[i].posY-1] ==0 && mapa.mapa_jugadores[mapa.jugadores[i].posX][mapa.jugadores[i].posY-1] ==0 && mapa.mapa_contadores[mapa.jugadores[i].posX][mapa.jugadores[i].posY-1]!=0){
			return 1;
		}	
			
		else{
			return 0;}
	
}
}	


	
void movIzq(Mapa mapa, int numero_jugador){  // jugador A es el jugador 0 

		if ((verificarIzq(mapa, numero_jugador)==1)){
			mapa.mapa_jugadores[mapa.jugadores[numero_jugador].posX][mapa.jugadores[numero_jugador].posY]= 0;
			mapa.mapa_jugadores[mapa.jugadores[numero_jugador].posX][mapa.jugadores[numero_jugador].posY-1]= numero_jugador+1;
			mapa.mapa_contadores[mapa.jugadores[numero_jugador].posX][mapa.jugadores[numero_jugador].posY]=mapa.mapa_contadores[mapa.jugadores[numero_jugador].posX][mapa.jugadores[numero_jugador].posY]-1;
			mapa.jugadores[numero_jugador].posY= mapa.jugadores[numero_jugador].posY-1;
			mapa.jugadores[numero_jugador].accion_realizada=3;
			

		}
		else{
			printf("\n\n!!! NO ES POSIBLE HACER ESE MOVIMIENTO !!!\n\n");
			printf("Realiza otra accion\n\n");
			
		}
		mostrar_Mapa(mapa);
		mostrar_simbolos(mapa);


}
int verificarArr(Mapa mapa, int i){

	if (mapa.jugadores[i].posX-1 >=0 && mapa.jugadores[i].posX-1 <mapa.dimension){
		if (mapa.mapa_obstaculos[mapa.jugadores[i].posX-1][mapa.jugadores[i].posY] ==0 && mapa.mapa_jugadores[mapa.jugadores[i].posX-1][mapa.jugadores[i].posY] ==0 && mapa.mapa_contadores[mapa.jugadores[i].posX-1][mapa.jugadores[i].posY]!=0){
			return 1;
		}	

		else{
			return 0;}
	
}
}	


void movArr(Mapa mapa, int numero_jugador){  // jugador A es el jugador 0 
		
		
		
		if ((verificarArr(mapa, numero_jugador)==1)){
			mapa.mapa_jugadores[mapa.jugadores[numero_jugador].posX][mapa.jugadores[numero_jugador].posY]= 0;
			mapa.mapa_jugadores[mapa.jugadores[numero_jugador].posX-1][mapa.jugadores[numero_jugador].posY]= numero_jugador+1;
			mapa.mapa_contadores[mapa.jugadores[numero_jugador].posX][mapa.jugadores[numero_jugador].posY]=mapa.mapa_contadores[mapa.jugadores[numero_jugador].posX][mapa.jugadores[numero_jugador].posY]-1;
			mapa.jugadores[numero_jugador].posX= mapa.jugadores[numero_jugador].posX -1;
			mapa.jugadores[numero_jugador].accion_realizada=1;
		

		}
		else{
			printf("\n\n!!! NO ES POSIBLE HACER ESE MOVIMIENTO !!!\n\n");
			printf("Realiza otra accion\n\n");
			
		}
		mostrar_Mapa(mapa);
		mostrar_simbolos(mapa);

		
}

int verificarAba(Mapa mapa, int i){
		
	if (mapa.jugadores[i].posX+1 >=0 && mapa.jugadores[i].posX+1 <mapa.dimension){
		if (mapa.mapa_obstaculos[mapa.jugadores[i].posX+1][mapa.jugadores[i].posY] ==0 && mapa.mapa_jugadores[mapa.jugadores[i].posX+1][mapa.jugadores[i].posY] ==0 && mapa.mapa_contadores[mapa.jugadores[i].posX+1][mapa.jugadores[i].posY]!=0){
			return 1;
		}	
			
		else{
			return 0;}
	
}
}	

void movAbajo(Mapa mapa, int numero_jugador){  // jugador A es el jugador 0 
		
		if ((verificarAba(mapa, numero_jugador)==1)){
			mapa.mapa_jugadores[mapa.jugadores[numero_jugador].posX][mapa.jugadores[numero_jugador].posY]= 0;
			mapa.mapa_jugadores[mapa.jugadores[numero_jugador].posX+1][mapa.jugadores[numero_jugador].posY]= numero_jugador+1;
			mapa.mapa_contadores[mapa.jugadores[numero_jugador].posX][mapa.jugadores[numero_jugador].posY]=mapa.mapa_contadores[mapa.jugadores[numero_jugador].posX][mapa.jugadores[numero_jugador].posY]-1 ;
			mapa.jugadores[numero_jugador].posX= mapa.jugadores[numero_jugador].posX +1;
			mapa.jugadores[numero_jugador].accion_realizada=2;
			
		
		}
		else{
			printf("\n\n!!! NO ES POSIBLE HACER ESE MOVIMIENTO !!!\n\n");
			printf("Realiza otra accion\n\n");
		
		}
		mostrar_Mapa(mapa);
		mostrar_simbolos(mapa);

		

}
/*Muestra las acciones, cada vez que se requiera, toma el mapa, porque tiene las funciones de mover jugador*/


void mostrar_Acciones(Mapa mapa){
	
  int opcion;
  do{
	printf("\nAcciones a realizar: ");
    printf("\n1. Mover jugador");
    printf("\n2. Disparar arma");
	printf("\n3. Tomar/cambiar arma");
    printf("\n4. Utilizar objeto");
	printf("\n5. Tomar/cambiar objeto");
	printf("\n9. Salir del juego\n");
    scanf("%d", &opcion);

    switch(opcion){
      int eleccion;
      case 1:
        printf("DIRECCION DE MOVIMIENTO: \n");
        printf("\n1. Hacia arriba.");
        printf("\n2. Hacia abajo.");
        printf("\n3. Hacia izquierda.");
		printf("\n4. Hacia derecha.");
        scanf("%d", &eleccion);
              
        if (eleccion == 1){
			movArr(mapa, 0);
          break;
		}
		 else if (eleccion == 2){
			movAbajo(mapa, 0);
			
          break;
		}
		 else if (eleccion == 3){
			 movIzq(mapa, 0);
			
          break;
		}
        else if (eleccion == 4){
			movDer(mapa, 0);
			
          break;
		}
      case 2:
        printf("Direccion de disparo: \n");
        printf("\n1. Hacia arriba.");
        printf("\n2. Hacia abajo.");
        printf("\n3. Hacia izquierda.");
		printf("\n4. Hacia derecha.");
        scanf("%d", &eleccion);
              
        if (eleccion == 1){
			//disparoArriba
			void mostarBalaArr(Mapa mapa){
			printf("Por ahora, no implementado \n");	
    	/*Si el jugador apreta esta opcion, entonces, el mapa printea, lo mismo que se veia antes, pero en la posicion dependiendo de la direccion en la que disparo
  		dependiendo del arma equipada es donde llega la bala, si choca con un obstaculo la bala, desaparece, si sale, del mapa desaparece, si choca con un jugador hace daño, no disminuye el contador*/
   		 }
			
          break;
		}
		 else if (eleccion == 2){
		 	printf("Por ahora, no implementado \n");
			//disparoAbajo
          break;
		}
		 else if (eleccion == 3){
		 	printf("Por ahora, no implementado \n");
          break;
		}
        else if (eleccion == 4){
        	printf("Por ahora, no implementado \n");
			//disparo derecha
          break;
		}

	  case 3:
        printf("\n\nTomar/cambiar arma: \n");
        	printf("Por ahora, no implementado \n");
	    void TomarArma(Mapa mapa){
			/*Si el jugador, se posa justo donde habia un arma, es decir, si las posiciones coinciden, entonces, el arma[1], se elimina, y se coloca, la que acaba de tomar */ 
		}

		void cambiarArma(Mapa mapa){
			/*si el jugador apreta esta opcion, el array armas cambia, donde la posicion 0 y todo lo que incluye, pasa a la posicoon 1, y la a 0 a la 1*/
		}
	  case 4:
        printf("\n\nUtilizar objeto: \n");
        		printf("Por ahora, no implementado \n");
        void UtilizarObj(Mapa mapa){
    	/*Si el jugador, apreta esta opcion, entonces, la posicion del objeto y el jugador, deben coincidir, si lo hacen, entonces, si es el de blindaje o de salud, se suma el porcentaje de lo que corresponde sin sobrepasar los 100 maximos */
   		 }

	  case 5:
        printf("\n\nTomar cambiar objeto: \n");
        printf("Por ahora, no implementado \n");
    }
  }
  while (opcion != 9);
  printf("\nADIOS\n");
}

/*Genera el mapa inicial, con todos sus submapas respectivos*/
Mapa generar_mapa(char* nombre_Archivo, Arma* armas){
	
	FILE* puntero_archivo;
	puntero_archivo = fopen(nombre_Archivo,"r");
	Mapa mapa_uno; 
	if(puntero_archivo == NULL){ // para saber si lo abre o no
	  printf("Error!  Falta archivo");   
	  exit(1);  
	}
	fscanf(puntero_archivo, "%d", &mapa_uno.dimension); // para poder trabajar con las variables del archivo

	fscanf(puntero_archivo, "%d", &mapa_uno.can_Jugadores);

	fscanf(puntero_archivo, "%d",  &mapa_uno.can_Obstaculos);
	
	fscanf(puntero_archivo, "%d",  &mapa_uno.semilla);


	mapa_uno.mapa_contadores= (int **)malloc(mapa_uno.dimension*sizeof(int*)); 
	int i;
	for (i=0;i<mapa_uno.dimension;i++) 
		mapa_uno.mapa_contadores[i] = (int*)malloc(mapa_uno.dimension*sizeof(int)); 
	
	
	
	srand(mapa_uno.semilla); 
	
	for (int i = 0; i <mapa_uno.dimension; i++){
		for (int j = 0; j < mapa_uno.dimension; j++){
			mapa_uno.mapa_contadores[i][j] = rand () % 100;      
        }          
			
	}
	
	

/*AQUI EMPIEZO A CREAR MAPA JUGADORES*/
	mapa_uno.mapa_jugadores= (int **)malloc(mapa_uno.dimension*sizeof(int*)); 
	
	for (i=0;i<mapa_uno.dimension;i++) {
		mapa_uno.mapa_jugadores[i] = (int*)malloc(mapa_uno.dimension*sizeof(int)); 
	}
	

    int semilla=mapa_uno.semilla;	
    mapa_uno.jugadores=(Personaje*)malloc(mapa_uno.can_Jugadores*sizeof(Personaje*));

    for(i=0;i<mapa_uno.can_Jugadores;i++){

        mapa_uno.jugadores[i].ID=i+1;
        mapa_uno.jugadores[i].posX=rand() % mapa_uno.dimension;
        mapa_uno.jugadores[i].posY=rand() % mapa_uno.dimension;
        mapa_uno.jugadores[i].vida=100;
        mapa_uno.jugadores[i].blindaje=100;
		mapa_uno.jugadores[i].turnoIni=rand() % 6+1;
		
		

    }

	int k;
	for (int i = 0; i < mapa_uno.dimension; i++){
			for (int j = 0; j < mapa_uno.dimension; j++){
				mapa_uno.mapa_jugadores[i][j]=0;
				for (k=0;k < mapa_uno.can_Jugadores;k++){
					if(i == mapa_uno.jugadores[k].posX && j == mapa_uno.jugadores[k].posY){
						mapa_uno.mapa_jugadores[i][j]=mapa_uno.jugadores[k].ID;
					}		
			}
				
		}
					
	}    

	

	//MAPA OBSTACULOS
	mapa_uno.obstaculos=(Obj*)malloc(mapa_uno.can_Obstaculos*sizeof(Obj));
	
	
	for(i=0; i<mapa_uno.can_Obstaculos; i++){ // asignar a cada uno de los obstaculos, su posicion random y su ID es igual a 1
		mapa_uno.obstaculos[i].ID=1;
		mapa_uno.obstaculos[i].posX= rand() % 20;
		mapa_uno.obstaculos[i].posY = rand() % 20; 	
	}

	mapa_uno.mapa_obstaculos= (int **)malloc(mapa_uno.dimension*sizeof(int*)); 
	
	for (i=0;i<mapa_uno.dimension;i++) {
		mapa_uno.mapa_obstaculos[i] = (int*)malloc(mapa_uno.dimension*sizeof(int)); 
	}
	

	
	
	 // aqui estoy asignando a cada una de las posiciones un 0 o un 1, dependiendo si hay o no obstaculo en esa posicion
	for (int i = 0; i <mapa_uno.dimension; i++){
			for (int j = 0; j < mapa_uno.dimension; j++){
				mapa_uno.mapa_obstaculos[i][j]=0;
				for (k=0;k < mapa_uno.can_Obstaculos;k++){
					if(i == mapa_uno.obstaculos[k].posX && j == mapa_uno.obstaculos[k].posY){
						mapa_uno.mapa_obstaculos[i][j]=mapa_uno.obstaculos[k].ID;
					}		
			}
				
		}
					
	} 
	


	/*AQUI EMPIEZA LA GENERACION DE ARMAS ALEATORIAS PARA EL MAPA INICIAL*/
	srand(mapa_uno.semilla);	
	
	mapa_uno.cantidad_Armas= rand () % (9-3+1) + 3;
	
	mapa_uno.armas_Tablero = (Arma*)malloc(sizeof(Arma)*(mapa_uno.cantidad_Armas));
	// arreglo armas del tablero, que seran aleatorias de las armas del archivo
	
	for(i=0;i< mapa_uno.cantidad_Armas; i++){
		int ale= rand() % 4;
		strcpy(mapa_uno.armas_Tablero[i].nombre, armas[ale].nombre);
		
		mapa_uno.armas_Tablero[i].dmg_1 = armas[ale].dmg_1;
		
		mapa_uno.armas_Tablero[i].dmg_2 = armas[ale].dmg_2;
		
		mapa_uno.armas_Tablero[i].dmg_3 = armas[ale].dmg_3;
		
		mapa_uno.armas_Tablero[i].balas = armas[ale].balas;
		
		mapa_uno.armas_Tablero[i].posX = rand () %20;
		
		mapa_uno.armas_Tablero[i].posY = rand () %20;
		
		mapa_uno.armas_Tablero[i].enfriamiento = armas[ale].enfriamiento;
		
	    strcpy(mapa_uno.armas_Tablero[i].modo_disparo, armas[ale].modo_disparo);
		
		mapa_uno.armas_Tablero[i].ID = armas[ale].ID; 
		}
	
		

	
	/*MAPA ARMAS: mapa que contiene las posiciones de las armas*/
	
	mapa_uno.mapa_armas=(int**)malloc(sizeof(int*)*(mapa_uno.dimension)); // reservo memoria

	
	for (int i = 0; i <mapa_uno.dimension; i++){ 
		mapa_uno.mapa_armas[i] = (int*)malloc(sizeof(int)*mapa_uno.dimension); // reservo memoria 2
	}
	
	
	for (int i = 0; i <mapa_uno.dimension; i++){
			for (int j = 0; j < mapa_uno.dimension; j++){
				mapa_uno.mapa_armas[i][j]=0;
				for (k=0;k <mapa_uno.cantidad_Armas;k++){
					if(i == mapa_uno.armas_Tablero[k].posX && j == mapa_uno.armas_Tablero[k].posY){
						mapa_uno.mapa_armas[i][j]=mapa_uno.armas_Tablero[k].ID;
					}		
			}
				
		}
					
	}    

	return mapa_uno;	
	
}

/*Funcion menu principal, que muestra las opciones iniciales, algunas no implementadas*/


int Menu(Mapa mapa){
  int opcion;
  do{
	printf("..................................\n");    
	printf(".......... BIENVENIDO A ..........\n");
	printf(".......CHORIPAN ROYALE BETA ......\n");
	printf("..................................\n");  
    printf("\n1. Explicacion del juego.");
    printf("\n2. Seleccionar modo de juego.");
    printf("\n3. Salir del juego\n");
    printf("\n\n Eliga una opcion de las 3 opciones.\n");
	printf("->");
    scanf("%d", &opcion);

    switch(opcion){
      int eleccion;
      case 1:
        printf("\n\nEl juego consiste en un battle royale en el que tienes que recoger armas para evitar ser eliminado por otros jugadores y evitar el ser eliminado, dentro del juego hay zonas que seran bombardeadas, lo recomendable es no estar cuando el bloque sea bombardeado y el juego termina cuando solo queda 1 de pie. El juego se divide en 2 modos de juego, el modo MANUAL y el AUTOMATICO, en el modo MANUAL usted tendra la libertad de mover el personaje a su propia voluntad y de acceder al menu mientras juega, en el modo AUTOMATICO la computadora controlara al personaje hasta que muera pero podra acceder al menu cuando usted quiera.\n");
        printf("\n\nEntendiste?");
        printf("\n1. SI.");
        printf("\n2. NO.\n");
        scanf("%d", &eleccion);
              
        if (eleccion == 1)
          break;

        else if (eleccion == 2)
          printf("\n\nEl juego consiste en un battle royale en el que tienes que recoger armas para evitar ser eliminado por otros jugadores y evitar el ser eliminado, dentro del juego hay zonas que serán bombardeadas, lo recomendable es no estar cuando el bloque sea bombardeado y el juego termina cuando solo queda 1 de pie. El juego se divide en 2 modos de juego, el modo MANUAL y el AUTOMATICO, en el modo MANUAL usted tendra la libertad de mover el personaje a su propia voluntad y de acceder al menu mientras juega, en el modo AUTOMATICO la computadora controlara al personaje hasta que muera pero podra acceder al menu cuando usted quiera.\n");
          break;

      case 2:
        printf("\n\nExisten 2 modos de juego, Que modo desea jugar?");
        printf("\n1. Modo Manual.");
        printf("\n2. Modo Automatico.");
        printf("\n\nSeleccione el modo que desea jugar:\n");
        scanf("%d", &eleccion);

        if(eleccion == 1)
		  printf("\n\nHas escogido el modo Manual.\n");
		  printf("\n\nEste es el mapa inicial.\n\n");
		  mostrar_Mapa(mapa);
		  mostrar_simbolos(mapa);
		  printf("\n\nTU JUGADOR ES A\n\n");
		  mostrar_Acciones(mapa);		 
		 
		  return 0;
        if(eleccion == 2)
          printf("\n\nModo Automatico\n");
      	  printf("Por ahora, no implementado ");
          return 0;
    }
  }
  while (opcion != 3);
  printf("\nADIOS\n");
}


/*Esta función lee el archivo armas, y devuelve un array de armas leidas del archivo NO SON las armas del tablero*/

Arma*leerArmas(){

	FILE* puntero_archivo;
	
	puntero_archivo = fopen("armas.in","r");
	if(puntero_archivo == NULL)
	{
	  printf("Error!  Falta archivo");   
	  exit(1);             
	}
	char str[100];

	int cantidad_Armas;
	fscanf(puntero_archivo, "%d", &cantidad_Armas);
	Arma* arreglo_Arma = (Arma*)malloc(sizeof(Arma)*(cantidad_Armas));	
	int i;
	char *token;
	fgets(str, 100, puntero_archivo);
	for (i = 0; i < cantidad_Armas; i++){ 
		
		fgets(arreglo_Arma[i].nombre, 100, puntero_archivo);
		//printf("%s", arreglo_Arma[i].nombre);
		fgets(str, 100, puntero_archivo);
		// Extract the first token
		token = strtok(str, " ");
		token = strtok(NULL, " ");
		token = strtok(NULL, " ");
		arreglo_Arma[i].dmg_1 = atoi(token);
		//printf("%d\n", arreglo_Arma[i].dmg_1);

		fgets(str, 100, puntero_archivo);
		token = strtok(str, " ");
		token = strtok(NULL, " ");
		token = strtok(NULL, " ");
		arreglo_Arma[i].dmg_2 = atoi(token);
		//printf("%d\n", arreglo_Arma[i].dmg_2);

		fgets(str, 100, puntero_archivo);
		token = strtok(str, " ");
		token = strtok(NULL, " ");
		token = strtok(NULL, " ");
		arreglo_Arma[i].dmg_3 = atoi(token);
		//printf("%d\n", arreglo_Arma[i].dmg_3);

		fgets(str, 100, puntero_archivo);
		token = strtok(str, " ");
		token = strtok(NULL, " ");
		token = strtok(NULL, " ");
		arreglo_Arma[i].balas = atoi(token);
		//printf("%d\n", arreglo_Arma[i].balas);

		fgets(str, 100, puntero_archivo);
		token = strtok(str, " ");
		token = strtok(NULL, " ");
		token = strtok(NULL, " ");
		arreglo_Arma[i].enfriamiento = atoi(token);
		//printf("%d\n", arreglo_Arma[i].enfriamiento);

		fgets(str,100,puntero_archivo);
        token = strtok(str, " ");
		token = strtok(NULL, " ");
		token = strtok(NULL, " ");
		strcpy(arreglo_Arma[i].modo_disparo,token);

		//printf("%s", arreglo_Arma[i].modo_disparo);
	}



	return arreglo_Arma;
}




/*Funcion principal*/
int main (){
	
	/*Se generan cada uno de los arreglos necesarios*/
	Arma*arreglo_Armafijo=leerArmas();
	Mapa mapa_uno= generar_mapa("mapa.in", arreglo_Armafijo); 
	
	Menu(mapa_uno);



	/*Se libera la memoria*/

	free(arreglo_Armafijo);

	for (int i = 0; i < mapa_uno.dimension; i++){
		free(mapa_uno.mapa_contadores[i]);
	}
	free(mapa_uno.mapa_contadores);
	
	for (int i = 0; i < mapa_uno.dimension; i++){
		free(mapa_uno.mapa_jugadores[i]);
	}
	free(mapa_uno.mapa_jugadores);


	for (int i = 0; i < mapa_uno.dimension; i++){
		free(mapa_uno.mapa_armas[i]);
	}
	free(mapa_uno.mapa_armas);


	for (int i = 0; i < mapa_uno.dimension; i++){
		free(mapa_uno.mapa_obstaculos[i]);
	}
	free(mapa_uno.mapa_obstaculos);

		
	return 0; 
	
	
}
