#ifndef DATAPRST_H
#define DATAPRST_H

// Declaraciones de funciones
void gotoxy(int pos_x, int pos_y);
void Color(int c);
void ListaColores();
void ListaAscii();
void LineaHorizontal(int x, int y, int tope);
void LineaVertical(int x, int y, int tope);
void Cuadrado(int x1, int y1, int x2, int y2, int borde);
void CuadradoRelleno(int x1, int y1, int x2, int y2, int colorRelleno);
void VentanaSombra1(int x1, int y1, int x2, int y2, int ColorFondo, int ColorSombra);
void VentanaSombra2(int x1, int y1, int x2, int y2, int ColorTitulo, int ColorFondo, int ColorSombra);
void Tabla(int x1, int y1, int filas, int columnas, int borde);

#endif // dataprs_H