/**
 * @file TallerCadenas.cpp
 * @author Nicolas Betancur Rios
 * @brief Manejo de strings y chars
 *
 * Este archivo tiene el objetivo de implementar varias funciones para manipular datos de tipo
 * string
 *
 */
#ifdef _WIN32 // Inclusión de bibliotecas y definiciones específicas para Windows
#include <iostream>
#include <string.h>
#include "Taller7.h"
void ClearScreen() {
    system("cls");
}
void SystemPause() {
    system("pause");
}
#elif __linux__ // Inclusión de bibliotecas y definiciones específicas para Linux
#include <iostream>
#include <string.h>
#include <conio.h>
// Las siguientes funciones usan shell script y los comandos de bash para funcionar en linux
void ClearScreen() {
    system("clear");
}
void SystemPause() {
    system("read -rsp $'Press any key to continue...\n' -n 1 key");
}
#else
#include <iostream>
#include <string>
#endif

using namespace std;

// Definicion de funciones:
void Menu();
int StringLength(string Cadena);
string StringCopy(string CadenaOrigen);
string StringRead(int LongitudCadena);
string AddLastChar(string Cadena, char LastChar);
string ReverseSelf(string Cadena);
string ReverseAux(string Cadena);
string StringConcat(string Cadena1, string Cadena2);
int StringVowels(string Cadena);
string StringNoVowels(string Cadena);
int StringToNumber(string Cadena);
bool StringPalindrome(string Cadena);
bool StringComp(string Cadena1, string Cadena2);
bool SubString(string Cadena, string SubCadena);

/**
 * @brief Funcion principal
 *
 * Funcion principal del programa, unicamente ejecuta la funcion Menu()
 *
 * @return int
 */
int main()
{
    Menu();
    return 0;
}

/**
 * @brief Función para mostrar el menú principal y manejar las opciones del usuario.
 *
 * Esta función presenta un menú con diversas operaciones de manipulación de cadenas
 * y solicita al usuario que seleccione una opción. Luego, llama a la función
 * correspondiente según la opción elegida por el usuario.
 */
