// Taller 4 Programacion 2
// Nicolas Betancur

#include <atomic>
#include <stdio.h>
#include <math.h>

void menu();
void nVecesHola(int num);
void nPrimerosNumeros(int num);
void TablaMultiplicar(int num, int lim);
void ImprimirTablas(int act, int num);
int Sumatoria(int num);
int Factorial(int num);
int SumatoriaExpresion(int n);
int PotenciaRecursiva(int x, int y);
bool ImparPar(int x);
bool Primo(int n , int i);
void Submultiplos(int x, int i);
int Fibonacci(int n);
void Fibonacci_secuencia(int n);
int MCM(int a, int b);
int MCD(int a, int b);
void Hanoi(int n, char origen, char destino, char auxiliar);

int main(){

	menu();
	return 0;
}

void menu(){
	
	int opcion = 0, num = 0;

    printf("\nMenu Principal: \n");
    printf("1. N veces el texto hola\n");
    printf("2. N primeros numeros enteros\n");
    printf("3. Tabla de multiplicar de un numero\n");
    printf("4. Todas las tablas de multiplicar hasta N\n");
    printf("5. Sumatoria de los numeros enteros hasta N\n");
    printf("6. Factorial de N\n");
    printf("7. Sumatoria de la expresion x^x para todos los numeros entre 1 y N\n");
    printf("8. Potencia de un numero x a la y potencia\n");
    printf("9. Indicar si un numero x es par o impar\n");
    printf("10. Indicar si un numero x es primo o no\n");
    printf("11. Submultiplos de un numero x\n");
    printf("12. N-esimo numero de la serie de Fibonacci\n");
    printf("13. N primeros numeros de la serie de Fibonacci\n");
    printf("14. Minimo comun multiplo de dos numeros a y b\n");
    printf("15. Maximo comun divisor de dos numeros a y b\n");
    printf("16. Pasos a seguir para resolver el problema de las torres de Hanoi con n anillos\n");printf("Seleccione una opcion (1-16)?\n");
    scanf("%d", &opcion);

	if (opcion == 1){
        
		printf("\nIntroduce el numero de veces a imprimir hola: ");
        scanf("%d", &num);
        nVecesHola(num);
		menu();

	} else if (opcion == 2){

		printf("\nIntroduce el valor del numero mayor: ");
		scanf("%d", &num);
		nPrimerosNumeros(num);
		menu();

	} else if (opcion == 3) {
		printf("\nIntroduce el numero para mostrar sus tablas: ");
		scanf("%d", &num);
		TablaMultiplicar(num, 10);
		menu();
	} else if (opcion == 4) {

		printf("\nIntroduce el numero para mostrar sus tablas anteriores: ");
		scanf("%d", &num);
		ImprimirTablas(1, num);
		menu();

	} else if (opcion == 5) {
		
		printf("Introduce el numero N para mostrar la sumatoria de los numeros hasta N: ");
        scanf("%d", &num);
        Sumatoria(num);
		menu();
	} else if (opcion == 6) {

		printf ("Introduce un numero para mostrar su factorial: ");
		scanf("%d", &num);
		Factorial(num);
		menu();
	}
}

void nVecesHola(int num)
{
    if (num > 0){
		printf("Hola\n");
		nVecesHola(num - 1);
    }
}

void nPrimerosNumeros(int num){

	if (num > 0){
		printf("%d, ", num);
		nPrimerosNumeros(num - 1);
	}
}

void TablaMultiplicar(int num, int lim) {

	if (lim > 0){
		printf("\n%d x %d = %d", num, lim, num * lim);
		TablaMultiplicar(num, lim - 1);
	}
}

void ImprimirTablas(int act, int num){
	if (act < num){
		printf("\nTabla del %d:\n", act);
		TablaMultiplicar(act, 10);
		ImprimirTablas(act + 1, num);
	}
}

int Sumatoria(int num){

	int result;
    if (num > 0) {
        result = num + Sumatoria(num - 1);
        printf("La sumatoria de los numeros hasta %d es igual a %d\n", num, result);
    } else {
		return 0;
	}

	return 0;
}

int Factorial(int num){
	
	int result = num * Factorial(num - 1);
	if (num == 0){
		return 1;
	}
	else {
		printf("El factorial de %d es %d", num, num * result);
		return result;
	}
}
















