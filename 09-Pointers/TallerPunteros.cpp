/**
 * @file TallerPunteros.cpp
 * @author Nicolas Betancur Rios
 * @brief Manejo de punteros
 *
 * Este archivo tiene como objetivo crear funciones que manipulen punteros
 *
 */
#include <iostream>
#include <string.h>
#include "dataprst.h"

using namespace std;

void Menu();
int sqrt(int *n);
void printstr(const char *str);
int str_busca(const char *str, char c);
void concatena(char *str1, const char *str2);
void reversa(char *str);
void buscarMenorMayor(int *arreglo, int n, int &menor, int &mayor);
void intercambiar(int &a, int &b);
void ordenarMenorAMayor(int *arreglo, int n);
void mostrarArreglo(int *arreglo, int n);

void Menu()
{
    int Opcion = 0;

    gotoxy(6, 2);
    cout << " Menu principal . . .";

    gotoxy(2, 4);
    cout << "1. Funcion sqr2, elevar un numero al cuadrado.";

    gotoxy(2, 5);
    cout << "2. Funcion printstr, mostrar una cadena en stin.";

    gotoxy(2, 6);
    cout << "3. Funcion strbusca, buscar un caracter en una cadena.";

    gotoxy(2, 7);
    cout << "4. Funcion strcon, concatenar dos cadenas.";

    gotoxy(2, 8);
    cout << "5. Funcion reversa, invertir una cadena.";

    gotoxy(2, 9);
    cout << "6. Funcion Apmenor, buscar numero menor y mayor.";

    gotoxy(2, 10);
    cout << "7. Funcion Dinorden, ordenar un arreglo.";

    gotoxy(2, 11);
    cout << "8. Salir.";

    gotoxy(5, 13);
    cout << "Opcion(1 | 8)?: ";
    cin >> Opcion;
    fflush(stdin);

    switch (Opcion)
    {
    case 1:
    {
        system("cls");
        gotoxy(6, 2);
        cout << "Seleccion: 1. Funcion sqr2, elevar un numero al cuadrado";
        int n;
        cout << " Ingresa el valor de n: " << endl
             << " >> ";
        cin >> n;
        fflush(stdin);
        cout << n << "^2 = " << sqrt(&n) << endl;
        system("pause");
        system("cls");
        Menu();
        break;
    }
    case 2:
    {
        system("cls");
        gotoxy(6, 2);
        cout << "Seleccion: 2. Funcion printstr, mostrar una cadena en stin. Ingresa la cadena:"
             << endl
             << " >> ";
        // Lee una línea completa desde stdin, incluyendo espacios
        cout << "Ingrese la cadena: ";
        const int MAX_LENGTH = 100; // Tamaño máximo de la cadena

        char input[MAX_LENGTH];
        cin.getline(input, MAX_LENGTH);

        // Muestra la cadena ingresada
        cout << "Cadena ingresada: ";
        printstr(input);
        cout << endl;
        system("pause");
        system("cls");
        Menu();
        break;
    }
    case 3:
    {
        const int MAX_LENGTH = 100; // Tamaño máximo de la cadena
        char input[MAX_LENGTH];
        char caracter;
        system("cls");
        gotoxy(6, 2);
        cout << "Seleccion: 3. Funcion strbusca, buscar un caracter en una cadena. Ingresa la cadena:"
             << endl
             << " >> ";
        // Lee una línea completa desde stdin, incluyendo espacios
        cin.getline(input, MAX_LENGTH);
        fflush(stdin);

        cout << endl
             << " Ingresa el caracter a buscar: " << endl
             << " >> ";
        cin >> caracter;
        fflush(stdin);

        // Busca el carácter en la cadena
        int resultado = str_busca(input, caracter);

        // Muestra el resultado
        if (resultado != -1)
        {
            cout << "El caracter '" << caracter << "' se encuentra en la posicion " << resultado << " de la cadena.\n";
        }
        else
        {
            cout << "El caracter '" << caracter << "' no se encuentra en la cadena.\n";
        }
        system("pause");
        system("cls");
        Menu();
        break;
    }
    case 4:
    {
        const int MAX_LENGTH = 100; // Tamaño máximo de las cadenas
        char cadena1[MAX_LENGTH];
        char cadena2[MAX_LENGTH];
        system("cls");
        gotoxy(6, 2);
        cout << "Seleccion: 4. Funcion strcon, concatenar dos cadenas."
             << endl;

        // Lee las dos cadenas desde stdin
        cout
            << endl
            << " Ingrese la primera cadena: " << endl
            << " >> ";
        cin.getline(cadena1, MAX_LENGTH);
        fflush(stdin);
        cout << " Ingrese la segunda cadena: " << endl
             << " >> ";
        cin.getline(cadena2, MAX_LENGTH);
        fflush(stdin);

        // Concatena las dos cadenas
        concatena(cadena1, cadena2);

        // Muestra la cadena resultante

        cout << " Cadena resultante: " << cadena1 << "\n";
        system("pause");
        system("cls");
        Menu();
        break;
    }
    case 5:
    {
        const int MAX_LENGTH = 100; // Tamaño máximo de la cadena
        char cadena[MAX_LENGTH];

        // Lee la cadena desde stdin
        system("cls");
        gotoxy(6, 2);
        cout << "Selecionado: 5. Funcion reversa, invertir una cadena." << endl;
        cout
            << endl
            << " Ingrese la cadena: " << endl
            << " >> ";
        cin.getline(cadena, MAX_LENGTH);
        fflush(stdin);

        // Invierte la cadena
        reversa(cadena);

        // Muestra la cadena invertida
        cout << " 5Cadena invertida: " << cadena << "\n";
        system("pause");
        system("cls");
        Menu();
        break;
    }
    case 6:
    {
        int n;
        system("cls");
        gotoxy(6, 2);
        cout << "Selecionado: 6. Funcion Apmenor, buscar numero menor y mayor." << endl;
        cout
            << endl
            << " Ingrese el tamano del arreglo: " << endl
            << " >> ";
        cin >> n;
        fflush(stdin);

        // Verifica que el tamaño del arreglo sea válido
        if (n <= 0)
        {
            cerr << " Tamano de arreglo inválido.\n";
            Menu();
        }

        // Crea un arreglo dinámico de tamaño n
        int *arreglo = new int[n];

        // Solicita al usuario ingresar los números y los almacena en el arreglo
        for (int i = 0; i < n; ++i)
        {
            cout << "Ingrese el numero " << i + 1 << ": ";
            cin >> arreglo[i];
        }
        fflush(stdin);

        int menor, mayor;

        // Busca el número menor y mayor en el arreglo
        buscarMenorMayor(arreglo, n, menor, mayor);

        // Muestra el número menor y mayor
        cout << "Numero menor: " << menor << "\n";
        cout << "Numero mayor: " << mayor << "\n";

        // Libera la memoria del arreglo dinámico
        delete[] arreglo;

        system("pause");
        system("cls");
        Menu();
        break;
    }
    case 7:
    {
        int n;
        system("cls");
        gotoxy(6, 2);
        cout << "Selecionado: 7. Funcion Dinorden, ordenar un arreglo." << endl;
        cout
            << endl
            << " Ingrese el tamano del arreglo: " << endl
            << " >> ";
        // Solicita al usuario ingresar el tamaño del arreglo
        cin >> n;

        // Verifica que el tamaño del arreglo sea válido
        if (n <= 0)
        {
            cerr << "Tamaño de arreglo inválido.\n";
            Menu();
        }

        // Crea un arreglo dinámico de tamaño n
        int *arreglo = new int[n];

        // Solicita al usuario ingresar los números y los almacena en el arreglo
        for (int i = 0; i < n; ++i)
        {
            std::cout << " Ingrese el numero " << i + 1 << ": ";
            std::cin >> arreglo[i];
        }

        // Ordena el arreglo de menor a mayor
        ordenarMenorAMayor(arreglo, n);

        // Muestra el arreglo ordenado
        mostrarArreglo(arreglo, n);

        // Libera la memoria del arreglo dinámico
        delete[] arreglo;
        system("pause");
        system("cls");
        Menu();
        break;
    }
    case 8:
    {
        cout << " Terminando el programa . . ." << endl;
        exit(0);
    }

    default:
        Menu();
        break;
    }
}

