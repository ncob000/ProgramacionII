#include <cstdio>
#include <iostream>

void MostrarDatos(int vector[], int length);
void ordIntercambio(int a[], int n);
void ordSeleccion(int a[], int n);
void ordInsercion(int a[], int n);
void ordBurbuja(int a[], int n);
void ordenacionShell(int a[], int n);
void quicksort(int a[], int primero, int ultimo);

int main()
{
    // Vector a ordenar, 52 numeros enteros en index aleatorios
    int VectorRandom[] = {31, 5, 0, 50, 28, 24, 8, 46, 15, 19,
                          33, 20, 43, 12, 26, 25, 48, 9, 40, 32,
                          27, 4, 49, 45, 18, 44, 10, 38, 37, 35,
                          23, 51, 39, 7, 21, 34, 17, 41, 13, 29,
                          22, 52, 36, 42, 1, 14, 16, 47, 11, 30, 6, 3};

    // Presentacion de datos:
    printf("\nDatos desordenados del vector: \n\n");
    MostrarDatos(VectorRandom, 52);
    printf("\n\nOrdenamiento por intercambio (bubble sort):\n\n");
    ordIntercambio(VectorRandom, 52);
    printf("\n\nOrdenamiento por seleccion   (selection sort):\n\n");
    ordSeleccion(VectorRandom, 52);
    printf("\n\nOrdenamiento por inserccion  (insertion sort)\n\n");
    ordInsercion(VectorRandom, 52);
    printf("\n\nOrdenamiento burbuja:\n\n");
    ordBurbuja(VectorRandom, 52);
    printf("\n\nOrdenamiento shell: \n\n");
    ordenacionShell(VectorRandom, 52);
    printf("\n\nOrdenamiento rapido (quik sort): \n\n");
    quicksort(VectorRandom, 0, 52);

    return 0;
}

/**
 * @brief Mostrar datos ordenados de un vector
 *
 * Este procedimiento recibe un vector organizado y el tamaño del mismo e imprime cada
 * elemento del vector
 *
 * @param vector vector ordenado
 * @param length tamaño del vector
 */
void MostrarDatos(int vector[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d, ", vector[i]);
    }
}
/**
 * @brief Ordena un arreglo de enteros utilizando el algoritmo de intercambio (ordenación de burbuja).
 *
 * Esta función ordena el arreglo de enteros 'a' en orden ascendente utilizando el algoritmo de intercambio.
 *
 * @param a Un arreglo de enteros que se ordenará.
 * @param n El número de elementos en el arreglo.
 */
void ordIntercambio(int a[], int n)
{
    int i, j;
    // Se realizan n−1 pasadas a través del arreglo.
    // Los elementos a[0] hasta a[n-2] se ordenan en cada pasada.
    for (i = 0; i <= n - 2; i++)
        /* coloca mínimo de a[i+1]...a[n-1] en a[i] */
        for (j = i + 1; j <= n - 1; j++)
            if (a[i] > a[j])
            {
                // Realiza intercambio de elementos
                int aux;
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }

    // muestra los datos ordenados
    MostrarDatos(a, n);
}

void ordSeleccion(int a[], int n)
{
    int indiceMenor, i, j;
    /* ordenar a[0]..a[n-2] y a[n-1] en cada pasada */
    for (i = 0; i < n - 1; i++)
    {
        /* comienzo de la exploración en índice i */
        indiceMenor = i;
        /* j explora la sublista a[i+1]..a[n-1] */
        for (j = i + 1; j < n; j++)
            if (a[j] < a[indiceMenor])
                indiceMenor = j;
        /* sitúa el elemento más pequeño en a[i] */
        if (i != indiceMenor)
        {
            int aux = a[i];
            a[i] = a[indiceMenor];
            a[indiceMenor] = aux;
        }
    }
    MostrarDatos(a, n);
}


void ordInsercion(int a[], int n)
{
    int i, j;
    int aux;
    for (i = 1; i < n; i++)
    {
        /* índice j explora la sublista a[i-1]..a[0] buscando la
        posición correcta del elemento destino, lo asigna a a[j] */
        j = i;
        aux = a[i];
        /* se localiza el punto de inserción explorando hacia abajo */
        while (j > 0 && aux < a[j - 1])
        {
            /* desplazar elementos hacia arriba para hacer espacio */
            a[j] = a[j - 1];
            j--;
        }
        a[j] = aux;
    }
    MostrarDatos(a, n);
}

void ordBurbuja(int a[], int n)
{
    int interruptor = 1;
    int pasada, j;
    for (pasada = 0; pasada < n - 1 && interruptor; pasada++)
    {
        /* bucle externo controla la cantidad de pasadas */
        interruptor = 0;
        for (j = 0; j < n - pasada - 1; j++)
            if (a[j] > a[j + 1])
            {
                /* elementos desordenados, es necesario intercambio */
                long aux;
                interruptor = 1;
                aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
            }
    }

    MostrarDatos(a, n);
}

void ordenacionShell(int a[], int n)
{
    int intervalo, i, j, k;
    intervalo = n / 2;
    while (intervalo > 0)
    {
        for (i = intervalo; i < n; i++)
        {
            j = i - intervalo;
            while (j >= 0)
            {
                k = j + intervalo;
                if (a[j] <= a[k])
                    j = -1;
                /* así termina el bucle, par ordenado */
                else
                {
                    double temp;
                    temp = a[j];
                    a[j] = a[k];
                    a[k] = temp;
                    j -= intervalo;
                }
            }
        }
        intervalo = intervalo / 2;
    }
    MostrarDatos(a, n);
}

// Algoritmo quiksort

void quicksort(int a[], int primero, int ultimo)
{
    int i, j, central;
    double pivote;
    central = (primero + ultimo) / 2;
    pivote = a[central];
    i = primero;
    j = ultimo;
    do
    {
        while (a[i] < pivote)
            i++;
        while (a[j] > pivote)
            j--;
        if (i <= j)
        {
            double tmp;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            /* intercambia a[i] con a[j] */
            i++;
            j--;
        }
    } while (i <= j);

    MostrarDatos(a, ultimo);
}
