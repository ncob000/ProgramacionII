#include "../include/ATM.h" // Archivo de cabebecera, definicion de funciones y estructuras del ATM
#include "../include/ui.h"  // Archivo de cabecera, definicion de funciones y estructuras del UI
using namespace std;

int numeroLen(int numero)
{
    string numeroComoCadena = to_string(numero);     // Covierte el numero a cadena
    int cantidadDigitos = numeroComoCadena.length(); // Calcula la longitud de la cadena
    return cantidadDigitos;
}

void remplazarInputAnterior(int x, int y, int longitud)
{
    /* ImprimirCaracteres esta definida en ui.h*/
    imprimirCaracter(x, y, 158, longitud); // 219 es el código ASCII para el bloque cuadrado
}

void logicaMenuBienvenida()
{

    // Estructura para almacenar la información del usuario
    USUARIO user;

    // Variables temporales para almacenar el número de cuenta y NIP
    int numeroCuenta;
    int nip;

    // Imprimir 'x' en los espacion del input
    gotoxy(50, 3);
    cout << "xxxxx";
    gotoxy(37, 5);
    cout << "xxxxx";

    // Solicitar al usuario ingresar el número de cuenta
    gotoxy(50, 3);
    cin >> user.NumeroDeCuenta;
    numeroCuenta = user.NumeroDeCuenta;

    // Solicitar al usuario ingresar el NIP
    gotoxy(37, 5);
    cin >> user.NIP;
    nip = user.NIP;

    // Llamar a la función buscarUsuario para verificar la existencia del usuario en la base de datos
    buscarUsuario(numeroCuenta, nip);
}

bool buscarUsuario(int numeroDeCuenta, int nip)
{
    ATM db;                /** Leer la base de datos ubicada en el directorio raiz */
    USUARIO usuarioActual; /** Variable para almacenar el usuario actual */
    TEXT_STATE colorState; /** estructura definida en ui.h encargada de modificar el color del texto */

    /** Abrir la base de datos principal para lectura */
    ifstream archivo(db.BaseDatosPrincipal);
    if (!archivo.is_open())
    {
        mostrarError("Error al abrir la base de datos");
        return false;
    }

    while (archivo >> usuarioActual.NumeroDeCuenta)
    {
        // Leer el NIP y el balance del usuario
        archivo >> usuarioActual.NIP;
        archivo >> usuarioActual.Balance;

        // Comparar con el usuario buscado
        if (usuarioActual.NumeroDeCuenta == numeroDeCuenta)
        {
            mostrarUsuarioEncontrado();
            remplazarInputAnterior(50, 3, numeroLen(numeroDeCuenta)); // Ajusta la posición y longitud según sea necesario

            // Verificar la contraseña
            if (usuarioActual.NIP == nip)
            {
                mostrarNipCorrecto();
                archivo.close();
                Sleep(1000);
                logicaMenuPrincipal(usuarioActual.NumeroDeCuenta, usuarioActual.Balance);
                return true; // Usuario encontrado y NIP correcto
            }
            else
            {
                MostrarNipIncorrecto();

                // Imprimir caracteres en blaco para evitar sobrepocicion de cracteres
                imprimirEspacios(50, 5);

                // Cerrar y abrir el archivo después de una llamada recursiva
                archivo.close();
                archivo.open(db.BaseDatosPrincipal);
                if (!archivo.is_open())
                {
                    mostrarError("Error al abrir la base de datos");
                    return false;
                }

                remplazarInputAnterior(37, 5, numeroLen(nip)); // Ajusta la posición y longitud según sea necesario
                archivo.close();
                logicaMenuBienvenida(); // Llamado recursivo a logica para volver a ingresar credenciales
                return false;           // Usuario encontrado, pero NIP incorrecto
            }
        }
    }

    // Si llegamos aquí, el usuario no fue encontrado en el archivo
    mostrarUsuarioNoEncontrado();
    imprimirEspacios(37, 5);
    remplazarInputAnterior(37, 5, numeroLen(numeroDeCuenta));
    archivo.close();

    // Cerrar y abrir el archivo después de una llamada recursiva
    archivo.open(db.BaseDatosPrincipal);
    if (!archivo.is_open())
    {
        mostrarError("Error al abrir la base de datos principal");
        return false;
    }
    remplazarInputAnterior(50, 3, numeroLen(numeroDeCuenta)); // Ajusta la posición y longitud según sea necesario
    archivo.close();

    logicaMenuBienvenida();
    return false;
}

