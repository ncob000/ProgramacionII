#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "dataprst.h"

void Menu();
void mostrar_vector(int N, int array[]);
void leer_enteros_desde_teclado(int N, int array[]);
void generarEnterosAleatorios(int N, int arrayEnteros[]);
int contarNumeroEnVector(const int vectorEnteros[], int tamano, int X);
void invertirVector(int vectorEnteros[], int tamano);
void copiarVector(const int vectorOriginal[], int tamano, int vectorCopia[]);
double calcularPromedio(const int vectorEnteros[], int tamano);
int encontrarPosicionMayor(const int vectorEnteros[], int tamano);
bool estaOrdenadoAscendentemente(const int vectorEnteros[], int tamano);

void mostrar_vector(int N, int array[])
{
    printf("Vector:");
    for (int i = 0; i < N; ++i)
    {
        printf(" %d", array[i]); // Mostramos los enteros del array
    }
    printf("\n");
}

void leer_enteros_desde_teclado(int N, int array[])
{
    for (int i = 0; i < N; ++i)
    {
        printf("Introduce un entero: ");
        scanf("%d", &array[i]); // Almacenamos el entero en el array
    }
}

/**
 * @brief Función que llena un array de tamaño N con enteros generados aleatoriamente.
 * @param N Tamaño del array a crear.
 * @param arrayEnteros Array de enteros a llenar.
 */
void generarEnterosAleatorios(int N, int arrayEnteros[])
{
    // Inicializar la semilla para la generación de números aleatorios.
    srand(static_cast<unsigned>(time(nullptr)));

    // Generar N enteros aleatorios y almacenarlos en el array.
    for (int i = 0; i < N; ++i)
    {
        arrayEnteros[i] = rand() % 100; // Generar números aleatorios entre 0 y 99.
    }
}

/**
 * @brief Función que cuenta el número de veces que un número dado aparece en un vector.
 * @param vectorEnteros Array de enteros en el que se busca el número.
 * @param tamano Tamaño del array.
 * @param X Número a buscar en el array.
 * @return El número de veces que X aparece en el array.
 */
int contarNumeroEnVector(const int vectorEnteros[], int tamano, int X)
{
    int contador = 0;

    // Contar el número de veces que X aparece en el array.
    for (int i = 0; i < tamano; ++i)
    {
        if (vectorEnteros[i] == X)
        {
            contador++;
        }
    }

    // Devolver el resultado.
    return contador;
}

/**
 * @brief Función que invierte un vector de enteros.
 * @param vectorEnteros Array de enteros a invertir.
 * @param tamano Tamaño del array.
 */
void invertirVector(int vectorEnteros[], int tamano)
{
    // Intercambiar elementos desde los extremos hacia el centro del vector.
    for (int i = 0; i < tamano / 2; ++i)
    {
        // Intercambiar vectorEnteros[i] y vectorEnteros[tamano - i - 1]
        int temp = vectorEnteros[i];
        vectorEnteros[i] = vectorEnteros[tamano - i - 1];
        vectorEnteros[tamano - i - 1] = temp;
    }
}

/**
 * @brief Función que crea y devuelve una copia de un vector en otra estructura similar.
 * @param vectorOriginal Array original que se va a copiar.
 * @param tamano Tamaño del array original.
 * @return Un nuevo array que es una copia del array original.
 */
void copiarVector(const int vectorOriginal[], int tamano, int vectorCopia[])
{
    // Copiar los elementos del vector original al vector copia.
    for (int i = 0; i < tamano; ++i)
    {
        vectorCopia[i] = vectorOriginal[i];
    }
}

/**
 * @brief Función que calcula el promedio de los elementos en un vector.
 * @param vectorEnteros Array de enteros del cual se calculará el promedio.
 * @param tamano Tamaño del array.
 * @return El promedio de los elementos en el array.
 */
double calcularPromedio(const int vectorEnteros[], int tamano)
{
    // Sumar todos los elementos en el array.
    int suma = 0;
    for (int i = 0; i < tamano; ++i)
    {
        suma += vectorEnteros[i];
    }

    // Calcular el promedio.
    double promedio = static_cast<double>(suma) / tamano;

    // Devolver el resultado.
    return promedio;
}

/**
 * @brief Función que devuelve la posición del mayor valor en un vector.
 * @param vectorEnteros Array de enteros en el que se busca el mayor valor.
 * @param tamano Tamaño del array.
 * @return La posición del mayor valor en el array.
 */
int encontrarPosicionMayor(const int vectorEnteros[], int tamano)
{
    // Inicializar la posición del mayor valor como la primera posición.
    int posicionMayor = 0;

    // Buscar el mayor valor en el array.
    for (int i = 1; i < tamano; ++i)
    {
        if (vectorEnteros[i] > vectorEnteros[posicionMayor])
        {
            posicionMayor = i;
        }
    }

    // Devolver la posición del mayor valor.
    return posicionMayor;
}