void Menu()
{
    ClearScreen(); // Funcion para limpiar pantalla definida en el header de este codigo (cambia segun el SO)

    int Opcion = 0;

    // Estructura del menu:
    gotoxy(6, 2);
    cout << " Menu principal . . .";

    gotoxy(2, 4);
    cout << "1.  Calcular la longitud de una cadena.";

    gotoxy(2, 5);
    cout << "2.  Copiar el contenido de una cadena adentro de otra.";

    gotoxy(2, 6);
    cout << "3.  Leer una cadena de N caracteres.";

    gotoxy(2, 7);
    cout << "4.  Agregar un caracter al final de una cadena.";

    gotoxy(2, 8);
    cout << "5.  Invertir una cadena en si misma.";

    gotoxy(2, 9);
    cout << "6.  Invertir una cadena en otra cadena.";

    gotoxy(2, 10);
    cout << "7.  Concatenar dos cadenas.";

    gotoxy(2, 11);
    cout << "8.  Contar cuantas vocales tiene una cadena.";

    gotoxy(2, 12);
    cout << "9.  Devolver una cadena sin vocales.";

    gotoxy(2, 13);
    cout << "10. Calcular el valor numerico de un string.";

    gotoxy(2, 14);
    cout << "11. Verificar si cadena es palindrome.";

    gotoxy(2, 15);
    cout << "12. Verificar si una cadena es igual a otra.";

    gotoxy(2, 16);
    cout << "13. Verificar si una cadena es substring de otra";

    gotoxy(2, 17);
    cout << "14. Salir.";

    gotoxy(5, 19);
    cout << " Opcion (1 | 14)?: ";
    cin >> Opcion;

    switch (Opcion)
    {
    case 1:
    {
        ClearScreen();
        gotoxy(6, 2);
        cout << "Seleccion: 1. Calcular la longitud de una cadena";
        string Cadena;
        gotoxy(2, 4);
        cout << "Ingresa la cadena para calcular su longitud: " << endl
             << " >> ";
        cin.ignore(); // Limpiar el buffer
        getline(cin, Cadena);

        gotoxy(6, 7);
        cout << "Cadena ingresada: " << Cadena
             << "\tLongitud de la cadena: " << StringLength(Cadena);

        gotoxy(1, 9);

        // En esta seccion cin.ignore hace el trabajo de funciones como getch()
        cout << "\nPresiona cualquier tecla para volver al menu ... ";
        cin.ignore();
        ClearScreen();
        Menu();
        break;
    }
    case 2:
    {
        ClearScreen();
        gotoxy(6, 2);
        cout << "Seleccion: 2. Copiar el contenido de una cadena en otra";
        string CadenaOrigen, CadenaResultado;
        gotoxy(2, 4);
        cout << "Ingresa la cadena a copiar: " << endl
             << " >> ";
        cin.ignore();
        getline(cin, CadenaOrigen);
        CadenaResultado = StringCopy(CadenaOrigen);
        gotoxy(6, 7);
        cout << "Cadena original: " << CadenaOrigen << "\tCadena resultante: " << CadenaResultado;
        gotoxy(1, 9);
        cout << "\nPresiona cualquier tecla para volver al menu ... ";
        cin.ignore();
        ClearScreen();
        Menu();
        break;
    }
    case 3:
    {
        ClearScreen();
        gotoxy(6, 2);
        cout << "Seleccion: 3.  Leer una cadena de N caracteres.";
        int LongitudCadena;
        string CadenaResultado;
        gotoxy(2, 4);
        cout << "Ingresa la longitud de la cadena: " << endl
             << " >> ";
        cin.ignore();
        cin >> LongitudCadena;
        CadenaResultado = StringRead(LongitudCadena);
        gotoxy(6, 9);
        cout << "Cadena de " << LongitudCadena << " caracteres: " << CadenaResultado;
        gotoxy(1, 11);
        cout << "\nPresiona cualquier tecla para volver al menu ... ";
        cin.ignore();
        ClearScreen();
        Menu();
        break;
    }
    case 4:
    {
        ClearScreen();
        gotoxy(6, 2);
        cout << "4.  Agregar un caracter al final de una cadena.";
        string Cadena, CadenaResultado;
        char LastChar;
        gotoxy(2, 4);
        cout << "Ingresa la cadena: " << endl
             << " >> ";
        cin.ignore();
        getline(cin, Cadena);
        gotoxy(2, 6);
        cout << "Ingresa el char para agregar: " << endl
             << " >> ";
        cin >> LastChar;
        cin.ignore();
        CadenaResultado = AddLastChar(Cadena, LastChar);
        gotoxy(6, 9);
        cout << "Cadena final: " << CadenaResultado << endl;
        gotoxy(1, 11);
        cout << "\nPresiona cualquier tecla para volver al menu ... ";
        cin.ignore();
        ClearScreen();
        Menu();
        break;
    }
    case 5:
    {
        ClearScreen();
        gotoxy(6, 2);
        cout << "5.  Invertir una cadena en si misma.";
        string Cadena;
        gotoxy(2, 4);
        cout << "Ingresa la cadena: " << endl
             << " >> ";
        cin.ignore();
        getline(cin, Cadena);
        gotoxy(6, 7);
        cout << "Cadena invertida: " << ReverseSelf(Cadena);
        gotoxy(1, 9);
        cout << "\nPresiona cualquier tecla para volver al menu ... ";
        cin.ignore();
        ClearScreen();
        Menu();
        break;
    }
    case 6:
    {
        ClearScreen();
        gotoxy(6, 2);
        cout << "6.  Invertir una cadena en otra cadena.";
        string Cadena;
        gotoxy(2, 4);
        cout << "Ingresa la cadena: " << endl
             << " >> ";
        cin.ignore();
        getline(cin, Cadena);
        gotoxy(6, 7);
        cout << "Cadena invertida: " << ReverseAux(Cadena);
        gotoxy(1, 9);
        cout << "\nPresiona cualquier tecla para volver al menu ... ";
        cin.ignore();
        ClearScreen();
        Menu();
        break;
    }
    case 7:
    {
        ClearScreen();
        gotoxy(6, 2);
        cout << "7.  Concatenar dos cadenas.";
        string Cadena1;
        string Cadena2;
        gotoxy(2, 4);
        cout << "Ingresa la primera cadena: " << endl
             << " >> ";
        cin.ignore();
        getline(cin, Cadena1);
        gotoxy(2, 6);
        cout << "Ingresa la segunda cadena: " << endl
             << " >> ";
        getline(cin, Cadena2);
        gotoxy(6, 9);
        cout << "Cadenas concatenadas: " << StringConcat(Cadena1, Cadena2);
        gotoxy(1, 11);
        cout << "\nPresiona cualquier tecla para volver al menu ... ";
        cin.ignore();
        ClearScreen();
        Menu();
        break;
    }
    case 8:
    {
        ClearScreen();
        gotoxy(6, 2);
        cout << "8.  Contar cuantas vocales tiene una cadena.";
        string Cadena;
        gotoxy(2, 4);
        cout << "Ingresa la cadena" << endl
             << " >> ";
        cin.ignore();
        getline(cin, Cadena);
        gotoxy(6, 7);
        cout << "La cadena " << Cadena << " tiene "
             << StringVowels(Cadena) << " vocales." << endl;
        gotoxy(1, 9);
        cout << "\nPresiona cualquier tecla para volver al menu ... ";
        cin.ignore();
        ClearScreen();
        Menu();
        break;
    }
    case 9:
    {
        ClearScreen();
        gotoxy(6, 2);
        cout << "9.  Devolver una cadena sin vocales.";
        string Cadena;
        gotoxy(2, 4);
        cout << "Ingrese una cadena: " << endl
             << " >> ";
        cin.ignore();
        getline(cin, Cadena);
        gotoxy(6, 7);
        cout << "cadena " << Cadena << " sin vocales: "
             << StringNoVowels(Cadena) << endl;
        gotoxy(1, 9);
        cout << "\nPresiona cualquier tecla para volver al menu ... ";
        cin.ignore();
        ClearScreen();
        Menu();
        break;
    }
    case 10:
    {
        ClearScreen();
        gotoxy(6, 2);
        cout << "10. Calcular el valor numerico de un string.";
        string Cadena;
        gotoxy(2, 4);
        cout << "Ingrese una cadena: " << endl
             << " >> ";
        cin.ignore();
        getline(cin, Cadena);
        gotoxy(6, 7);
        cout << "Valor numerico de " << Cadena << ": "
             << StringToNumber(Cadena);
        gotoxy(1, 9);
        cout << "\nPresiona cualquier tecla para volver al menu ... ";
        cin.ignore();
        ClearScreen();
        Menu();
        break;
    }
    case 11:
    {
        ClearScreen();
        gotoxy(6, 2);
        cout << "11. Verificar si cadena es palindrome.";
        string Cadena;
        gotoxy(2, 4);
        cout << "Ingresa la cadena: " << endl
             << " >> ";
        cin.ignore();
        getline(cin, Cadena);
        if (StringPalindrome(Cadena)) // La funcion es boleana por lo que si es true entra directamente al if
        {
            gotoxy(6, 7);
            cout << "La cadena " << Cadena << " es palindrome." << endl;
        }
        else
        {
            gotoxy(6, 7);
            cout << "La cadena " << Cadena << " NO es palindrome." << endl;
        }
        gotoxy(1, 9);
        cout << "\nPresiona cualquier tecla para volver al menu ... ";
        cin.ignore();
        ClearScreen();
        Menu();
        break;
    }
    case 12:
    {
        ClearScreen();
        gotoxy(6, 2);
        cout << "12. Verificar si una cadena es igual a otra.";
        string Cadena1;
        string Cadena2;
        gotoxy(2, 4);
        cout << "Ingresa la cadena: " << endl
             << " >> ";
        cin.ignore();
        getline(cin, Cadena1);
        gotoxy(2, 6);
        cout << "Ingresa la otra cadena: " << endl
             << " >> ";
        getline(cin, Cadena2);
        if (StringComp(Cadena1, Cadena2) == true)
        {
            gotoxy(6, 9);
            cout << "Las cadenas " << Cadena1 << " y "
                 << Cadena2 << " son IGUALES";
        }
        else
        {
            gotoxy(6, 9);
            cout << "Las cadenas " << Cadena1 << " y "
                 << Cadena2 << " NO son IGUALES";
        }
        gotoxy(1, 11);
        cout << "\nPresiona cualquier tecla para volver al menu ... ";
        cin.ignore();
        ClearScreen();
        Menu();
        break;
    }
    case 13:
    {
        ClearScreen();
        gotoxy(6, 2);
        cout << "13. Verificar si una cadena es substring de otra";
        string Cadena;
        string SubCadena;
        gotoxy(2, 4);
        cout << "Ingresa la cadena principal: " << endl
             << " >> ";
        cin.ignore();
        getline(cin, Cadena);
        gotoxy(2, 6);
        cout << "Ingresa la sub-cadena: " << endl
             << " >> ";
        getline(cin, SubCadena);

        if (SubString(Cadena, SubCadena) == true)
        {
            gotoxy(6, 9);
            cout << "La cadena " << SubCadena << " ES SUBCADENA de " << Cadena;
        }
        else
        {
            gotoxy(6, 9);
            cout << "La cadena " << SubCadena << " NO ES SUBCADENA de " << Cadena;
        }
        gotoxy(1, 11);
        cout << "\nPresiona cualquier tecla para volver al menu ... ";
        cin.ignore();
        ClearScreen();
        Menu();
        break;
    }
    case 14:
        cout << "Programa finalizado . . .";
        break; // Salir del programa
    default:
        // Cubrir la posibilidad de que el usuario ingrese una opcion invalida (> 14)
        cout << "Opcion " << Opcion << " desconocida." << endl
             << "Porfavor ingresa un valor valido";
        Menu();
        break;
    }
}