void logicaMenuPrincipal(int numeroCuenta, double saldo)
{
    // Cargar menu principal.
    renderCapa2();
    pantallaMenus();
    mostrarTextoMenuPrincipal();

    // Leer opcion del usuario
    int opcion;
    gotoxy(46, 8);
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        // Primera opcion ver el saldo, llama a la funcion indicada.
        verSaldo(numeroCuenta, saldo);
        break;
    case 2:
    {
        OPCIONES_RETIRO opcionesRetiro; // Variable para ver las opciones de retiro posibles
        int montoSeleccionado;          // Opcion seleccionada por el usuario
        // Cargar menu de opciones de retiro
        renderCapa2();
        pantallaMenus();
        menuOpcionesDeRetiro();
        gotoxy(71, 8);
        cin >> montoSeleccionado;
        int montoRetiro = montoDeRetiro(opcionesRetiro, montoSeleccionado); // Asignarle el valor de montoDeRetiro a una variable
        actualizarSaldo(numeroCuenta, saldo, montoRetiro);                  // LLmar la funcion para actualizar el saldo en la base de datos

        break;
    }
    case 3:
        // Opcion tres para relaizar un deposito, llama a la funcion necesario
        realizarDeposito(numeroCuenta, saldo);
        break;
    case 4:
        // Cargar UI necesarios
        pantallaMenus();
        animacionSalida();
        renderCapa2();
        pantallaMenus();
        mostrarTextoMenuBienvenida();
        logicaMenuBienvenida(); // Volvemos al menu principal
        break;
    default:
        break;
    }
}

void verSaldo(int numeroCuenta, double saldo)
{
    ATM db;                /** variable para almacenar la base de datos necesaria */
    USUARIO usuarioActual; /** Variable para almacenar el usuario actual. */
    TEXT_STATE colorState; /** Variable para almacenar el estado (color) del texto. */

    ifstream archivo(db.BaseDatosPrincipal);
    if (!archivo.is_open())
    {
        mostrarError("Error al abrir la base de datos");
        return;
    }

    /*
        Este codigo hace uso de la logica binaria de c++ donde para entrar a un bucle como un while
        solo es necesaria una condicion booleana (true, false) almacenar el estado del usuario como un
        calor booleano facilita la entrada o salida a bucles o condicionales.
    */

    bool usuarioEncontrado = false; /** Uusario encontrado, inicia siendo false*/

    /** Leer abase de datos */
    while (archivo >> usuarioActual.NumeroDeCuenta >> usuarioActual.NIP >> usuarioActual.Balance)
    {
        if (usuarioActual.NumeroDeCuenta == numeroCuenta)
        {
            usuarioEncontrado = true; // si el usuario es encontrado cambiamos su estado a true para poner entrar a bucles y condicionales futuros
            break;                    // No necesitamos seguir leyendo después de encontrar al usuario
        }
    }

    archivo.close();

    if (usuarioEncontrado) // true
    {
        // mostramos la informacion del saldo y volvemos al menu principal
        mostrarInformacionSaldo(numeroCuenta, usuarioActual.Balance);
        logicaMenuPrincipal(numeroCuenta, usuarioActual.Balance);
    }
    else
    {
        mostrarError("Usuario no encontrado en la base de datos.");

        // Puedes manejar este caso de otra manera si lo deseas.
    }
}

int montoDeRetiro(const OPCIONES_RETIRO &opciones, int seleccionUsuario)
{
    USUARIO user;
    switch (seleccionUsuario)
    {
    case 1:
        return opciones.Opcion1;
    case 2:
        return opciones.Opcion2;
    case 3:
        return opciones.Opcion3;
    case 4:
        return opciones.Opcion4;
    case 5:
        return opciones.Opcion5;
    case 6:
        logicaMenuPrincipal(user.NumeroDeCuenta, user.Balance);
    default:
        return 0;
    }
}

