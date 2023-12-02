/**
 * @file main.cpp
 * @author Nicolas Betancur Rios
 * @brief usar libreria de presentacion de datos
 *
 * Este programa tiene como objetivo usar la libreria de presentacion de datos "Taller7.h"
 * y crear un menu para acceder a las funciones de dicha libreria.
 *
 */
#include <cstdio>    // Entrada y salida de datos
#include <stdlib.h>  // exit()
#include <conio.h>   // getch()
#include "Taller7.h" // Presentacion de datos

/**
 * @brief Muestra un menú en la consola y permite al usuario seleccionar diferentes opciones para dibujar figuras y tablas.
 *
 * Esta función presenta un menú en la consola y permite al usuario seleccionar diferentes opciones.
 * Las opciones incluyen dibujar cuadros en la pantalla, cuadros con relleno, ventanas con sombra, ventanas con barra de título
 * y dibujar tablas con cierto número de columnas y filas. La función solicita datos al usuario, dibuja las figuras o tablas
 * correspondientes en la consola y muestra información sobre las coordenadas y los colores utilizados.
 */
void Menu()
{
    // Variables para las opciones del menú y las coordenadas de las figuras.
    int Opcion, x1, y1, x2, y2, borde,
        ColorRelleno, ColorSombra, ColorTitulo, filas, columnas;

    // Limpiar la pantalla y mostrar el título del taller y el menú principal.
    system("cls");
    gotoxy(3, 1);
    printf("Taller 7 - presentacion de datos");
    gotoxy(10, 2);
    printf("Menu principal . . .\n");
    printf("\n 1. Dibujar cuadrado en pantalla.");
    printf("\n 2. Dibujar cuadrado con relleno.");
    printf("\n 3. Dibujar una ventana con sombra.");
    printf("\n 4. Dibujar una ventana con barra de titulo.");
    printf("\n 5. Dibujar tabla con n columnas y m filas. ");
    printf("\n 6. Salir.\n");
    gotoxy(4, 11);
    printf("Opcion (1 | 6)?: ");
    scanf("%d", &Opcion);

    switch (Opcion)
    {
    case 1:
        // Opción para dibujar un cuadro en la pantalla.
        system("cls");
        gotoxy(5, 1); // centrar el titulo.
        printf("Seleccionado: 1. Dibujar cuadrado en pantalla.\n");
        printf("\n - Selecciona el borde (0 %c, 1 %c)?: ", char(179), char(186));
        scanf("%d", &borde);

        // Solicitar coordenadas y tipo de borde al usuario.
        printf(" - Ingresa la coordenada x1: ");
        scanf("%d", &x1);
        printf(" - Ingresa la coordenada y1: ");
        scanf("%d", &y1);
        printf(" - Ingresa la coordenada x2: ");
        scanf("%d", &x2);
        printf(" - Ingresa la coordenada y2: ");
        scanf("%d", &y2);
        system("cls");

        // Llamar a la función Cuadrado para dibujar el cuadro.
        Cuadrado(x1, y1, x2, y2, borde);

        // Mostrar información sobre las coordenadas del cuadro.
        printf("\nCoordenadas del cuadro: \n x1 = %d   y1 = %d,\n x2 = %d   y2 = %d\n", x1, y1, x2, y2);

        // Esperar a que el usuario presione una tecla y volver al menú.
        printf("\nPresiona una tecla para volver al menu . . .");
        getch();

        // Llamado recursivo a menu.
        Menu();
        break;
    case 2:
        // Opción para dibujar un cuadro con relleno.
        system("cls");
        gotoxy(5, 1);
        printf("Seleccionado: 2. Dibujar cuadrado con relleno.\n");

        // Solicitar coordenadas, color de relleno al usuario.
        printf("\n - Ingresa la coordenada x1: ");
        scanf("%d", &x1);
        printf(" - Ingresa la coordenada y1: ");
        scanf("%d", &y1);
        printf(" - Ingresa la coordenada x2: ");
        scanf("%d", &x2);
        printf(" - Ingresa la coordenada y2: ");
        scanf("%d", &y2);
        printf(" - Ingresa el color de relleno: ");
        scanf("%d", &ColorRelleno);
        system("cls");

        // Llamar a la función CuadradoRelleno para dibujar el cuadro con relleno.
        CuadradoRelleno(x1, y1, x2, y2, ColorRelleno);

        // Mostrar información sobre las coordenadas y el color del cuadro.
        printf("\nCoordenadas del cuadro: \n x1 = %d,   y1 = %d,\n x2 = %d,   y2 = %d\nInformacion de color:\n Color de relleno: %d\n", x1, y1, x2, y2, ColorRelleno);

        // Esperar a que el usuario presione una tecla y volver al menú.
        printf("\nPresiona una tecla para volver al menu ...");
        getch();

        // Llamado recursivo a menu.
        Menu();
        break;

    case 3:
        // Opción para dibujar una ventana con sombra.
        system("cls");
        gotoxy(5, 1);
        printf("Seleccionado: 3. Dibujar una ventana con sombra.\n");

        // Solicitar coordenadas, color de relleno, color de sombra al usuario.
        printf("\n - Ingresa la coordenada x1: ");
        scanf("%d", &x1);
        printf(" - Ingresa la coordenada y1: ");
        scanf("%d", &y1);
        printf(" - Ingresa la coordenada x2: ");
        scanf("%d", &x2);
        printf(" - Ingresa la coordenada y2: ");
        scanf("%d", &y2);
        printf(" - Ingresa el color de relleno: ");
        scanf("%d", &ColorRelleno);
        printf(" - Ingresa el color de sombra: ");
        scanf("%d", &ColorSombra);
        system("cls");

        // Llamar a la función VentanaSombra1 para dibujar la ventana con sombra.
        VentanaSombra1(x1, y1, x2, y2, ColorRelleno, ColorSombra);

        // Mostrar información sobre las coordenadas y los colores de la ventana.
        printf("\nCoordenadas del cuadro: \n x1 = %d,   y1 = %d,\n x2 = %d,   y2 = %d\n\nInformacion de color:\n Color de relleno: %d\n Color de sombra: %d\n", x1, y1, x2, y2, ColorRelleno, ColorSombra);

        // Esperar a que el usuario presione una tecla y volver al menú.
        printf("\nPresiona una tecla para volver al menu ...");
        getch();

        // Llamado recursivo a menu.
        Menu();
        break;

    case 4:
        // Opción para dibujar una ventana con barra de título.
        system("cls");
        gotoxy(5, 1);
        printf("Seleccionado: 4. Dibujar una ventana con barra de titulo.\n");

        // Solicitar coordenadas, color del título, color de relleno, color de sombra al usuario.
        printf("\n - Ingresa la coordenada x1: ");
        scanf("%d", &x1);
        printf(" - Ingresa la coordenada y1: ");
        scanf("%d", &y1);
        printf(" - Ingresa la coordenada x2: ");
        scanf("%d", &x2);
        printf(" - Ingresa la coordenada y2: ");
        scanf("%d", &y2);
        printf(" - Ingresa el color del titulo: ");
        scanf("%d", &ColorTitulo);
        printf(" - Ingresa el color de relleno: ");
        scanf("%d", &ColorRelleno);
        printf(" - Ingresa el color de sombra: ");
        scanf("%d", &ColorSombra);
        system("cls");

        // Llamar a la función VentanaSombra2 para dibujar la ventana con título y sombra.
        VentanaSombra2(x1, y1, x2, y2, ColorTitulo, ColorRelleno, ColorSombra);

        // Mostrar información sobre las coordenadas y los colores de la ventana.
        printf("\nCoordenadas del cuadro: \n x1 = %d,   y1 = %d,\n x2 = %d,   y2 = %d\n\nInformacion de color:\n Color del titulo: %d\n Color de relleeno: %d\n Color de sombra: %d\n", x1, y1, x2, y2, ColorTitulo, ColorRelleno, ColorSombra);

        // Esperar a que el usuario presione una tecla y volver al menú.
        printf("\nPresiona una tecla para volver al menu ...");
        getch();

        // Llamado recursivo a menu.
        Menu();
        break;

    case 5:
        // Opción para dibujar una tabla con cierto número de columnas y filas.
        system("cls");
        gotoxy(5, 1);
        printf("Seleccionado: 5. Dibujar tabla con n columnas y m filas.\n");

        // Solicitar coordenadas, número de filas, número de columnas, tipo de borde al usuario.
        printf("\n - Ingresa la coordenada x1: ");
        scanf("%d", &x1);
        printf(" - Ingresa la coordenada y1: ");
        scanf("%d", &y1);
        printf(" - Ingresa el numero de filas: ");
        scanf("%d", &filas);
        printf(" - Ingresa el numero de columnas: ");
        scanf("%d", &columnas);
        printf("\n - Selecciona el borde (0 %c, 1 %c)?: ", char(179), char(186));
        scanf("%d", &borde);
        system("cls");

        // Llamar a la función Tabla para dibujar la tabla.
        Tabla(x1, y1, filas, columnas, borde);

        // Mostrar información sobre las coordenadas, el número de filas y columnas, y el tipo de borde de la tabla.
        printf("\nCoordenadas de la tabla: \n x1 = %d,   y1 = %d,\n Numero de filas: %d\n Numero de columnas: %d\n Tipo de borde: %d\n", x1, y1, filas, columnas, borde);

        // Esperar a que el usuario presione una tecla y volver al menú.
        printf("\nPresiona una tecla para volver al menu ...");
        getch();

        // Llamado recursivo a menu.
        Menu();

        break;
    case 6:
        // Opcion para salir del programa.
        exit(0);
        break;

    default:
        break;
    }
}

/**
 * @brief Función principal del programa.
 *
 * La función principal del programa. Llama a la función Menu para iniciar el programa.
 *
 * @return Devuelve 0 si el programa se ejecuta correctamente.
 */
int main()
{
    // Llamar a el procedimiento Menu.
    Menu();
    return 0;
}