/**
 * @brief Copia el contenido de una cadena en otra.
 *
 * @param CadenaOrigen La cadena de origen que se copiará.
 * @return La nueva cadena que contiene el mismo contenido que la cadena de origen.
 */
int StringLength(string Cadena)
{
    int LongitudCadena = 0; // Variable para almecenar la longitud de la cadena
    // Iterar atravez de la cadena hasta que se encuentre el caracter nulo '\0'
    while (Cadena[LongitudCadena] != '\0')
    {
        LongitudCadena++; // Incrementar en 1 por cada caracter encontrado
    }
    return LongitudCadena; // retorna la longitud final de la cadena
}

/**
 * @brief Lee una cadena de N caracteres desde la entrada estándar.
 *
 * @param LongitudCadena La longitud de la cadena que se leerá.
 * @return La cadena ingresada por el usuario.
 */
string StringCopy(string CadenaOrigen)
{
    string CadenaDestino;         // Variable de tipo string donde se va a almacener CadenaOrigen
    CadenaDestino = CadenaOrigen; // Igualacion a la cadena ingresada por el usuario
    return CadenaDestino;         // Retorna la cadena donde se copio la cadena ingresada por el usuario
}

/**
 * @brief Lee una cadena de texto de una longitud específica.
 *
 * Esta función solicita al usuario que ingrese una cadena de texto de la longitud
 * especificada. Luego, devuelve la cadena ingresada por el usuario.
 *
 * @param LongitudCadena La longitud de la cadena que se leerá.
 * @return La cadena ingresada por el usuario de la longitud especificada.
 */
