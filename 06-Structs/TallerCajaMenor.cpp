#include <iostream>
#include "dataprst.h"

using namespace std;

/**
 * @brief Estructura que representa un Recibo de Caja.
 *
 * Esta estructura almacena información asociada a un recibo de caja,
 * incluyendo el número de documento, la ciudad, la fecha, el beneficiario,
 * el valor y el concepto asociado al recibo.
 */
struct ReciboCaja
{
    int numeroDocumento; /**< Número de documento asociado al recibo. */
    char ciudad[50];     /**< Ciudad asociada al recibo. */
    char fecha[11];      /**< Fecha en la que se emitió el recibo (formato dd/mm/yyyy). */
    char pagadoA[50];    /**< Nombre del beneficiario o entidad a la que se pagó. */
    float valor;         /**< Valor monetario asociado al recibo. */
    char concepto[200];  /**< Concepto o descripción del motivo del pago. */
};

const int MAX_DOCUMENTOS = 50; // Numero maximo de documentos
ReciboCaja documentos[MAX_DOCUMENTOS];
int numDocumentos = 0; // Numero actual de documentos

/**
 * @brief Función para adicionar un nuevo documento a la estructura de recibos de caja.
 *
 * Esta función solicita al usuario ingresar los datos de un nuevo recibo de caja
 * y los almacena en la estructura de documentos si hay espacio disponible.
 * Si se alcanza el límite máximo de documentos, muestra un mensaje indicando que
 * no se pueden adicionar más documentos.
 */
void AdicionarDocumento()
{
    system("cls");

    if (numDocumentos < MAX_DOCUMENTOS)
    {
        // Pedir al usuario ingresar los datos del recibo de caja
        gotoxy(4, 2);
        cout << "Ingrese el numero del documento: ";
        cin >> documentos[numDocumentos].numeroDocumento;

        gotoxy(4, 3);
        cout << "Ingrese la ciudad: ";
        cin >> documentos[numDocumentos].ciudad;

        gotoxy(4, 4);
        cout << "Ingrese la fecha: ";
        cin >> documentos[numDocumentos].fecha;

        gotoxy(4, 5);
        cout << "Pagado a: ";
        cin >> documentos[numDocumentos].pagadoA;

        gotoxy(4, 6);
        cout << "Ingrese el valor: ";
        cin >> documentos[numDocumentos].valor;

        gotoxy(4, 7);
        cout << "Ingrese el concepto: ";
        cin >> documentos[numDocumentos].concepto;

        numDocumentos++;

        gotoxy(6, 9);
        cout << "Documento adicionado correctamente.\n";
        gotoxy(1, 11);
        system("pause");
    }
    else
    {
        gotoxy(6, 9);
        cout << "No se pueden adicionar más documentos. Límite alcanzado.\n";
    }
}

/**
 * @brief Función para consultar un documento de la estructura de recibos de caja por su número.
 *
 * Esta función solicita al usuario ingresar el número de documento que desea consultar.
 * Luego, busca el documento en la estructura y muestra su información si es encontrado.
 * Si el documento no se encuentra, muestra un mensaje indicando que no se ha encontrado.
 */
void ConsultarDocumento()
{
    int numeroBuscado;

    cout << "Ingrese el número del documento a consultar: ";
    cin >> numeroBuscado;

    system("cls");

    // Buscar el documento por el número
    for (int i = 0; i < numDocumentos; i++)
    {
        if (documentos[i].numeroDocumento == numeroBuscado)
        {
            // Muestra la información del documento encontrado
            gotoxy(5, 4);
            cout << "Ciudad: " << documentos[i].ciudad;
            gotoxy(35, 4);
            cout << "Fecha: " << documentos[i].fecha;
            gotoxy(55, 4);
            cout << "No." << documentos[i].numeroDocumento;

            gotoxy(5, 6);
            cout << "Pagado a:" << documentos[i].pagadoA;
            gotoxy(35, 6);
            cout << "Valor: $" << documentos[i].valor;
            gotoxy(5, 8);
            cout << "Concepto: " << documentos[i].concepto;
            // Muestra otros campos según la estructura

            gotoxy(1, 11);
            system("pause");
            return;
        }
    }

    cout << "Documento no encontrado.\n";
}

