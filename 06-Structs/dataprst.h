/**
 * @file Taller7.h
 * @author Nicolas Betancur Rios
 * @brief Manejar salida de datos en terminal
 *
 * Esta libreria provee funciones que pueden ser utilizadas para
 * imprimir formas y colores en la terminal
 */

#ifndef TALLER7_H
#define TALLER7_H

#include <stdio.h>
#include <windows.h>

/**
 * @brief Mueve el cursor en la consola.
 *
 * Esta función posiciona el cursor de la consola en las coordenadas (pos_x, pos_y).
 *
 * @param pos_x Coordenada X a la que se moverá el cursor.
 * @param pos_y Coordenada Y a la que se moverá el cursor.
 */

void gotoxy(int pos_x, int pos_y)
{
	HANDLE hConsoleOutput;
	COORD coord;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X = pos_x;
	coord.Y = pos_y;
	SetConsoleCursorPosition(hConsoleOutput, coord);
}

/**
 * @brief Cambia el color del texto y el fondo en la consola de Windows.
 *
 * Esta función cambia el color del texto y el fondo en la consola de Windows utilizando el valor
 * especificado como argumento. Los valores válidos generalmente varían de 0 a 255 y pueden
 * representar combinaciones de colores específicas en la paleta de colores de la consola.
 *
 * @param c Valor numérico que representa el color del texto y el fondo en la consola.
 *          (Los números de colores suelen depender del sistema, por ejemplo, en Windows son valores entre 0 y 255)
 */
void Color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

/**
 * @brief Muestra una lista de colores en la consola de Windows.
 *
 * Esta función muestra una lista de colores en la consola de Windows utilizando diferentes códigos
 * de color para el texto y el fondo. La lista incluye cuatro bloques de colores, cada uno con 64 colores.
 * Cada bloque representa una gama diferente de colores en la paleta de colores de la consola de Windows.
 */
void ListaColores()
{
	// Iterar a través de cuatro bloques de colores con 64 colores cada uno.
	for (int i = 0; i < 64; i++)
	{
		// Mostrar el color en la primera columna.
		gotoxy(1, i);
		Color(i);
		printf("Color %d", i);

		// Mostrar el color en la segunda columna.
		gotoxy(20, i);
		Color(i + 64);
		printf("Color %d", i + 64);

		// Mostrar el color en la tercera columna.
		gotoxy(40, i);
		Color(i + 128);
		printf("Color %d", i + 128);

		// Mostrar el color en la cuarta columna.
		gotoxy(60, i);
		Color(i + 192);
		printf("Color %d", i + 192);
	}

	// Restablecer el color de la consola a blanco después de mostrar la lista de colores.
	Color(7);
}
/**
 * @brief Muestra una lista de caracteres ASCII y sus códigos correspondientes en la consola de Windows.
 *
 * Esta función muestra una lista de caracteres ASCII y sus códigos correspondientes en la consola de Windows.
 * La lista se muestra en tres columnas, cada una conteniendo los códigos y los caracteres ASCII asociados.
 * La función itera a través de tres bloques de caracteres ASCII para mostrar una variedad de símbolos y caracteres.
 */
void ListaAscii()
{
	// Iterar a través de tres bloques de caracteres ASCII.
	for (int i = 0; i < 85; i++)
	{
		// Mostrar el código ASCII y el carácter en la primera columna.
		gotoxy(1, i);
		printf("%d : %c", i, (char)i);

		// Mostrar el código ASCII y el carácter en la segunda columna.
		gotoxy(20, i);
		printf("%d : %c", i + 85, (char)(i + 85));

		// Mostrar el código ASCII y el carácter en la tercera columna.
		gotoxy(40, i);
		printf("%d : %c", i + 170, (char)(i + 170));
	}
}
/**
 * @brief Crear una linea horizontal.
 *
 * Este procedimiento crea una linea horizontal teniendo en cuenta unas coordenadas
 * y un tope.
 *
 * @param x Coordenada X.
 * @param y Coordenada Y.
 * @param tope Tamaño de la linea horizontal.
 */
void LineaHorizontal(int x, int y, int tope)
{
	for (int i = 0; i <= tope; i++)
	{
		gotoxy(x + i, y);
		printf("%c", (char)196);
	}
}

