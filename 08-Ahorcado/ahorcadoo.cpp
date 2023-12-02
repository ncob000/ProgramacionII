#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

char palabrasNuevas[30][15] = {"elefante", "tigre", "león", "jirafa", "mono", "ballena", "delfín", "pingüino", "tortuga",
                               "cocodrilo", "tiburón", "águila", "halcón", "serpiente", "rinoceronte", "hipopótamo", "koala",
                               "panda", "pingüino", "murciélago", "zorro", "lobo", "cebra", "gato", "perro",
                               "caballo", "conejo", "loro", "pavo real", "tucán"};

int GenerarNumeroAleatorioNuevo()
{
    srand(time(NULL));
    return rand() % 30;
}

void MostrarPalabraNueva(char P1[], char P2[])
{
    int longitud = strlen(P1);
    for (int i = 0; i < longitud; i++)
    {
        cout << P2[i] << " ";
    }
    cout << endl;
}

int main()
{
    char PalabraOriginal[12];
    char PalabraAdivinanza[12];

    int seleccionada = GenerarNumeroAleatorioNuevo();
    strcpy(PalabraOriginal, palabrasNuevas[seleccionada]);
    int longitud = strlen(PalabraOriginal);

    for (int i = 0; i < longitud; i++)
    {
        PalabraAdivinanza[i] = '_';
    }

    int intentos = 6;
    int ganado = 0;

    cout << "Juego de adivinar palabras!" << endl;

    while (intentos > 0 && ganado != 1)
    {
        cout << "Te quedan " << intentos << " intentos restantes." << endl;
        MostrarPalabraNueva(PalabraOriginal, PalabraAdivinanza);

        cout << "Ingresa una letra: ";
        char letra;
        cin >> letra;
        cin.ignore();

        int letraEncontrada = 0;
        for (int i = 0; i < longitud; i++)
        {
            if (PalabraOriginal[i] == letra && PalabraAdivinanza[i] == '_')
            {
                PalabraAdivinanza[i] = letra;
                letraEncontrada = 1;
            }
        }

        if (letraEncontrada != 1)
        {
            intentos--;
            cout << "Incorrecto! Pierdes un intento." << endl;
        }

        if (strcmp(PalabraOriginal, PalabraAdivinanza) == 0)
        {
            ganado = 1;
        }
    }

    if (ganado == 1)
    {
        cout << "Felicidades! Adivinaste la palabra: " << PalabraOriginal << endl;
    }
    else
    {
        cout << "Has perdido. La palabra era: " << PalabraOriginal << endl;
    }

    return 0;
}