/**
 * @brief elevar un numero al cuadrado usando punteros
 *
 * @param n
 * @return int
 */
int sqrt(int *n)
{
    *n = *n * *n;
    return *(n);
}

/**
 * @brief Imprime una cadena de caracteres en la salida estándar.
 *
 * @param str - Apuntador a la cadena de caracteres.
 */
/**
 * @brief Imprime una cadena de caracteres en la salida estándar utilizando putchar y apuntadores.
 * @param str Puntero a la cadena de caracteres.
 */
void printstr(const char *str)
{
    while (*str != '\0')
    {
        putchar(*str);
        ++str;
    }
}

/**
 * @brief Busca un carácter en una cadena de caracteres y devuelve la posición.
 * @param str Puntero a la cadena de caracteres.
 * @param c Carácter a buscar.
 * @return La posición del carácter en la cadena o -1 si no se encuentra.
 */
int str_busca(const char *str, char c)
{
    int posicion = 0;

    // Itera sobre la cadena hasta encontrar el carácter o llegar al final
    while (*str != '\0')
    {
        if (*str == c)
        {
            return posicion; // Devuelve la posición si encuentra el carácter
        }

        ++str;
        ++posicion;
    }

    return -1; // Devuelve -1 si no se encuentra el carácter
}

/**
 * @brief Concatena dos cadenas de caracteres.
 * @param str1 Puntero a la primera cadena.
 * @param str2 Puntero a la segunda cadena que se concatenará al final de str1.
 */
