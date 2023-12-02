
#include <iostream>
#include "../include/ui.h"
#include "../include/ATM.h"

/*
    Este es el archivo principal del ATM, es fundamental para la correcta ejecucion del programa
    y es el archivo que se compila he incluye las demas librerias.

    El proyecto esta dividido en diferentes librerias, cada libreria tiene un archivo almacenados
    en include (archivos .h),donde se definen las funciones procedimientos, estructuras, etc.
    y tambien tienen un archivo almacenado en src (archivo.cpp) los cuales implementan las funciones

    El ejecutable del proyecto esta disponible en el directorio build o se puede hacer una compilacion
    limpia desde cero ejecutando <build> en la carpeta raiz del proyecto en una CMD

    El proyexto esta diseñado para ser ejecutado en una terminal con dimensiones especificas
    las dimensiones son 120 X 30, generalmente es el tamaño default de las ventanas flotantes en windows,
    para evitar errores de renderisado no se recomienda ejecutar en ventana completa, y en caso de ver
    fallas de renderisado en ventana flotante hay que configurar las dimensiones de la terminal.

    <Click derecho en el titulo del cmd> propiedades > Diseño > Tamaño de la ventana

*/

/**
 * @brief Funcion principal que ejecuta las funciones indispesable del ATM
 *
 * @return int
 */
int main()
{
    animacionBios(); // Animacion Inicial

    // Capas de colores
    renderCapa0();
    renderCapa1();

    // Partes del ATM
    pantallaMenus();
    tecladoNumerico();
    dispensadorEfectivo();
    ranuraDepositos();

    // Textos fundamentales
    mostrarTextoRanuras();
    mostrarTextoMenuBienvenida();

    // Primier menu de bienvenida
    logicaMenuBienvenida();

    gotoxy(2, 30);
    system("pause");
    return 0;
}