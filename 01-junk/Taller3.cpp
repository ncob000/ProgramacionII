// Librerias
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constantes
#define pi 3.1416

// Subrutinas
void menu(); // Procedimento sin parametros
void NumeroCuadrado(int Numero); // procedimiento con parametros
void AreaSupCilindro(float Radio, float Altura); // procedimento con parametros
void AreaTrapecio(); //procedimiento sin parametros
float LngCircunferencia(float Radio); // funcion con parametros
float CelciusFahrenheit(); // funcion sin parametros
float VolumenEsfera(float Radio); // Funcion con parametros
float PromedioEstudiante(); // Funcion sin parametros
int ValorBilletes(int b1000, int b2000, int b5000, int b10000, int b20000, int b50000); // Funcion con parametros

// Funcion principal
int main(){
    menu();
}

// Subrutinas.

// Menu del programa
void menu(){
    int Opcion;
	
	printf("\n------------------");
    printf("\nMenu principal ...\n");
    printf("\n1. Calcular n² + 10.");
    printf("\n2. Longitud de una circunferencia.");
    printf("\n3. Grados Celcius a Fahrenheint. ");
    printf("\n4. Area de un trapecio isóceles. ");
    printf("\n5. Volumen de una esfera. ");
    printf("\n6. Volumen de la superficie de un cilindro. ");
	printf("\n7. Calcular promedio de un estudiante.");
	printf("\n8. Calcular valor de los billetes");
	printf("\n9. Salir.\n");
    printf("\nEntre una opcion (1-4)? : ");
    scanf("%d", &Opcion);
	
	// n² + 10
    if (Opcion == 1){
        int Numero;
        printf("\nEntre el valor de n: ");
        scanf("%d", &Numero);
        NumeroCuadrado(Numero);
        menu();
    }
    
	// Longitud de una circunferencia
    else if (Opcion == 2){
        float Radio, Func;
        printf("\nEntre el valor del radio: ");
        scanf("%f", &Radio);
        Func = LngCircunferencia(Radio);
        printf("La longitud de la circunferencia es: %.2f\n", Func);
        menu();
    }
    
	// Celcius a fahrenheit
    else if (Opcion == 3){
        float Func;
        printf("\nEntre los grados Celcius: ");
        Func = CelciusFahrenheit();
        printf("Su temperatura a grados Fahrenheint es: %.2f\n", Func);
        menu();
    }
	
	// Area de un trapecio
    else if (Opcion == 4){
        AreaTrapecio();
        menu();
    }
	
	// Volumen de una esfera
    else if (Opcion == 5){
        float Radio, Func;
        printf("\nEntre el radio de la esfera: ");
        scanf("%f", &Radio);
        printf("El volumen de la esfera es: %.2f\n", VolumenEsfera(Radio));
        menu();
    }
	
	// Area superior de un cilindro
    else if (Opcion == 6){
        float Radio, Altura;
        printf("\nEntre el radio del cilindro: ");
        scanf("%f", &Radio);
        printf("Entre la altura del cilindro: ");
        scanf("%f", &Altura);
        AreaSupCilindro(Radio, Altura);
        menu();
    }
	
	// Promedio de un estudiante
	else if (Opcion == 7){
		printf("El promedio del estudiante es: %.2f\n", PromedioEstudiante());
		menu();
	}
	
	// Valor de billetes
	else if (Opcion == 8){
		int b1000, b2000, b5000, b10000, b20000, b50000;
		printf("Entre la cantidad de billetes de 1000: ");
		scanf("%d", &b1000);

		printf("Entre la cantidad de billetes de 2000: ");
		scanf("%d", &b2000);

		printf("Entre la cantidad de billetes de 5000: ");
		scanf("%d", &b5000);

		printf("Entre la cantidad de billetes de 10000: ");
		scanf("%d", &b10000);

		printf("Entre la cantidad de billetes de 20000: ");
		scanf("%d", &b20000);

		printf("Entre la cantidad de billetes de 50000: ");
		scanf("%d", &b50000);

		printf("El valor de los billetes es de %d$\n", ValorBilletes(b1000, b2000, b5000, b10000, b20000, b50000));
		menu();
	}
	
	// Salir del programa
	else if (Opcion == 9){
		printf("Saliendo del programa...");
		exit(0);
	}
	
	// Opcion diferente de 1..9
	else {
		printf("\nOpcion no valida!\n");
		menu();
	}
}

// Funcion que calcula el promedio de un estudiante tomando tres notas
float PromedioEstudiante()
{
    char CodigoEstudiante[6];
    char NombreEstudiante[10];
    float Nota1, Nota2, Nota3;

    printf("\nCódigo del estudiante: ");
    scanf("%s", CodigoEstudiante);
    printf("Nombre del estudiante: ");
    scanf("%s", NombreEstudiante);
    printf("Entre la primera nota: ");
    scanf("%f", &Nota1);
    printf("Entre la segunda nota: ");
    scanf("%f", &Nota2);
    printf("Entre la tercera nota: ");
    scanf("%f", &Nota3);

    return (Nota1 + Nota2 + Nota3) / 3;
}

// Procedimiento que calcula una exprecion matematica dado un numero
void NumeroCuadrado(int Numero){
    int Resultado = pow(Numero, 2) + 10;
    printf("Resultado: %d² + 10 = %d\n", Numero, Resultado);
}

// Funcion que calcula la longitud de una circunferencia
float LngCircunferencia(float Radio){
    return 2 * pi * Radio;
}

// Funcion que convierte de grados celcius a grados fahrenheit
float CelciusFahrenheit(){
    float Celcius;
    scanf("%f", &Celcius);
    return Celcius * (1.8) + 32; // 9/5 = 1.8
}

// Procedimento que calcula el area de un trapecio teniendo sus bases y altura
void AreaTrapecio(){
    float BaseMayor, BaseMenor, Altura, Area;

    printf("\nEntre la base menor: "); 
    scanf("%f", &BaseMenor);
	printf("Entre la base mayor: ");
	scanf("%f", &BaseMayor);
	printf("Entre la altura: ");
	scanf("%f", &Altura);
    Area = ((BaseMayor + BaseMenor) * Altura) / 2;
	printf("El area del trapecio es: %.2f\n", Area);
}

// Funcion que calcula el volumen de una esfera teniendo su radio
float VolumenEsfera(float Radio){
    return 1.333 * pi * pow(Radio, 3);
}

// Procedimiento que calcula el area de la superficie de un cilindro teniendo su radio y altura
void AreaSupCilindro(float Radio, float Altura){
    float Resultado = (2 * pi * Radio * Altura) + 2 * pi * pow(Radio, 2);
    printf("El volumen de la superficie del cilindro es: %.2f\n", Resultado);
}

// Funcion que clacula el valor de una cantidad de billetes de cierto valor
int ValorBilletes(int b1000, int b2000, int b5000, int b10000, int b20000, int b50000){
    int Valor = (b1000 * 1000) + (b2000 * 2000) + (b5000 * 5000) + (b10000 * 10000) + (b20000 * 20000) + (b50000 * 50000);
    return Valor;
}