string StringRead(int LongitudCadena)
{
    string CadenaFinal; // Variable para almacernar la cadena final
    char Caracter;      // Caracter para iterar en la cadena
    cout << " Ingresa una cadena de " << LongitudCadena << " caracteres: " << endl
         << " >> ";

    // Iterar atravez de la cadena hasta su longitud maxima
    for (int i = 0; i < LongitudCadena; i++)
    {
        cin >> Caracter;                 // Leer 1 caracter por cada iteracion
        CadenaFinal.push_back(Caracter); // Añadir el caracter a la posicion i de la cadena
    }

    cin.ignore();       // Limpiar el buffer
    return CadenaFinal; // Retorna la cadena final
}

/**
 * @brief Lee una cadena y un char y agrega el char leido al final de la cadena
 *
 * Esta funcion recibe como parametros una cadena de caracteres y un caracter, luego, retorna la
 * cadena leida con el caracter leido agregado al final de la cadena.
 *
 * @param Cadena La cadena principal
 * @param LastChar EL caracter para agregar al final de la cadena
 * @return La union entre Cadena y LastChar
 */
string AddLastChar(string Cadena, char LastChar)
{
    string CadenaFinal;              // Variable para almecenar la cadena resultante
    CadenaFinal = Cadena;            // Igualar las cadenas
    CadenaFinal.push_back(LastChar); // Añadir el caracter ingresado por el usuario al final de la cadena
    return CadenaFinal;              // retorna cadena final
}

