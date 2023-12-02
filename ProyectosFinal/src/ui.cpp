#include "../include/ui.h"

using namespace std;

void imprimirCaracter(int x, int y, char caracter, int cantidad)
{
    gotoxy(x, y);
    for (int i = 0; i < cantidad; ++i)
    {
        Color(112);
        cout << caracter;
    }
}

void animacionBios()
{
    string LogoATM =
        "\n       d8888 88888888888 888b     d888 \n"
        "      d88888     888     8888b   d8888 \n"
        "     d88P888     888     88888b.d88888 \n"
        "    d88P 888     888     888Y88888P888 \n"
        "   d88P  888     888     888 Y888P 888 \n"
        "  d88P   888     888     888  Y8P  888 \n"
        " d8888888888     888     888       888 \n"
        "d88P     888     888     888       888 \n";

    for (char c : LogoATM)
    {
        cout << c;
        // Esperar 0.1 segundos antes de pasar al siguiente carácter
        Sleep(1);
    }
    cout << "\nNombre o eslogan del banco . . .\t" << char(169);

    gotoxy(50, 1);
    cout << "Bios del ATM";

    gotoxy(50, 2);
    cout << "Informacion sobre el hardware";

    gotoxy(50, 4);
    cout << "Mas informacion relevante";

    gotoxy(50, 5);
    cout << "Informacion del software";

    Sleep(1000);
}

Struct LONGITUD_CONSOLA()
{
    Struct s;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    s.Width = csbi.srWindow.Right - csbi.srWindow.Left - 1;
    s.Height = csbi.srWindow.Bottom - csbi.srWindow.Top - 1;
    return s;
}

Struct Len = LONGITUD_CONSOLA();
TEXT_STATE colorState;

void renderCapa0()
{
    CuadradoRelleno(0, 0, Len.Width, Len.Height, 8);
}

void renderCapa1()
{
    VentanaSombra1(3, 1, Len.Width - 3, Len.Height - 2, 7, 0);
}

void pantallaMenus()
{
    Color(colorState.normal);
    Cuadrado(4, 1, Len.Width - 4, Len.Height - 20, 1);
}
void renderCapa2()
{
    CuadradoRelleno(3, 1, Len.Width - 3, Len.Height - 21, 7);
}

void tecladoNumerico()
{
    Cuadrado(4, 10, Len.Width - 87, Len.Height - 1, 1);
    gotoxy(8, 12);
    cout << "1";
    gotoxy(9, 13);
    cout << ".";
    Cuadrado(5, 11, 12, 14, 0);

    gotoxy(17, 12);
    cout << "2";
    gotoxy(18, 13);
    cout << ",";
    Cuadrado(14, 11, 21, 14, 0);

    gotoxy(26, 12);
    cout << "3";
    gotoxy(27, 13);
    cout << "*";
    Cuadrado(23, 11, 30, 14, 0);

    gotoxy(8, 16);
    cout << "4";
    gotoxy(9, 17);
    cout << "+";
    Cuadrado(5, 15, 12, 18, 0);

    gotoxy(17, 16);
    cout << "5";
    gotoxy(18, 17);
    cout << "-";
    Cuadrado(14, 15, 21, 18, 0);

    gotoxy(26, 16);
    cout << "6";
    gotoxy(27, 17);
    cout << ";";
    Cuadrado(23, 15, 30, 18, 0);

    gotoxy(8, 20);
    cout << "7";
    gotoxy(9, 21);
    cout << "<";
    Cuadrado(5, 19, 12, 22, 0);

    gotoxy(17, 20);
    cout << "8";
    gotoxy(18, 21);
    cout << "#";
    Cuadrado(14, 19, 21, 22, 0);

    gotoxy(26, 20);
    cout << "9";
    gotoxy(27, 21);
    cout << ":";
    Cuadrado(23, 19, 30, 22, 0);

    gotoxy(8, 24);
    cout << "0";
    gotoxy(9, 25);
    cout << "$";
    Cuadrado(5, 23, 12, 26, 0);

    gotoxy(20, 24);
    cout << "Enter";
    Cuadrado(14, 23, 30, 26, 0);
}

void dispensadorEfectivo()
{
    Cuadrado(35, 10, Len.Width - 4, Len.Height - 10, 1);
    Cuadrado(41, 15, Len.Width - 10, 16, 1);
}

void ranuraDepositos()
{
    Cuadrado(35, 19, Len.Width - 4, Len.Height - 1, 1);
    Cuadrado(41, 24, Len.Width - 10, 25, 1);
}

void mostrarTextoMenuBienvenida()
{
    TEXTO texto;
    gotoxy(53, 1);
    cout << texto.TituloPantallaBienv;

    gotoxy(15, 3);
    cout << texto.Opcion1PantallaBienv;

    gotoxy(15, 5);
    cout << texto.Opcion2PantallaBienv;
}

void mostrarTextoMenuPrincipal()
{
    TEXTO texto;
    gotoxy(53, 1);
    cout << texto.TituloMenuPrincipal;

    gotoxy(15, 3);
    cout << texto.Opcion1MenuPrincipal;

    gotoxy(15, 4);
    cout << texto.Opcion2MenuPrincipal;

    gotoxy(15, 5);
    cout << texto.Opcion3MenuPrincipal;

    gotoxy(15, 6);
    cout << texto.Opcion4MenuPrincipal;

    gotoxy(25, 8);
    cout << texto.EntradaOpcionBase;
}