/**
 * @brief Crear una linea vertical.
 *
 * Este procedimiento crea una linea vertical teniendo en cuenta unas coordenadas
 * y un tope.
 *
 * @param x Coordenada X.
 * @param y Coordenada Y.
 * @param tope Tamaño de la linea vertical.
 */
void LineaVertical(int x, int y, int tope)
{
	for (int i = 0; i <= tope; i++)
	{
		gotoxy(x, y + i);
		printf("%c", (char)179);
	}
}

/**
 * @brief Imprime un cuadrado en terminal
 *
 * Este procedimiento imprime un cuadrado en pantalla teniendo en cuenta unas coordenadas iniciales
 * y otras coordenadas que definen el tamaño del cuadro, ademas tambien recibe un tipo de borde que
 * puede ser de dos tipos | o  ║
 *
 * @param x1 Coordenada x1 para ubicar el cursor.
 * @param y1 Coordenada y1 para ubicar el cursor.
 * @param x2 Coordenada x2 para ubicar el cursor.
 * @param y2 Coordenada y2 para ubicar el cursor.
 * @param borde Tipo de borde a imprimir (0-1).
 */
void Cuadrado(int x1, int y1, int x2, int y2, int borde)
{

	/*
		Las siguientes 6 variable de tipo char definen el tipo de borde espcificado por la variable 'borde'
		Ej:
			Horizontal          -> '─ , ═' (196, 205)
			Vertical            -> '| , ║' (179 ,186)
			EsquinaSupDerecha   -> '┐ , ╗' (191 ,187)
			EsquinaSupIzquierda -> '┌ , ╔' (218, 201)
			EsquinaInfDerecha   -> '┘ , ╝' (217, 188)
			EsquinaInfIzquierda -> '└ , ╚' (192, 200)
	*/

	char Horizontal, Vertical, EsquinaSupDerecha, EsquinaSupIzquierda,
		EsquinaInfDeracha, EsquinaInfIzquierda;

	if (borde == 0) // Asignar un tipo de borde a cada variable dependiendo de la eleccion del usuario
	{
		Horizontal = char(196);
		Vertical = char(179);
		EsquinaSupDerecha = char(191);
		EsquinaSupIzquierda = char(218);
		EsquinaInfDeracha = char(217);
		EsquinaInfIzquierda = char(192);
	}
	else if (borde == 1)
	{
		Horizontal = char(205);
		Vertical = char(186);
		EsquinaSupDerecha = char(187);
		EsquinaSupIzquierda = char(201);
		EsquinaInfDeracha = char(188);
		EsquinaInfIzquierda = char(200);
	}
	else
	{
		printf("Opcion %d fuera de rango\nOpciones posibles: (0 |, 1 ║)\n", borde); // error si borde > 1
	}

	for (int i = x1; i <= x2; i++)
	{
		gotoxy(i, y1); // Crea la linea horizontal superior.
		printf("%c", Horizontal);

		gotoxy(i, y2);
		printf("%c", Horizontal); // Crea la linea horizontal inferior.

		for (int j = y1; j <= y2; j++)
		{
			gotoxy(x1, j);
			printf("%c", Vertical); // Crea la linea vertical izquierda.

			gotoxy(x2, j);
			printf("%c", Vertical); // Crea la liea vertical derecha.
		}

		/*
			Se remplazan los caracteres de las esquinas por los caracteres correspondientes
			a cada esquina.
		*/
		gotoxy(x1, y1);
		printf("%c", EsquinaSupIzquierda);

		gotoxy(x1, y2);
		printf("%c", EsquinaInfIzquierda);

		gotoxy(x2, y1);
		printf("%c", EsquinaSupDerecha);

		gotoxy(x2, y2);
		printf("%c", EsquinaInfDeracha);
	}
	printf("\n"); // Salto de linea para formar la figura
}

/**
 * @brief Dibuja un cuadrado relleno en la consola.
 *
 * Esta función dibuja un cuadrado relleno en la consola con un color de relleno especificado.
 *
 * @param x1 Coordenada x del primer punto superior izquierdo del cuadrado.
 * @param y1 Coordenada y del primer punto superior izquierdo del cuadrado.
 * @param x2 Coordenada x del segundo punto inferior derecho del cuadrado.
 * @param y2 Coordenada y del segundo punto inferior derecho del cuadrado.
 * @param colorRelleno Número del color que se utilizará para el relleno del cuadrado.
 */
