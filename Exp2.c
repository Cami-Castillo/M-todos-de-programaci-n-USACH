#include <stdio.h>
#include <math.h>
/* 
Nombre :Camila Castillo
NOTA: 7
ACTIVIDAD: Dada la imagen, hacer un programa que calcule el area y el perimetro del anillo, mediante un menu de opciones. El usuario debe poder elegir si quiere calcular
el area o el perimetro del anillo. El programa debe preguntar por el valor del lado del cuadrado, el cual ingresará el usuario.  

IMAGEN DEL PROBLEMA EN CODIGO ASCII, ALEJAR PARA VER MEJOR
ES UN CIRCULO POR FUERA DEL CUADRADO Y UNO POR DENTRO : 
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNXK0000000000000000000000000000KXNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMWNX000000KXNWMMMMMMMMMMMMMMMMMMMMWNXKK00000XNWMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMWNK0000KNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNK0000KNMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMNK000KNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNK0O0KNWMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMNKOO0XWMMMMMMMMMMMMMMMMMMMMMMMWNNWMMMMMMMMMMMMMMMMMMMMMMMWX0OOKNMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMWX0O0XWMMMMMMMMMMMMMMMMMMMMMMMMMMKkkKMMMMMMMMMMMMMMMMMMMMMMMMMMWX0O0XWMMMMMMMMMMMMMMM
MMMMMMMMMMMMMWKkxkKXXXXXXXXXXXXXXXXXNNXXNXXXXXXXOooOXXXXXXXNNXXXXXXXXXXXXXXXXXXXXKkxkKWMMMMMMMMMMMMM
MMMMMMMMMMMWXxcoO0xok00000000000000OOkxdooodxkOOdccdOOkxddoodxkO0000000000O0000kox0OocxXWMMMMMMMMMMM
MMMMMMMMMMN0OxdKMM0xXMMMMMMMMMMMWX00000KXNWWMMMMKxxKMMMMWWNXK00000XWMMMMMMMMMMMKx0MMKdkO0NMMMMMMMMMM
MMMMMMMMWKk0NKod00xxXMMMMMMMMNK000KXWMMMMMMMMMMMX00XMMMMMMMMMMMWXK000KNMMMMMMMMXxx00doKW0kKWMMMMMMMM
MMMMMMMNOOXMMKdONNNNWMMMMMWKOO0XWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWX0OOKWMMMMMWNNNNOdKMWXOONMMMMMMM
MMMMMMXk0NMMMKxKMMMMMMMMN0OOXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWX0O0NMMMMMMMMKxKMMMN0kXMMMMMM
MMMMWKkKWMMMMKxKMMMMMMN0O0NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN0O0NMMMMMMKxKMMMMWKkKWMMMM
MMMWKkKWMMMMMKxKMMMMWKkONMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNOkKWMMMMKxKMMMMMWKkKWMMM
MMMKkKWMMMMMMKxKMMMNOkXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXkONMMMKxKMMMMMMWKkKMMM
MMXk0WMMMMMMMKxKMMXkONMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNOkXMMKxKMMMMMMMW0kXMM
MNkOWMMMMMMMMKxKMXk0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0kXMKxKMMMMMMMMWOkNM
W0kNMMMMMMMMMKxKXk0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0kXKxKMMMMMMMMMNk0W
Xk0WMMMMMMMMMKxOkOWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWOkOxKMMMMMMMMMM0kX
OkNMMMMMMMMMMKdokNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNkodKMMMMMMMMMMNkO
k0MMMMMMMMMMMKllKMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKllKMMMMMMMMMMM0k
xKMMMMMMMMMMMKcoNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNocKMMMMMMMMMMMKx
xNMMMMMMMMMMMKlkMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMklKMMMMMMMMMMMNx
xNMMMMMMMMMMMKd0MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0dKMMMMMMMMMMMNx
kWMMMMMMMN000xcd000XMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN000dcx000NMMMMMMMWk
kWMMMMMMMWXXXOlkXXXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXXXklOXXXWMMMMMMMWk
xNMMMMMMMMMMMKoOMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMOoKMMMMMMMMMMMNx
xXMMMMMMMMMMMKcxWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWdcKMMMMMMMMMMMXx
k0MMMMMMMMMMMKclXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXlcKMMMMMMMMMMMKx
kOWMMMMMMMMMMKolOWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWOloKMMMMMMMMMMWOk
KkXMMMMMMMMMMKxxkKMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKkxxKMMMMMMMMMMXkK
WOOWMMMMMMMMMKx00kXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXk00xKMMMMMMMMMWOOW
MKkKMMMMMMMMMKxKWOkXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXkOWKxKMMMMMMMMMKkXM
MW0kXMMMMMMMMKxKMW0kXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXk0WMKxKMMMMMMMMXk0WM
MMWOONMMMMMMMKxKMMWKkKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKkKWMMKxKMMMMMMMNkOWMM
MMMNOONMMMMMMKxKMMMMXOOXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXOOXMMMMKxKMMMMMMNOONMMM
MMMMNOONMMMMMKxKMMMMMWKk0NWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN0kKWMMMMMKxKMMMMMNOONMMMM
MMMMMNOkXMMMMKxKMMMMMMMN0O0XWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWX0O0NMMMMMMMKxKMMMMXkONMMMMM
MMMMMMW0kKWMMKxKMMMMMMMMMWKOOKNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNKOOKNMMMMMMMMMKxKMMWKk0WMMMMMM
MMMMMMMMXkONMKod00O0NMMMMMMWX0O0KNWMMMMMMMMMMMMMWXXWMMMMMMMMMMMMMWNK0O0XWMMMMMMN0O00doKMNOkXWMMMMMMM
MMMMMMMMMN0kK0dkXXkdXMMMMMMMMMWX00000XNWMMMMMMMMKxxKMMMMMMMMWNXK0000XWMMMMMMMMMKdkXXkd0Kk0NMMMMMMMMM
MMMMMMMMMMMXOdlkXXkoOXXXXXXXXXXXXXKOkxxxxxkO0KKXkookXKK0OkxxxxxkOKXXXXXXXXXXXXXOokXXkldOXWMMMMMMMMMM
MMMMMMMMMMMMWKdldOOkO000000000000000000OkxxxxkOOdccdOOkxxxxkO000000000000000000OkOOdlxKWMMMMMMMMMMMM
MMMMMMMMMMMMMMWX0O0NMMMMMMMMMMMMMMMMMMMMMMMMMMMMKxxKMMMMMMMMMMMMMMMMMMMMMMMMMMMMN0O0XWMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMWN0O0KNMMMMMMMMMMMMMMMMMMMMMMMMMX00XMMMMMMMMMMMMMMMMMMMMMMMMMNKOO0NMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMWX0O0KNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNK0O0XWMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMWX0000KNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNK00O0XWMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMWNK00000XNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNX00000KNMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXK000000KKXXNNWWWWWWWWWWNNXXKK000000KXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNK0OkkxxxxkkkkkkxxxxxxkkO0KNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM


*/


void funcionarea (float*area, float lado){    // funcion que no retorna nada, pero 	que genera el area del anillo. 
	*area= (3.14 *(lado/2)*(lado/2))- (lado/2*sqrt(2) * 3.14); // calculo del área del anillo.
}

int main(){   // funcion principal

	 int lado;     // definicion de variables
	 float area ;
	 int op =1 ;    
	 int perimetro;



	printf("Ingrese el lado del cuadrado: ");   // para solicitar el lado del cuadrado. 
	scanf("%d",&lado);        // para guardar la varible ingresada


while (op!=3) {       

	if (op==1) {   
		printf("Ingrese una opcion: ");    
		scanf("%d", &op);
		funcionarea (&area, lado );   // se llama a la funcion para darle un nuevo valor a la variable area
		printf ("El area del anillo es: %f", area);  // se entrega el dato de la variable area 
	}

	else if (op==2) {
		perimetro= 2*3.14*(lado*(sqrt(2)/2)) - (lado/2*2*3.14) ; // calculo para calcular el perimentro
		printf("El perimetro del anillo es: %d", perimetro  ); // se entrega el perimetro

	}
	return 0; 
}
}