/**
 * @brief Invierte una cadena de texto en sí misma.
 *
 * Esta función toma una cadena de texto como entrada y la invierte en su lugar,
 * es decir, modifica la cadena original para que los caracteres estén en orden inverso.
 *
 * @param Cadena La cadena de texto que se invertirá.
 * @return La cadena invertida.
 */
string ReverseSelf(string Cadena)
{
    int Length = StringLength(Cadena) - 1;

    // Intercambiar los caracteres desde el inicio y el final de la cadena hasta que se crucen.
    for (int i = 0; i < Length; i++)
    {
        char CharTemp = Cadena[i];
        Cadena[i] = Cadena[Length];
        Cadena[Length] = CharTemp;
        Length--;
    }

    return Cadena; // Devolver la cadena invertida.
}

/**
 * @brief Invierte una cadena de texto y devuelve la cadena invertida como un nuevo objeto.
 *
 * Esta función toma una cadena de texto como entrada y crea una nueva cadena que contiene
 * los caracteres de la cadena original en orden inverso.
 *
 * @param Cadena La cadena de texto que se invertirá.
 * @return La nueva cadena que contiene los caracteres en orden inverso.
 */
string ReverseAux(string Cadena)
{
    string CadenaFinal; // Cadena que almacenará los caracteres invertidos.
    int Length = StringLength(Cadena) - 1;

    // Agregar los caracteres de la cadena original en orden inverso a la nueva cadena.
    for (int i = 0; i <= Length; i++)
    {
        CadenaFinal.push_back(Cadena[Length - i]);
    }

    return CadenaFinal; // Devolver la cadena invertida como un nuevo objeto.
}

/**
 * @brief Concatena dos cadenas de texto y devuelve la cadena resultante.
 *
 * Esta función toma dos cadenas de texto como entrada y las concatena para formar una nueva cadena.
 *
 * @param Cadena1 La primera cadena que se concatenará.
 * @param Cadena2 La segunda cadena que se concatenará.
 * @return La cadena resultante de la concatenación de Cadena1 y Cadena2.
 */
string StringConcat(string Cadena1, string Cadena2)
{
    return Cadena1 + Cadena2; // Devolver la concatenación de las dos cadenas.
}

/**
 * @brief Cuenta cuántas vocales tiene una cadena de texto.
 *
 * Esta función cuenta el número de vocales (mayúsculas y minúsculas) en la cadena de texto proporcionada.
 *
 * @param Cadena La cadena de texto en la que se contarán las vocales.
 * @return El número de vocales presentes en la cadena.
 */
int StringVowels(string Cadena)
{
    int Length = StringLength(Cadena);
    int temp = 0;

    // Iterar a través de la cadena y contar las vocales (mayúsculas y minúsculas).
    for (int i = 0; i < Length; i++)
    {
        if (Cadena[i] == 'a' || Cadena[i] == 'A' || Cadena[i] == 'e' || Cadena[i] == 'E' || Cadena[i] == 'i' || Cadena[i] == 'I' || Cadena[i] == 'o' || Cadena[i] == 'O' || Cadena[i] == 'u' || Cadena[i] == 'U')
        {
            temp++;
        }
    }

    return temp; // Devolver el número de vocales en la cadena.
}

