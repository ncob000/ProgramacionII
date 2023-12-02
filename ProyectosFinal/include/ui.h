#ifndef UI_H
#define UI_H

#include <string>
#include <iostream>
#include <windows.h>
#include "dataprst.h"
#include "ATM.h"
// Definición de una estructura para representar ancho y alto
struct WIDTH_HEIGHT
{
    int Width;  // Ancho
    int Height; // Alto
};

// Alias para simplificar el uso de la estructura WIDTH_HEIGHT
typedef struct WIDTH_HEIGHT Struct;

// Función para obtener las dimensiones de la consola (ancho y alto)
Struct LONGITUD_CONSOLA();

// Función que realiza una animación de inicio estilo BIOS
void animacionBios();

// Funciones para renderizar diferentes capas de la interfaz de usuario
void renderCapa0();
void renderCapa1();
void renderCapa2();
void renderCapa3();

// Función para mostrar la pantalla de menús
void pantallaMenus();

// Función para gestionar el teclado numérico
void tecladoNumerico();

// Función para simular el dispensador de efectivo
void dispensadorEfectivo();

// Función para simular la ranura de depósitos
void ranuraDepositos();

// Funciones para mostrar diferentes textos en la interfaz de usuario
void mostrarTextoMenuBienvenida();
void mostrarTextoRanuras();
void mostrarTextoMenuPrincipal();

// Función para gestionar el menú de saldo
void menuSaldo();

// Función para imprimir un carácter en una posición dada
void imprimirCaracter(int x, int y, char caracter, int cantidad);

// Función para mostrar el menú de opciones de retiro
void menuOpcionesDeRetiro();

// Función para manejar la situación de saldo insuficiente
void manejarSaldoInsuficiente(const std::string &mensaje, int numeroCuenta, double saldo);

// Función para mostrar mensajes de error
void mostrarError(const std::string &mensaje);

// Función para mostrar el título del menú de depósitos
void tituloMenuDepositos();

// Funciones para mostrar mensajes relacionados con depósitos
void mostrarDepositoTransaccionCancelada();
void mostrarDepositoCancelado();
void mostrarDepositoExitoso();
void mostrarDepositoDepRanura();

// Función para mostrar un mensaje de error relacionado con el tiempo de depósito
void mostrarErrorTiempoDeposito();

// Funciones para mostrar mensajes relacionados con la búsqueda de usuarios
void mostrarUsuarioEncontrado();
void mostrarUsuarioNoEncontrado();

// Funciones para mostrar mensajes relacionados con la validación del NIP
void mostrarNipCorrecto();
void MostrarNipIncorrecto();

// Función para imprimir espacios en una posición dada
void imprimirEspacios(int x, int y);

// Función que simula una animación de salida
void animacionSalida();

// Función para mostrar información de saldo en la interfaz de usuario
void mostrarInformacionSaldo(int numeroCuenta, double saldo);

// Estrucutra que almacena diferentes tipos de texto repetitivos con el objetivo de
// que puedan ser reutilizados
struct TEXTO
{
    const char *DispensadorEfectivo = "Dispensador de efectivo";
    const char *RanuraDepositos = "Ranura de depositos";
    const char *TituloPantallaBienv = " BIENVENIDO! ";
    const char *Opcion1PantallaBienv = "| - Escriba su numero de cuenta >>";
    const char *Opcion2PantallaBienv = "| - Escriba su NIP >> ";
    const char *TituloMenuPrincipal = " MENU PRINCIPAL ";
    const char *Opcion1MenuPrincipal = "| - 1. Ver mi saldo";
    const char *Opcion2MenuPrincipal = "| - 2. Retirar fondos";
    const char *Opcion3MenuPrincipal = "| - 3. Depositar fondos";
    const char *Opcion4MenuPrincipal = "| - 4. Salir";
    const char *EntradaOpcionBase = " Escriba una opcion: ";
    const char *MenuRetiroTitulo = " OPCIONES DE RETIRO ";
    const char *MenuRetiroOpcion1 = " 1 - $20 ";
    const char *MenuRetiroOpcion2 = " 2 - $40 ";
    const char *MenuRetiroOpcion3 = " 3 - $60 ";
    const char *MenuRetiroOpcion4 = " 4 - $100 ";
    const char *MenuRetiroOpcion5 = " 5 - $200 ";
    const char *MenuRetiroOpcion6 = " 6 - Cancelar transaccion ";
    const char *MenuRetiroEntrada = " Elija una opcion (1 | 6): ";
    const char *MenuDepositoTitulo = " - Introduzca el monto de deposito o escriba 0 para cancelar la transaccion >> ";
    const char *MenuDepositoDepRanura = " - Por favor, introduzca el deposito en la ranura de depositos.";
    const char *MenuDepositoConfirmar = "Presione '1' para confirmar o '0' para cancelar.";
    const char *MenuDepositoTiempoErr1 = " El tiempo de espera ha superado los 20 segundos";
    const char *MenuDepositoTiempoErr2 = " Porfavor recuerde que solo tiene 20 segundos para hacer el deposito";
};

// Estado del texto
struct TEXT_STATE
{
    int normal = 112;
    int susces = 32;
    int warning = 96;
    int error = 64;
};

#endif // UI_H