void actualizarSaldo(int numeroCuenta, double saldo, int montoRetiro)
{
    ATM db;                         /** variable para almacenar la ruta de la db */
    ATM atmSaldoInicial;            /** Saldo inicial del ATM */
    USUARIO usuarioActual;          /** Usuario actual */
    TEXT_STATE colorState;          /** estructura definida en ui.h encargada de modificar el color del texto */
    OPCIONES_RETIRO opcionesRetiro; /** Opciones de retiro */

    // Abrir el archivo original para lectura
    ifstream archivoOrg(db.BaseDatosPrincipal);
    if (!archivoOrg.is_open())
    {
        mostrarError("Error al abrir la base de datos para lectura");
        return;
    }
    // Crear un archivo temporal para escritura
    ofstream archivoTemp(db.BaseDatosTemporal);
    if (!archivoTemp.is_open())
    {
        mostrarError("Error al abrir la base de datos para escritura");
        return;
    }

    bool usuarioEncontrado = false; // De nuevo usamos la logica binaria de c++

    while (archivoOrg >> usuarioActual.NumeroDeCuenta >> usuarioActual.NIP >> usuarioActual.Balance)
    {
        if (usuarioActual.NumeroDeCuenta == numeroCuenta)
        {
            // Verificamos que el valor del retiro no sea mayor del saldo rrelacionado a la cuenta
            if (montoRetiro > usuarioActual.Balance)
            {
                // Cerramos los archivos, mostramos el mensaje adecuado y volvemos al menu principal
                archivoOrg.close();
                archivoTemp.close();
                manejarSaldoInsuficiente("Saldo insuficiente, por favor ingrese una cantidad menor", numeroCuenta, saldo);
                logicaMenuPrincipal(numeroCuenta, saldo);
                return;
            }
            else
            {
                // Se asume que el usuario fue encontrado, en ese caso le restamos el monto al saldo del usuario
                usuarioActual.Balance -= montoRetiro;
                usuarioEncontrado = true;
            }
        }
        // Copiamos db principal a la db temporal
        archivoTemp << usuarioActual.NumeroDeCuenta << ' ' << usuarioActual.NIP << ' ' << usuarioActual.Balance << '\n';
    }

    archivoOrg.close();
    archivoTemp.close();

    // Reemplazamos archivo original con el temp (archivo con saldo actualizado)
    if (usuarioEncontrado)
    {
        if (remove(db.BaseDatosPrincipal) != 0)
        {
            mostrarError("Error al eliminar el archivo original.");
            return;
        }
        if (rename(db.BaseDatosTemporal, db.BaseDatosPrincipal) != 0)
        {
            mostrarError("Error al renombrar el archivo temporal.");
            return;
        }

        // Mostramos mensaje adecuado para la transaccion exitosa
        archivoOrg.close();
        archivoTemp.close();
        renderCapa2();
        pantallaMenus();
        gotoxy(70, 3);
        Color(colorState.susces);
        registroDeRegistros(numeroCuenta, montoRetiro, "retiro");
        gotoxy(45, 5);
        cout << "Saldo retirado exitosamente.";
        gotoxy(50, 6);
        cout << "Se han retirado $" << montoRetiro;
        Sleep(2000); // Esperamos dos segundos
        logicaMenuPrincipal(numeroCuenta, saldo);
        Color(colorState.normal);
    }
    else
    {

        // Eliminar el archivo temporal si el usuario no fue encontrado
        remove(db.BaseDatosTemporal);
        archivoOrg.close();
        archivoTemp.close();
    }
}

void registroDeRegistros(int numeroCuenta, double montoRetiro, string tipoTransaciion)
{
    INFO_RETIRO transaccion; /** Almacenas la info de la transaccion */
    ATM db;                  /** Base de datos */

    // Asignamos los datos que ya tenemos del usuario a las estructuras necesarias
    transaccion.NumeroDeDocumentoRetiro = numeroCuenta;
    transaccion.MontoRetiro = montoRetiro;
    transaccion.tipoDeRetiro = tipoTransaciion;

    time_t tiempoActual = time(nullptr);                // Medir el tiempo de ejecutada la presente funcion
    transaccion.FechaHoraRetiro = ctime(&tiempoActual); // Se lo asignamos a la estrucutura adecuada

    // Abrimos la db para escritura en moto append
    ofstream archivoRegistro(db.BaseDatosTransacciones, std::ios::app);
    if (!archivoRegistro.is_open())
    {
        mostrarError("Error al abrir el archivo de registro de transacciones.");
    }

    // Le mandamos al archivo los respectivos datos referentes a las transaccion que se realizo
    archivoRegistro << "FECHA " << transaccion.FechaHoraRetiro
                    << "TIPO " << transaccion.tipoDeRetiro << endl
                    << "MONTO " << transaccion.MontoRetiro << endl
                    << "CUENTA " << transaccion.NumeroDeDocumentoRetiro << endl
                    << endl;
    ;

    // Cerrar el archivo
    archivoRegistro.close();
}