/**
 * @brief Función para mostrar un listado horizontal de los documentos almacenados.
 *
 * Esta función muestra un listado de los documentos almacenados de forma horizontal.
 * Incluye información como el número del documento, la ciudad, la fecha y el valor.
 * Además, calcula y muestra el valor total de todos los documentos.
 * Si no hay documentos almacenados, muestra un mensaje indicando que no hay documentos.
 */
void MostrarListado()
{
    system("cls");
    int total = 0;

    if (numDocumentos > 0)
    {
        // Mostrar listado de documentos de forma horizontal
        gotoxy(5, 4);
        cout << "Listado de Documento: ";
        // Agrega aquí encabezados para otros campos
        cout << "\n";

        for (int i = 0; i < numDocumentos; ++i)
        {
            gotoxy(5, i + 6);
            cout << documentos[i].numeroDocumento << "\t" << documentos[i].ciudad << "\t" << documentos[i].fecha << "\t" << documentos[i].valor;
            // Agrega aquí otros campos según la estructura
            cout << "\n";
            gotoxy(5, i + 7);
            total = total + documentos[i].valor;
        }

        // Mostrar el valor total de los documentos
        cout << "Valor total de los documentos: " << total;
    }
    else
    {
        cout << "No hay documentos para mostrar.\n";
    }

    system("pause");
}

/**
 * @brief Función para modificar los datos de un documento de la estructura de recibos de caja.
 *
 * Esta función solicita al usuario ingresar el número del documento que desea modificar.
 * Luego, busca el documento en la estructura y permite al usuario ingresar nuevos datos.
 * Si el documento no se encuentra, muestra un mensaje indicando que no se ha encontrado.
 */
void ModificarDocumento()
{
    int numeroBuscado;

    cout << "Ingrese el numero del documento a modificar: ";
    cin >> numeroBuscado;
    system("cls");

    // Buscar el documento por el número
    for (int i = 0; i < numDocumentos; ++i)
    {
        if (documentos[i].numeroDocumento == numeroBuscado)
        {
            // Modificar los datos del recibo de caja
            cout << "Ingrese los nuevos datos del recibo de caja:\n";
            cout << "Nuevo numero del documento: ";
            cin >> documentos[i].numeroDocumento;
            // Agrega aquí la modificación de otros campos según la estructura
            cout << "Documento modificado correctamente.\n";
            system("pause");
            return;
        }
    }

    cout << "Documento no encontrado.\n";
}

/**
 * @brief Función principal que muestra un menú y realiza acciones según la opción seleccionada por el usuario.
 *
 * Este menú proporciona opciones para realizar diversas acciones relacionadas con documentos.
 * El usuario puede seleccionar opciones como adicionar documento, consultar documento, mostrar listado,
 * modificar documento o salir del programa.
 * La función utiliza otras funciones definidas previamente para ejecutar las acciones correspondientes a cada opción.
 */
void menu()
{
    int opcion;

    do
    {
        // Mostrar menú
        system("cls");
        gotoxy(15, 2);
        cout << "Menu Principal . . .\n";
        gotoxy(6, 4);
        cout << "- 1. Adicionar Documento\n";
        gotoxy(6, 5);
        cout << "- 2. Consultar Documento\n";
        gotoxy(6, 6);
        cout << "- 3. Mostrar Listado\n";
        gotoxy(6, 7);
        cout << "- 4. Modificar Documento\n";
        gotoxy(6, 8);
        cout << "- 5. Salir\n";
        gotoxy(8, 10);
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        // Realizar acciones según la opción seleccionada
        switch (opcion)
        {
        case 1:
            AdicionarDocumento();
            break;
        case 2:
            ConsultarDocumento();
            break;
        case 3:
            MostrarListado();
            break;
        case 4:
            ModificarDocumento();
            break;
        case 5:
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opción no válida. Intente de nuevo.\n";
        }

    } while (opcion != 5);
}
int main()
{
    menu();
    return 0;
}