void concatena(char *str1, const char *str2)
{
    // Mueve el puntero al final de str1
    while (*str1 != '\0')
    {
        ++str1;
    }

    // Copia los caracteres de str2 al final de str1
    while (*str2 != '\0')
    {
        *str1 = *str2;
        ++str1;
        ++str2;
    }

    *str1 = '\0'; // Agrega el carácter nulo al final para formar una cadena completa
}

/**
 * @brief Invierte una cadena de caracteres.
 * @param str Puntero a la cadena que se invertirá.
 */
void reversa(char *str)
{
    if (str == nullptr || *str == '\0')
    {
        // La cadena es nula o vacía, no se realiza ninguna acción
        return;
    }

    // Encuentra el final de la cadena
    char *fin = str;
    while (*fin != '\0')
    {
        ++fin;
    }

    --fin; // Apunta al último carácter antes del carácter nulo

    // Intercambia los caracteres desde el principio hasta el final
    while (str < fin)
    {
        // Intercambio de caracteres
        char temp = *str;
        *str = *fin;
        *fin = temp;

        // Mueve los punteros
        ++str;
        --fin;
    }
}

/**
 * @brief Busca el número menor y mayor en un arreglo.
 * @param arreglo Puntero al arreglo de números.
 * @param n Tamaño del arreglo.
 * @param menor Almacena el número menor.
 * @param mayor Almacena el número mayor.
 */
void buscarMenorMayor(int *arreglo, int n, int &menor, int &mayor)
{
    if (arreglo == nullptr || n <= 0)
    {
        // El arreglo es nulo o vacío, no se realiza ninguna acción
        return;
    }

    // Inicializa menor y mayor con el primer elemento del arreglo
    menor = mayor = *arreglo;

    // Itera sobre el arreglo para encontrar el menor y mayor
    for (int i = 1; i < n; ++i)
    {
        if (*(arreglo + i) < menor)
        {
            menor = *(arreglo + i);
        }
        else if (*(arreglo + i) > mayor)
        {
            mayor = *(arreglo + i);
        }
    }
}

/**
 * @brief Intercambia dos valores.
 * @param a Primer valor.
 * @param b Segundo valor.
 */
void intercambiar(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

/**
 * @brief Ordena un arreglo de enteros de menor a mayor utilizando el algoritmo de selección.
 * @param arreglo Puntero al arreglo de números.
 * @param n Tamaño del arreglo.
 */
void ordenarMenorAMayor(int *arreglo, int n)
{
    if (arreglo == nullptr || n <= 0)
    {
        // El arreglo es nulo o vacío, no se realiza ninguna acción
        return;
    }

    // Utiliza el algoritmo de selección para ordenar el arreglo
    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; ++j)
        {
            if (*(arreglo + j) < *(arreglo + minIndex))
            {
                minIndex = j;
            }
        }

        // Intercambia el elemento actual con el mínimo encontrado
        intercambiar(*(arreglo + i), *(arreglo + minIndex));
    }
}

/**
 * @brief Muestra los elementos de un arreglo.
 * @param arreglo Puntero al arreglo de números.
 * @param n Tamaño del arreglo.
 */
void mostrarArreglo(int *arreglo, int n)
{
    std::cout << "Arreglo ordenado de menor a mayor: ";
    for (int i = 0; i < n; ++i)
    {
        std::cout << *(arreglo + i) << " ";
    }
    std::cout << "\n";
}

int main()
{
    Menu();
    return 0;
}