bool estaOrdenadoAscendentemente(const int vectorEnteros[], int tamano)
{
    // Un vector de tamaño 0 o 1 siempre se considera ordenado
    if (tamano <= 1)
    {
        return true;
    }

    // Verificar si el vector está ordenado ascendentemente
    for (int i = 1; i < tamano; ++i)
    {
        if (vectorEnteros[i - 1] > vectorEnteros[i])
        {
            return false;
        }
    }

    // Si no se encontraron pares desordenados, el vector está ordenado
    return true;
}

void Menu()
{
    system("cls");
    Cuadrado(1, 1, 50, 14, 0);
    int Opcion = 0;
    fflush(stdin);

    gotoxy(15, 2);
    printf(" Menu principal . . .");

    gotoxy(4, 4);
    printf("1. Leer un vector de tama%co N.", char(164)); // char 164 = ñ

    gotoxy(4, 5);
    printf("2. Generar un vector de N datos aleatorios.");

    gotoxy(4, 6);
    printf("3. Numero de veces que X esta en un vector.");

    gotoxy(4, 7);
    printf("4, Invertir los datos de un vector");

    gotoxy(4, 8);
    printf("5. Copiar un vector en otro");

    gotoxy(4, 9);
    printf("6. Promedio de los datos de un vector");

    gotoxy(4, 10);
    printf("7. Pocision del mayor valor del vector.");

    gotoxy(4, 11);
    printf("8. Indicar si un vector esta ordenado.");

    gotoxy(4, 12);
    printf("9. Salir.");

    gotoxy(15, 14);
    printf(" Opcion (1 | 4)? : ");
    scanf("%d", &Opcion);
    fflush(stdin);

    switch (Opcion)
    {
    case 1:
    {
        int N;
        system("cls");
        gotoxy(15, 2);
        printf("Seleccion: 1. Leer un vector de tama%co N", char(164));
        gotoxy(4, 4);
        printf("Ingresa el tama%co del vector: ", char(164));
        scanf("%d", &N);

        // Limpiar el búfer de entrada
        fflush(stdin);

        int resultado[N]; // Crear un array estático de tamaño N
        gotoxy(0, 6);
        leer_enteros_desde_teclado(N, resultado);
        gotoxy(5, N + 7);
        mostrar_vector(N, resultado);
        gotoxy(0, N + 9);
        system("pause");
        system("cls");
        Menu();
        break;
    }
    case 2:
    {
        int N;
        system("cls");
        gotoxy(15, 2);
        printf("Seleccion 2. Generar un vector de N datos aleatorios.");
        gotoxy(4, 4);
        printf("Ingresa el tama%co del vector: ", char(164));
        scanf("%d", &N);

        // Limpiar el búfer de entrada
        fflush(stdin);

        int resultado[N]; // Crear un array estático de tamaño N
        gotoxy(0, 6);
        generarEnterosAleatorios(N, resultado);
        gotoxy(5, 6);
        mostrar_vector(N, resultado);
        gotoxy(0, 9);
        system("pause");
        system("cls");
        Menu();
        break;
    }
    case 3:
    {
        int tamano;
        system("cls");
        gotoxy(15, 2);
        printf("Seleccion 3. Numero de veces que X esta en un vector.");
        gotoxy(4, 4);
        printf("Ingresa el tama%co del vector: ", char(164));
        scanf("%d", &tamano);

        fflush(stdin);

        // Pedir al usuario ingresar los elementos del vector.
        gotoxy(0, 6);
        int vectorEnteros[tamano];
        for (int i = 0; i < tamano; ++i)
        {
            printf("Ingrese el elemento #%d: ", i + 1);
            scanf("%d", &vectorEnteros[i]);
        }

        gotoxy(1, tamano + 7);
        int X;
        printf("Ingrese el numero a buscar en el vector: ");
        scanf("%d", &X);

        // Llamar a la función para contar el número de veces que X aparece en el vector.
        int resultado = contarNumeroEnVector(vectorEnteros, tamano, X);

        // Imprimir el resultado.
        gotoxy(1, tamano + 9);
        printf("El numero %d aparece %d veces en el vector.\n", X, resultado);
        system("pause");
        system("cls");
        Menu();
        break;
    }
    case 4:
    {
        int tamano;

        system("cls");
        gotoxy(15, 2);
        printf("Seleccion 4, Invertir los datos de un vector");
        gotoxy(4, 4);
        printf("Ingresa el tama%co del vector: ", char(164));
        scanf("%d", &tamano);
        fflush(stdin);

        int vectorEnteros[tamano];

        // Pedir al usuario ingresar los elementos del vector.
        gotoxy(0, 6);

        for (int i = 0; i < tamano; ++i)
        {
            printf("Ingrese el elemento #%d: ", i + 1);
            scanf("%d", &vectorEnteros[i]);
        }
        invertirVector(vectorEnteros, tamano);

        // Imprimir el resultado.
        gotoxy(1, tamano + 9);
        mostrar_vector(tamano, vectorEnteros);

        system("pause");
        system("cls");
        Menu();
        break;
    }
    case 5:
    {
        int tamano;

        system("cls");
        gotoxy(15, 2);
        printf("Seleccion 5. Copiar un vector en otro");
        gotoxy(4, 4);
        printf("Ingresa el tama%co del vector: ", char(164));
        scanf("%d", &tamano);
        fflush(stdin);

        int vectorOriginal[tamano];
        gotoxy(0, 6);
        for (int i = 0; i < tamano; ++i)
        {
            printf("Ingrese el elemento #%d: ", i + 1);
            scanf("%d", &vectorOriginal[i]);
        }

        // Crear un nuevo array para almacenar la copia.
        int vectorCopia[tamano];

        // Llamar a la función para obtener una copia del vector.
        copiarVector(vectorOriginal, tamano, vectorCopia);

        // Imprimir el resultado.
        gotoxy(1, tamano + 9);
        mostrar_vector(tamano, vectorCopia);
        system("pause");
        system("cls");
        Menu();
        break;
    }
    case 6:
    {
        int tamano;

        system("cls");
        gotoxy(15, 2);
        printf("Seleccion 6. Promedio de los datos de un vector");
        gotoxy(4, 4);
        printf("Ingresa el tama%co del vector: ", char(164));
        scanf("%d", &tamano);
        fflush(stdin);

        int vectorPromedio[tamano];
        // Pedir al usuario ingresar los elementos del vector.
        gotoxy(0, 6);

        for (int i = 0; i < tamano; ++i)
        {
            printf("Ingrese el elemento #%d: ", i + 1);
            scanf("%d", &vectorPromedio[i]);
        }

        // Llamar a la función para calcular el promedio del vector.
        double promedio = calcularPromedio(vectorPromedio, tamano);

        // Imprimir el resultado.
        gotoxy(1, tamano + 9);
        printf("El promedio de los elementos en el vector es: %.2f\n", promedio);
        system("pause");
        system("cls");
        Menu();
        break;
    }
    case 7:
    {
        int tamano;

        system("cls");
        gotoxy(15, 2);
        printf("Seleccion 7. Pocision del mayor valor del vector.");
        gotoxy(4, 4);
        printf("Ingresa el tama%co del vector: ", char(164));
        scanf("%d", &tamano);
        fflush(stdin);

        int vectorPosicion[tamano];
        // Pedir al usuario ingresar los elementos del vector.
        gotoxy(0, 6);

        for (int i = 0; i < tamano; ++i)
        {
            printf("Ingrese el elemento #%d: ", i + 1);
            scanf("%d", &vectorPosicion[i]);
        }

        int posicion = encontrarPosicionMayor(vectorPosicion, tamano);

        // Mostrar el resultado.
        if (posicion != -1)
        {
            printf("La posición del mayor valor es: %d\n", posicion + 1);
        }
        system("pause");
        system("cls");
        Menu();
        break;
    }

    case 8:
    {
        int tamano;

        system("cls");
        gotoxy(15, 2);
        printf("Seleccion 8. Indicar si un vector esta ordenado.");
        gotoxy(4, 4);
        printf("Ingresa el tama%co del vector: ", char(164));
        scanf("%d", &tamano);
        fflush(stdin);

        int vectorOrd[tamano];
        // Pedir al usuario ingresar los elementos del vector.
        gotoxy(0, 6);

        for (int i = 0; i < tamano; ++i)
        {
            printf("Ingrese el elemento #%d: ", i + 1);
            scanf("%d", &vectorOrd[i]);
        }

        // Llamar a la función para verificar si el vector está ordenado ascendentemente.
        bool ordenado = estaOrdenadoAscendentemente(vectorOrd, tamano);

        // Mostrar el resultado.
        if (ordenado)
        {
            printf("El vector esta ordenado ascendentemente.\n");
        }
        else
        {
            printf("El vector NO esta ordenado ascendentemente.\n");
        }
        system("pause");
        system("cls");
        Menu();
        break;
    }
    case 9:
        break;

    default:
        printf("Opcion desconocida!!");
        Menu();
        break;
    }
}
int main()
{
    Menu();
    return 0;
}