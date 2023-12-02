#include <iostream>
#include <fstream>

struct Usuario
{
    int NumeroDeCuenta;
    int NIP;
    // Otros campos si es necesario
};

bool buscarUsuario(int numeroDeCuenta, int nip)
{
    std::ifstream archivo("..\\database.txt");
    if (!archivo.is_open())
    {
        std::cerr << "Error al abrir la base de datos" << std::endl;
        return false;
    }

    Usuario usuarioActual; // Variable para almacenar el usuario actual

    while (archivo >> usuarioActual.NumeroDeCuenta)
    {
        // Leer el NIP y otros datos del usuario
        archivo >> usuarioActual.NIP;

        // Comparar con el usuario buscado
        if (usuarioActual.NumeroDeCuenta == numeroDeCuenta)
        {
            // Verificar la contraseña
            if (usuarioActual.NIP == nip)
            {
                std::cout << "Usuario encontrado. NIP correcto." << std::endl;
                return true; // Usuario encontrado y NIP correcto
            }
            else
            {
                std::cout << "Usuario encontrado. NIP incorrecto." << std::endl;
                return false; // Usuario encontrado, pero NIP incorrecto
            }
        }
    }

    // Si llegamos aquí, el usuario no fue encontrado en el archivo
    std::cout << "Usuario no encontrado." << std::endl;
    return false;
}

int main()
{
    Usuario user;
    int numeroCuenta;
    int nipUsuario;
    std::cin >> user.NumeroDeCuenta;
    numeroCuenta = user.NumeroDeCuenta;
    std::cin >> user.NIP;
    nipUsuario = user.NIP;
    buscarUsuario(numeroCuenta, nipUsuario);

    return 0;
}