void CuadradoRelleno(int x1, int y1, int x2, int y2, int colorRelleno)
{
	Color(colorRelleno);
	for (int y = y1 + 1; y < y2; y++)
	{
		for (int x = x1 + 1; x < x2; x++)
		{
			gotoxy(x, y);
			printf("%c", 219); //  ASCII 219
		}
	}
	// Restaurar el color original (por ejemplo, blanco)
	Color(7);
}

/**
 * @brief Crea una ventana con un sombreado en la parte inferior y derecha.
 *
 * Esta función crea una ventana en la consola con un área de sombra en la parte
 * inferior y derecha. La ventana está rellena con un color de fondo especificado,
 * y el sombreado se dibuja con un color de sombra específico.
 *
 * @param x1 Coordenada x del primer punto superior izquierdo de la ventana.
 * @param y1 Coordenada y del primer punto superior izquierdo de la ventana.
 * @param x2 Coordenada x del segundo punto inferior derecho de la ventana.
 * @param y2 Coordenada y del segundo punto inferior derecho de la ventana.
 * @param ColorFondo Número del color que se utilizará para el fondo de la ventana.
 * @param ColorSombra Número del color que se utilizará para el sombreado de la ventana.
 */
void VentanaSombra1(int x1, int y1, int x2, int y2, int ColorFondo, int ColorSombra)
{
	// Dibujar el área de la ventana rellena con el color de fondo especificado.
	CuadradoRelleno(x1, y1, x2, y2, ColorFondo);

	// Dibujar el sombreado en la esquina inferior derecha.
	Color(ColorSombra);

	// Dibujar el sombreado en la parte inferior.
	for (int j = y1 + 1; j <= y2 + 1; j++)
	{
		gotoxy(x2 + 1, j);
		printf("%c", char(219));
	}

	// Dibujar el sombreado en el borde derecho.
	for (int i = x1 + 1; i <= x2 + 1; i++)
	{
		gotoxy(i, y2 + 2);
		printf("%c", char(219));
	}

	// Restaurar el color original de la consola (por ejemplo, blanco).
	printf("\n");
	Color(7);
}

/**
 * @brief Crea una ventana con un área de sombra y un título.
 *
 * Esta función crea una ventana en la consola con un área de sombra en la parte inferior
 * y derecha y un título en la parte superior. La ventana está rellena con un color de fondo
 * especificado, el área de sombra se dibuja con un color de sombra específico y el título se
 * imprime con un color de título específico.
 *
 * @param x1 Coordenada x del primer punto superior izquierdo de la ventana.
 * @param y1 Coordenada y del primer punto superior izquierdo de la ventana.
 * @param x2 Coordenada x del segundo punto inferior derecho de la ventana.
 * @param y2 Coordenada y del segundo punto inferior derecho de la ventana.
 * @param ColorTitulo Número del color que se utilizará para el título de la ventana.
 *                    (Los números de colores suelen depender del sistema, por ejemplo, en Windows son valores entre 0 y 255)
 * @param ColorFondo Número del color que se utilizará para el fondo de la ventana.
 *                   (Los números de colores suelen depender del sistema, por ejemplo, en Windows son valores entre 0 y 255)
 * @param ColorSombra Número del color que se utilizará para el sombreado de la ventana.
 *                    (Los números de colores suelen depender del sistema, por ejemplo, en Windows son valores entre 0 y 255)
 */
void VentanaSombra2(int x1, int y1, int x2, int y2, int ColorTitulo, int ColorFondo, int ColorSombra)
{
	// Crear una ventana con área de sombra usando la función VentanaSombra1.
	VentanaSombra1(x1, y1, x2, y2, ColorFondo, ColorSombra);

	// Cambiar el color para el título y dibujar el borde superior del título.
	Color(ColorTitulo);
	for (int i = x1; i <= x2; i++)
	{
		gotoxy(i, y1);
		printf("%c", char(219));
	}

	// Posicionar el cursor en la línea siguiente para futuras impresiones.
	gotoxy(x2 + 1, y2 + 1);

	// Restaurar el color original de la consola (por ejemplo, blanco).
	printf("\n");
	Color(7);
}
/**
 * @brief Dibuja una tabla en la consola con bordes personalizables.
 *
 * Esta función dibuja una tabla en la consola con un número específico de filas y columnas.
 * Los bordes y el estilo de intersección pueden ser personalizados mediante el parámetro 'borde'.
 *
 * @param x1 Coordenada x del primer punto superior izquierdo de la tabla.
 * @param y1 Coordenada y del primer punto superior izquierdo de la tabla.
 * @param filas Número de filas de la tabla.
 * @param columnas Número de columnas de la tabla.
 * @param borde Tipo de bordes y estilo de intersección de la tabla (0: Simple, 1: Doble).
 * @note El cuadro se imprime incorrectamente cuando x1 y y1 son diferentes de 0.
 * @note Actualmente el char InterseccionLineaSuperior no se usa [-Wunused-but-set-variable].
 */
