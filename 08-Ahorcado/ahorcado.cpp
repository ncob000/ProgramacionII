#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

char listaPalabras[30][20] = {"elefante", "tigre", "león", "jirafa", "mono", "ballena", "delfín", "pingüino", "tortuga",
                              "cocodrilo", "tiburón", "águila", "halcón", "serpiente", "rinoceronte", "hipopótamo", "koala",
                              "panda", "pingüino", "murciélago", "zorro", "lobo", "cebra", "gato", "perro",
                              "caballo", "conejo", "loro", "pavo real", "tucán"};

int ObtenerIndiceAleatorio()
{
    srand(time(NULL));
    return rand() % 30;
}

void MostrarPalabra(char palabraOriginal[], char palabraAdivinanza[])
{
    int longitud = strlen(palabraOriginal);
    for (int i = 0; i < longitud; i++)
    {
        cout << palabraAdivinanza[i] << " ";
    }
    cout << endl;
}

int main()
{
    char palabraOriginal[20];
    char palabraAdivinanza[20];

    int seleccionada = ObtenerIndiceAleatorio();
    strcpy(palabraOriginal, listaPalabras[seleccionada]);
    int longitud = strlen(palabraOriginal);

    for (int i = 0; i < longitud; i++)
    {
        palabraAdivinanza[i] = '_';
    }

    int intentos = 6;
    int ganado = 0;

    cout << "Juego de adivinar palabras!" << endl;

    for (; intentos > 0 && ganado != 1; intentos--)
    {
        cout << "Te quedan " << intentos << " intentos restantes." << endl;
        MostrarPalabra(palabraOriginal, palabraAdivinanza);

        cout << "Ingresa una letra: ";
        char letra;
        cin >> letra;
        cin.ignore();

        int letraEncontrada = 0;
        for (int i = 0; i < longitud; i++)
        {
            if (palabraOriginal[i] == letra && palabraAdivinanza[i] == '_')
            {
                palabraAdivinanza[i] = letra;
                letraEncontrada = 1;
            }
        }

        if (letraEncontrada != 1)
        {
            cout << "Incorrecto! Pierdes un intento." << endl;
        }

        if (strcmp(palabraOriginal, palabraAdivinanza) == 0)
        {
            ganado = 1;
        }
    }

    if (ganado == 1)
    {
        cout << "Felicidades! Adivinaste la palabra: " << palabraOriginal << endl;
    }
    else
    {
        cout << "Has perdido. La palabra era: " << palabraOriginal << endl;
    }

    return 0;
}
