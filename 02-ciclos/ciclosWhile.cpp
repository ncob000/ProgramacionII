/*
	Programacion II
	Taller #4 (Manejo de ciclos usando WHILE) 
	Nicolas Betancur
*/

// Librerias
#include <stdio.h>
#include <cstdlib> // para la funcion exit()

// Funciones
void Menu();
void Multiplos();
void Suma();
void Promedio();
void Perfecto();
void Amigos();
void Fibonacci();
void Factorial();
void Perfectos();
void Primos();
void Factoriales();
void Tablas();

// Funcion principal
int main(){
	Menu();
	return 0;
}

void Menu(){
	
	int Opcion = 0;
	
	printf("\n------------------\n");
	printf("Menu principal ...\n"); 
	printf("\n1.  Multiplos del 7.\n");
	printf("2.  Calcular la Expresion 3(1) + 3(2) + ... + 3(n).\n");
	printf("3.  Promedio de un estudiante.\n");
	printf("4.  Indicar si un numero es perfecto o no.\n");
	printf("5.  Indicar si dos numeros son amigos\n");
	printf("6.  Secuancia de fibonacci hasta n.\n");
	printf("7.  Imprimir el factorial de n.\n");
	printf("8.  Numeros perfectos entre 1 y 10000\n");
	printf("9.  Numeros primos entre 1 y 1000\n");
	printf("10. Factorial de los primeros 10 enteros.\n");
	printf("11. Tablas de multiplicar de 10 hasta 20.\n");
	printf("12. Salir.\n");
	printf("\nIngrese una opcion: (1-12)?: ");
	scanf("%d", &Opcion);

	switch (Opcion) {
		case 1:
			Multiplos();
			Menu();
		break;
		case 2:
			Suma();
			Menu();
		break;
		case 3:
			Promedio();
			Menu();
		break;
		case 4:
			Perfecto();
			Menu();
		break;
		case 5:
			Amigos();
			Menu();
		break;
		case 6:
			Fibonacci();
			Menu();
		break;
		case 7:
			Factorial();
			Menu();
		break;
		case 8:
			Perfectos();
			Menu();
		break;
		case 9:
			Primos();
			Menu();
		break;
		case 10:
			Factoriales();
			Menu();
		break;
		case 11:
			Tablas();
			Menu();
		break;
		case 12:
			exit(0);
		default:
			printf("\nOpcion desconocida ...\n");
			Menu();
		break;
	}
}

/*
	Algoritmo que muestre todos los múltiplos de 7 comprendidos entre 1 y 1000.
*/
void Multiplos(){
	printf("\n1. Multiplos del 7 hasta 1000:\n");
	int i = 0;	
	while(i <= 1000){
		if (i % 7 == 0){
			printf("%d, ", i);
		}
		i++;
	}
	printf("\n");
}

/*
	Algoritmo que calcula la siguiente suma: 3(1)+3(2)+3(3)+3(4)+ ... +3(n)
*/
void Suma(){

	int suma = 0, n;
	
	printf("\n2. Calcular la expresion 3(1)+ 3(2)+ ... + 3(n):\n");
	printf("Ingresa el valor de n: ");
	scanf("%d", &n);
	int i = 0;
	while(i <= n){
		suma = suma + 3 * i;
		i++;
	}
	
	printf("El valor de la expresion hasta %d es: %d\n", n, suma);
}

/*
	Leer cuatro notas de un estudiante y segun su promedio decir si perdio o gano
*/
void Promedio(){

	float nota, total, promedio;
	
	printf("\n3. Promedio de un estudiante:\n");
	int i = 1;
	while (i <= 4){
		printf("Ingrese la nota %d: ", i);
		scanf("%f", &nota);
		total = total + nota;
		i++;
	}

	promedio = total / 4;

	if (promedio < 3.0){
		printf("\nPerdiste.\n");
	} else {
		printf("\nGanaste!\n");
	}
}

/*
	Leer un numero entero positivo por teclado y decir si es perfecto o no, tambien imprimir
	los divisores de dicho numero
 */

void Perfecto(){
	
	int n = 0, suma = 0;

	printf("\n4. Indicar si un numero es perfecto o no:\n");
	printf("\nIngresa el valor de n: ");
	scanf("%d", &n);
	
	printf("Divisores: ");
	int i = 1;
	while (i < n){
		if (n % i == 0){
			printf("%d, ", i);
			suma = suma + i;
		}
		i++;
	}

	if (suma == n){
		printf("\nEl numero %d es perfecto.\n", n);
	} else {
		printf("\nEl numero %d NO es perfecto.\n", n);
	}
}