void mostrarTextoRanuras()
{
    TEXTO texto;
    gotoxy(63, 13);
    cout << texto.DispensadorEfectivo;

    gotoxy(65, 22);
    cout << texto.RanuraDepositos;
}

void menuOpcionesDeRetiro()
{
    TEXTO texto;
    gotoxy(45, 1);
    cout << texto.MenuRetiroTitulo;

    gotoxy(35, 4);
    cout << texto.MenuRetiroOpcion1;

    gotoxy(35, 5);
    cout << texto.MenuRetiroOpcion2;

    gotoxy(35, 6);
    cout << texto.MenuRetiroOpcion3;

    gotoxy(65, 4);
    cout << texto.MenuRetiroOpcion4;

    gotoxy(65, 5);
    cout << texto.MenuRetiroOpcion5;

    gotoxy(65, 6);
    cout << texto.MenuRetiroOpcion6;

    gotoxy(45, 8);
    cout << texto.MenuRetiroEntrada;
}
void manejarSaldoInsuficiente(const std::string &mensaje, int numeroCuenta, double saldo)
{
    OPCIONES_RETIRO opcionesRetiro;
    renderCapa2();
    pantallaMenus();
    gotoxy(20, 3);
    Color(colorState.warning);
    cout << mensaje;
    Color(colorState.normal);
    gotoxy(20, 4);
    cout << "Su saldo actual es: $" << saldo << std::endl;
    Sleep(2000);
    renderCapa2();
    pantallaMenus();
}

void animacionSalida()
{
    TEXT_STATE textState;
    renderCapa2();
    pantallaMenus();
    Color(colorState.susces);
    gotoxy(45, 5);
    cout << "Gracias por usar nuestros servicios . . .";
    Sleep(1000);
    Color(colorState.normal);
}

void mostrarError(const string &mensaje)
{
    cerr << "Error: " << mensaje << endl;
    cerr << "Posibles soliciones:" << endl;
    cerr << "- Verificar que el directorio $ROOT_DIR\\data\\ exista" << endl;
    cerr << "- verificar los nombre de las DB (database.txt, temp.txt, transacciones.txt)";
}

void tituloMenuDepositos()
{
    TEXTO text;
    renderCapa2();
    pantallaMenus();
    gotoxy(12, 3);
    cout << text.MenuDepositoTitulo;
}

void mostrarDepositoTransaccionCancelada()
{
    TEXT_STATE text;
    Color(text.susces);
    gotoxy(25, 6);
    cout << "!Transaccion cancelada con exito! Volviendo al menu principal.";
    Color(text.normal);
}

void mostrarDepositoDepRanura()
{
    TEXTO text;
    gotoxy(13, 4);
    cout << text.MenuDepositoDepRanura;
}

void mostrarDepositoCancelado()
{
    renderCapa3();
    gotoxy(25, 6);
    TEXT_STATE colorState;
    Color(colorState.warning);
    cout << "!Deposito CANCELADO por el usuario!. Volviendo al menu principal.";
    Color(colorState.normal);
}
void renderCapa3()
{
    CuadradoRelleno(23, 6, 100, 6, 7);
}
void mostrarDepositoExitoso()
{
    renderCapa3();
    gotoxy(25, 6);
    TEXT_STATE colorState;
    Color(colorState.susces);
    cout << "!Deposito REALIZADO con exito!. Volviendo al menu principal.";
    Color(colorState.normal);
}

void mostrarErrorTiempoDeposito()
{
    TEXTO text;
    TEXT_STATE testState;
    renderCapa2();
    pantallaMenus();
    gotoxy(30, 4);
    Color(colorState.error);
    cout << text.MenuDepositoTiempoErr1;
    gotoxy(20, 5);
    cout << text.MenuDepositoTiempoErr2;
    Color(colorState.normal);
}
void imprimirEspacios(int x, int y)
{
    for (int i = 0; i < 10; i++)
    {
        gotoxy(x + i, y);
        cout << ' ';
    }
}
void mostrarUsuarioEncontrado()
{
    gotoxy(70, 3);
    Color(colorState.susces);
    cout << ">>   Usuario encontrado!   <<";
    Color(colorState.normal);
}

void mostrarUsuarioNoEncontrado()
{
    gotoxy(70, 3);
    Color(colorState.error);
    cout << ">> Usuario NO encontrado! <<";
    Color(colorState.normal);
}

void mostrarNipCorrecto()
{
    gotoxy(70, 5);
    Color(colorState.susces);
    cout << ">>       NIP correcto.     <<";
    Color(colorState.normal);
}

void MostrarNipIncorrecto()
{
    gotoxy(70, 5);
    Color(colorState.warning);
    cout << ">>      NIP incorrecto.   <<" << endl;
    Color(colorState.normal);
}

void mostrarInformacionSaldo(int numeroCuenta, double saldo)
{
    Color(colorState.normal);
    renderCapa2();
    pantallaMenus();
    gotoxy(47, 1);
    cout << "Informacion del saldo:";
    gotoxy(40, 4);
    cout << "|  Numero de cuenta:       " << numeroCuenta;
    gotoxy(40, 5);
    cout << "|  Su saldo actual es:     $" << saldo;
    gotoxy(37, 8);
    system("pause");
}