void realizarDeposito(int numeroCuenta, double saldo)
{
    ATM db;
    TEXTO text;           /** Variable para elegir el texto a imprimir*/
    TEXT_STATE textState; /** Estado del texto */

    // Abrimos las bases de datos para lectura y escritura
    ifstream archivoOrg(db.BaseDatosPrincipal);
    if (!archivoOrg.is_open())
    {
        mostrarError("Error al abrir la base de datos");
        return;
    }

    ofstream archivoTemp(db.BaseDatosTemporal);
    if (!archivoTemp)
    {
        mostrarError("Error al abrir la base de datos temporal");
        return;
    }

    // Mostramos el texto respectivo para este menu
    tituloMenuDepositos();

    // leemos el valor del deposito del usuario en centavos
    int montoDepositoCentavos;
    cin >> montoDepositoCentavos;

    // Cubrimos la posibilidad de cancelar la transaccion
    if (montoDepositoCentavos == 0)
    {
        mostrarDepositoTransaccionCancelada(); // Actual
        Sleep(2000);
        archivoOrg.close();
        archivoTemp.close();
        logicaMenuPrincipal(numeroCuenta, saldo);
    }

    // Ya se especificó un monto de depósito

    /**
        se está utilizando static_cast para realizar una conversión explícita del tipo de datos.

        La razón para usar static_cast<double> es garantizar que la división se realice como una operación de punto flotante
    */
    double montoDepositoDolares = static_cast<double>(montoDepositoCentavos) / 100;
    int tiempoDeposito = 1; /** variable para iniciar el contador del deposito */
    bool usuarioEncontrado = false;
    bool sobreRecibido = false; /** Estado de la interaccion con la ranura de depositos del ATM */
    USUARIO usuarioActual;
    ATM atmSaldoInicial;
    time_t tiempoInicio = time(nullptr); // Obtenemos el tiempo actual del sistema y lo almacenamos aqui

    mostrarDepositoDepRanura();
    Color(textState.warning);
    gotoxy(35, 6);
    cout << text.MenuDepositoConfirmar;
    gotoxy(25, 7);

    // Variables para el contador de el tiempo de deposito
    int tiempoRestante;
    int tiempoLimite = 22; // Se usa 22 para que el contador llegue hasta 20

    do
    {
        // Esperar 1 segundo
        Sleep(1000);
        tiempoDeposito++; // Cada paso en el bucle le sumamos 1 al tiempo

        // Calcular tiempo restante
        tiempoRestante = tiempoLimite - tiempoDeposito; // Tiempo restnte para finalizzr el deposito

        // Mostrar el contador de tiempo restante
        gotoxy(25, 7);
        cout << "Tiempo restante: " << tiempoRestante << " segundos para introducir el deposito en la ranura" << endl;

        // Verificar si el usuario ha presionado una tecla
        if (_kbhit())
        {
            char tecla = _getch(); // Utiliza _getch para leer una tecla sin esperar a 'Enter'

            if (tecla == '1')
            {
                mostrarDepositoExitoso();
                Sleep(2000);
                sobreRecibido = true; // El sobre a sido depositado
            }
            else if (tecla == '0')
            {
                mostrarDepositoCancelado();
                Sleep(2000);
                // Cerrar archivos y realizar otras tareas necesarias
                archivoOrg.close();
                archivoTemp.close();
                logicaMenuPrincipal(numeroCuenta, saldo);
            }
        }

        // Si el tiempo de depósito excede los 20 segundos, cancelar la transacción
        if (tiempoDeposito >= 20)
        {
            mostrarErrorTiempoDeposito();
            gotoxy(35, 8);
            system("pause");
            archivoOrg.close();
            archivoTemp.close();
            logicaMenuPrincipal(numeroCuenta, saldo);
            return;
        }
    } while (!sobreRecibido);

    // Hacemos la logica para hacer el respectivo cambio en las bases de datos
    while (archivoOrg >> usuarioActual.NumeroDeCuenta >> usuarioActual.NIP >> usuarioActual.Balance)
    {
        if (usuarioActual.NumeroDeCuenta == numeroCuenta)
        {
            // Lógica específica de depósito
            usuarioActual.Balance += montoDepositoDolares;
            usuarioEncontrado = true;
        }

        archivoTemp << usuarioActual.NumeroDeCuenta << ' ' << usuarioActual.NIP << ' ' << usuarioActual.Balance << '\n';
    }

    archivoOrg.close();
    archivoTemp.close();

    // Reemplazar archivo original con el temp (archivo con saldo actualizado)
    if (usuarioEncontrado)
    {
        if (remove(db.BaseDatosPrincipal) != 0)
        {
            mostrarError("Error al eliminar el archivo original.");
            return;
        }
        if (rename(db.BaseDatosTemporal, db.BaseDatosPrincipal) != 0)
        {
            mostrarError("Error al renombrar el archivo temporal.");
            return;
        }

        // Lógica de deposito exitoso
        archivoOrg.close();
        archivoTemp.close();
        registroDeRegistros(numeroCuenta, montoDepositoCentavos, "deposito");
        logicaMenuPrincipal(numeroCuenta, saldo);
    }
    else
    {
        // Eliminar el archivo temporal si el usuario no fue encontrado
        remove(db.BaseDatosTemporal);
    }
}