/*
	Leer dos numeros e indicar si son amigos 
*/
void Amigos(){

	int a = 0, b = 0, divA = 0, divB = 0; // Las variables divA y divB almacenan los divisores de a y b respectivamente
	
	printf("\n5. Indicar si dos numeros son amigos o no\n");
	printf("\nIngresa el valor de a: "); 
	scanf("%d", &a);

	printf("Ingresa el valor de b: ");
	scanf("%d", &b);
	
	int i = 1;
	while (i < a){
		// Se utiliza el valor de i para calcular los divisores de a y b en un solo bucle
		if (a % i == 0){
			divA = divA + i;
		}

		if (b % i == 0){
			divB = divB + i;
		}
		i++;
	}

	if (divA == b && divB == a){
		printf("Los numeros %d y %d son amigos.\n", a, b);
	} else {
		printf("Los numeros %d y %d NO son amigos.\n", a, b);
	}
}

/*
	Procedimeinto que calula la sucesion de fibonacci hasta un numero ingresado
	por teclado
*/

void Fibonacci(){

	int n, suma, prev = 0, next = 1; // La variable next se inicializa en 1 para que la sucecion se cumpla
	
	printf("\n6. Secuancia de fibonacci hasta n:\n");
	printf("Ingresa el valor de n: ");
	scanf("%d", &n);
	
	printf("%d, %d, ", prev, next); // Se imprimen las variables prev y next para cumplir: 0,1,1,...
	int i = 0;
	while (i <= n){
		suma = prev + next; 
		printf("%d, ", suma);
		
		prev = next;
		next = suma;
		i++;	
	}
	printf("\n");
}

/*
	Algoritmo que calcula el factorial de un numero n ingresado por teclado
*/
void Factorial(){

	int n, factorial = 1;
	
	printf("\n7. Factorial de n:\n");
	printf("Ingresa el valor de n: ");
	scanf("%d", &n);
	
	int i = 1;
	while (i <= n){
		factorial = factorial * i;
		i++;	
	}

	printf("%d! = %d\n", n, factorial);
}

//Parte 2 (ciclos anidados)

/*
	Algoritmo que calcula cuantos numeros primos hay entre 1 y 10000
*/
void Perfectos(){
	int suma = 0, cont = 0;

	printf("\n8. Numeros perfectos entre 1 y 10000\n");
	
	printf("\nNumeros encontrados: "); // Completar el print de la linea 285
	int i = 0;
	while (i <= 10000){
		
		int j = 1;
		suma = 0;
		
		while (j < i){
			if (i % j == 0){
				suma = suma + j;
			}
			j++;
		}
		
		if (suma == i){
			printf("%d, ", suma);
			cont = cont + 1;
		}
		i++;	
	}

	printf("\nHay %d numeros perfectos\n", cont);
}

/*
	Algoritmo que muestra y calcula los numeros primos que hay entre 1 y 1000
*/

void Primos(){
	
	int cantidad = 0;
	printf("\n9. Numeros primos entre 1 y 1000\n");
	printf("\nNumeros encontrados: \n");
	
	int i = 1;
	while (i <= 1000){
		
		int j = 1, primo = 0;
		
		while (j <= i){
			if (i % j == 0){
				primo = primo + 1;
			}
			j++;		
		}

		if (primo == 2){
			printf("%d, ", i);
			cantidad = cantidad + 1;
		}	
		i++;
	}
	
	printf("\nEn total hay %d numeros primos entre 1 y 1000\n", cantidad);
}

/*
	Algoritmo que calcula los factoriales de los primeros 10 numeros enteros;
*/
void Factoriales(){
	
	int i = 0;
	while (i <= 10){
		int factorial = 1, j = 1;
		while (j <= i){
			factorial = factorial * j;
			j++;
		}
		printf("Factorial de %d: %d\n", i, factorial);
		i++;
	}

}

/*
	Algoritmo que implementa las tablas de multiplicar de 10 hasta 20
*/
void Tablas(){

	printf("\n11. Tablas de multiplicar del 10 hasta el 20.\n");
	int i = 10;
	while (i <= 20){
		int j = 1;
		while (j <= i){
			if (j <= 10){ //limita que las tablas sean solo hasta el 10 y no cuante el aumento de j cada iteracion
				printf("%d * %d = %d\n", i, j, i*j);
			}
			j++;
		}
		printf("\n");
		i++;
	}
}