void Tabla(int x1, int y1, int filas, int columnas, int borde)
{
	char Horizontal, Vertical, EsquinaSupDerecha, EsquinaSupIzquierda,
		EsquinaInfDerecha, EsquinaInfIzquierda, InterseccionLineaIzquierda, InterseccionLineaDerecha, InterseccionCruz /*InterseccionLineaSuperior,*/;

	// variable encargada de manejar el ancho de cada celda.
	int ancho = 10; // ancho default = 10.

	// Determinar los caracteres para los bordes y las intersecciones según el tipo de borde seleccionado.
	if (borde == 0)
	{
		// Bordes simples
		Horizontal = char(196);			 // Linea horizontal
		Vertical = char(179);			 // Linea vertical
		EsquinaSupDerecha = char(191);	 // Esquina superior derecha
		EsquinaSupIzquierda = char(218); // Esquina superior izquierda
		EsquinaInfDerecha = char(217);	 // Esquina inferior derecha
		EsquinaInfIzquierda = char(192); // Esquina inferior izquierda
		// InterseccionLineaSuperior = char(194);	// Intersección de línea superior
		InterseccionLineaIzquierda = char(195); // Intersección de línea izquierda
		InterseccionLineaDerecha = char(180);	// Intersección de línea derecha
		InterseccionCruz = char(197);			// Intersección de cruz
	}
	else if (borde == 1)
	{
		// Bordes dobles
		Horizontal = char(205);
		Vertical = char(186);
		EsquinaSupDerecha = char(187);
		EsquinaSupIzquierda = char(201);
		EsquinaInfDerecha = char(188);
		EsquinaInfIzquierda = char(200);
		// InterseccionLineaSuperior = char(203);
		InterseccionLineaIzquierda = char(204);
		InterseccionLineaDerecha = char(185);
		InterseccionCruz = char(206);
	}
	else
	{
		printf("ERROR: Opcion desconocida");
		return; // Salir de la función si la opción de borde es desconocida.
	}

	// Dibujar la tabla
	for (int i = 0; i <= filas; ++i)
	{
		for (int j = 0; j <= columnas; ++j)
		{
			if (i == 0 || j == 0)
			{
				printf("%c", Horizontal);
			}
			else
			{
				printf("%c", InterseccionCruz);
			}

			if (j < columnas)
			{
				for (int k = 0; k < ancho; ++k)
				{
					printf("%c", Horizontal);
				}
			}
		}
		printf("\n");

		if (i < filas)
		{
			for (int l = 0; l <= columnas; ++l)
			{
				if (l == 0)
				{
					printf("%c", Vertical);
				}
				else
				{
					printf("%c", Vertical);
				}

				if (l < columnas)
				{
					for (int m = 0; m < ancho; ++m)
					{
						printf(" ");
					}
				}
			}
			printf("\n");
		}
	}

	// Dibujar los bordes exteriores de la tabla.
	for (int s = 0; s < filas * 2; s = s + 2)
	{
		gotoxy(x1, y1 + s);
		printf("%c", InterseccionLineaIzquierda);

		gotoxy(x1 + columnas * ancho + columnas, y1 + s);
		printf("%c", InterseccionLineaDerecha);
	}

	// Dibujar las esquinas de la tabla.
	gotoxy(x1, y1);
	printf("%c", EsquinaSupIzquierda);
	gotoxy(x1, y1 + filas * 2);
	printf("%c", EsquinaInfIzquierda);
	gotoxy(x1 + columnas * ancho + columnas, y1);
	printf("%c", EsquinaSupDerecha);
	gotoxy(x1 + columnas * ancho + columnas, y1 + filas * 2);
	printf("%c", EsquinaInfDerecha);
}
#endif