/**
 * @brief Elimina todas las vocales de una cadena de texto y devuelve la cadena resultante.
 *
 * Esta función toma una cadena de texto como entrada y elimina todas las vocales
 * (mayúsculas y minúsculas) de la cadena. Devuelve la cadena modificada sin las vocales.
 *
 * @param Cadena La cadena de texto de la que se eliminarán las vocales.
 * @return La cadena resultante después de eliminar las vocales.
 */
string StringNoVowels(string Cadena)
{
    string CadenaFinal; // Cadena que almacenará los caracteres sin vocales.

    int Length = StringLength(Cadena);
    int i;
    for (i = 0; i < Length; i++)
    {
        // Si el carácter actual no es una vocal, agregarlo a la cadena final.
        if (Cadena[i] != 'a' && Cadena[i] != 'A' && Cadena[i] != 'e' && Cadena[i] != 'E' && Cadena[i] != 'i' && Cadena[i] != 'I' && Cadena[i] != 'o' && Cadena[i] != 'O' && Cadena[i] != 'u' && Cadena[i] != 'U')
        {
            CadenaFinal += Cadena[i];
        }
    }

    return CadenaFinal; // Devolver la cadena modificada sin las vocales.
}

/**
 * @brief Convierte una cadena de dígitos en un número entero.
 *
 * Esta función toma una cadena que representa un número y lo convierte en un valor entero.
 *
 * @param Cadena La cadena de dígitos que se convertirá en un número.
 * @return El número entero convertido desde la cadena de dígitos.
 */
int StringToNumber(string Cadena)
{
    int Numero = 0; // Variable para almacenar el número convertido.
    int i = 0;

    // Iterar a través de la cadena y construir el número entero.
    while (Cadena[i] != '\0')
    {
        Numero = Numero * 10 + (Cadena[i] - '0'); // Convertir el carácter en su equivalente numérico y agregarlo al número.
        i++;
    }

    return Numero; // Devolver el número entero convertido desde la cadena de dígitos.
}
/**
 * @brief Verifica si una cadena de texto es un palíndromo.
 *
 * Esta función verifica si la cadena de texto proporcionada es un palíndromo, es decir,
 * si se lee igual de adelante hacia atrás que de atrás hacia adelante.
 *
 * @param Cadena La cadena de texto que se verificará como palíndromo.
 * @return true si la cadena es un palíndromo, false si no lo es.
 */
bool StringPalindrome(string Cadena)
{
    string StringReverse = ReverseSelf(Cadena); // Invertir la cadena de texto.

    // Comparar la cadena original con su versión invertida para verificar si es un palíndromo.
    if (StringReverse == Cadena)
        return true;
    else
        return false;
}

/**
 * @brief Compara dos cadenas de texto para verificar si son iguales.
 *
 * Esta función compara dos cadenas de texto y determina si son iguales.
 *
 * @param Cadena1 La primera cadena que se comparará.
 * @param Cadena2 La segunda cadena que se comparará.
 * @return true si las cadenas son iguales, false si no lo son.
 */
bool StringComp(string Cadena1, string Cadena2)
{
    if (Cadena1 == Cadena2)
        return true;
    else
        return false;
}

/**
 * @brief Verifica si una cadena es una subcadena de otra cadena más grande.
 *
 * Esta función verifica si la SubCadena está presente como una subcadena dentro de la Cadena.
 *
 * @param Cadena La cadena principal en la que se buscará la subcadena.
 * @param SubCadena La cadena que se verificará como subcadena.
 * @return true si SubCadena es una subcadena de Cadena, false si no lo es.
 */
bool SubString(string Cadena, string SubCadena)
{
    // Iterar a través de la cadena principal y buscar la subcadena.
    for (int i = 0; Cadena[i] != '\0'; ++i)
    {
        bool esSubcadena = true;

        // Verificar si la subcadena está presente en la posición actual de la cadena principal.
        for (int j = 0; SubCadena[j] != '\0'; ++j)
        {
            if (Cadena[i + j] != SubCadena[j])
            {
                esSubcadena = false;
                break;
            }
        }

        // Si la subcadena fue encontrada, retornar verdadero.
        if (esSubcadena)
        {
            return true;
        }
    }

    // Si la subcadena no fue encontrada en ninguna posición, retornar falso.
    return false;
}
