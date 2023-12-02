/**
 * @file ATM.h
 * @author Nicolas Betancur Rios (1093212122)
 * @brief Definicion de librerias, funciones y estructuras necesarios para la logica del ATM
 * @version 1.1
 * @date 2023-11-26
 */

#ifndef ATM_H
#define ATM_H

#include <iostream>  // cin, cout
#include <windows.h> // Sleep, ui.h
#include <fstream>   // ifstream, ofstream ...
#include <string>    // string, string_to_number
#include <ctime>     // time
#include <conio.h>   // _hkhib, _getch

/**
 * @brief Estructura que almacena los datos basicos del usuario
 *
 */
struct USUARIO
{
    int NumeroDeCuenta; /** Numero de cuenta del usuario */
    int NIP;            /** NIP o contraseña del usuario */
    double Balance;     /** saldo del usuario */
};

/**
 * @brief Estructura que representa la información de un retiro.
 */
struct INFO_RETIRO
{
    int NumeroDeDocumentoRetiro; /** Número de documento asociado al retiro. */
    int MontoRetiro;             /** Monto retirado en la transacción. */
    std::string tipoDeRetiro;    /** Tipo de retiro realizado. */
    std::string FechaHoraRetiro; /** Fecha y hora en que se realizó el retiro. */
};

/**
 * @brief Estrucutra que representa las opciones de retiro desponibles y su valor
 *
 */
struct OPCIONES_RETIRO
{
    int Opcion1 = 20;    /** Primera opcion eq. 20$ */
    int Opcion2 = 40;    /** Segunda opcion eq. 40$ */
    int Opcion3 = 60;    /** Tercera opcion eq. 80$ */
    int Opcion4 = 100;   /** Cuarta opcion eq. 100$ */
    int Opcion5 = 200;   /** Quinta opcion eq. 200$ */
    bool Opcion6 = NULL; /** Sexta opcion eq. salir */
};

/**
 * @brief Estructura que almacena datos relevantes del ATM
 *
 */
struct ATM
{
    const char *BaseDatosPrincipal = "..\\data\\database.txt";          /** Ruta de la db principal. */
    const char *BaseDatosTemporal = "..\\data\\temp.txt";               /** Ruta de la db temporal. */
    const char *BaseDatosTransacciones = "..\\data\\transacciones.txt"; /** Ruta de la db de log de transacciones. */
    int SaldoInicial = 500 * 20;                                        /** Saldo inicial del cajero. */
};

/**
 * @brief Obtiene la cantidad de dígitos en un número entero.
 *
 * @param numero Número del cual se desea conocer la cantidad de dígitos.
 * @return Cantidad de dígitos en el número.
 */
int numeroLen(int numero);

/**
 * @brief Borra la entrada anterior en la pantalla.
 *
 * @param x Coordenada x en la pantalla.
 * @param y Coordenada y en la pantalla.
 * @param longitud Longitud de la entrada anterior a borrar.
 */
void borrarInputAnterior(int x, int y, int longitud);

/**
 * @brief Lógica para el menú de bienvenida.
 */
void logicaMenuBienvenida();

/**
 * @brief Busca un usuario en la base de datos.
 *
 * @param numeroDeCuenta Número de cuenta del usuario.
 * @param nip NIP del usuario.
 * @return True si el usuario es encontrado, False en caso contrario.
 */
bool buscarUsuario(int numeroDeCuenta, int nip);

/**
 * @brief Lógica para el menú principal.
 *
 * @param numeroCuenta Número de cuenta del usuario.
 * @param saldo Saldo actual del usuario.
 */
void logicaMenuPrincipal(int numeroCuenta, double saldo);

/**
 * @brief Muestra el saldo del usuario.
 *
 * @param numeroCuenta Número de cuenta del usuario.
 * @param saldo Saldo actual del usuario.
 */
void verSaldo(int numeroCuenta, double saldo);

/**
 * @brief Actualiza el saldo del usuario después de un retiro.
 *
 * @param numeroCuenta Número de cuenta del usuario.
 * @param saldo Saldo actual del usuario.
 * @param montoRetiro Monto retirado en la transacción.
 */
void actualizarSaldo(int numeroCuenta, double saldo, int montoRetiro);

/**
 * @brief Obtiene el monto de retiro según las opciones y la selección del usuario.
 *
 * @param opciones Opciones disponibles para el retiro.
 * @param seleccionUsuario Selección del usuario en cuanto al monto de retiro.
 * @return Monto de retiro seleccionado.
 */
int montoDeRetiro(const OPCIONES_RETIRO &opciones, int seleccionUsuario);

/**
 * @brief Realiza un depósito en la cuenta del usuario.
 *
 * @param numeroCuenta Número de cuenta del usuario.
 * @param saldo Saldo actual del usuario.
 */
void realizarDeposito(int numeroCuenta, double saldo);

/**
 * @brief Registra la información de un depósito o retiro en una db.
 *
 * @param numeroCuenta Número de cuenta del usuario.
 * @param saldo Saldo actual del usuario.
 * @param tipoDeposito Tipo de transacción (depósito o retiro).
 */
void registroDeRegistros(int numeroCuenta, double saldo, std::string tipoTransaccion);

/**
 * @brief Obtiene el tiempo transcurrido desde el inicio del programa.
 *
 * @return Tiempo transcurrido en segundos.
 */
int tiempoTranscurrido();

/**
 * @brief Muestra el menú de opciones para el usuario con privilegios de administrador.
 */
void mostrarMenuRoot();

#endif // ATM_h
