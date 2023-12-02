#include <stdio.h>
#include <string.h>

// Creacion de un registro
struct Estudiante
{
    char Codigo[6];
    char Nombre[10];
    float Nota1, Nota2, Nota3;
};

void AdicionarEstudiante(Estudiante estudiante[], int NumeroEstudiantes);
void BuscarEstudiante(Estudiante estudiante[], int n);
void ListaEstudiantes(Estudiante estudiante[], int n);

int main()
{
    int NumeroEstudiantes;
    printf("Ingresa la cantidad de estudiantes: ");
    scanf("%d", &NumeroEstudiantes);
    Estudiante estudiante[NumeroEstudiantes];
    AdicionarEstudiante(estudiante, NumeroEstudiantes);
    // BuscarEstudiante(estudiante, NumeroEstudiantes);
    ListaEstudiantes(estudiante, NumeroEstudiantes);
    return 0;
}

void AdicionarEstudiante(Estudiante estudiante[], int NumeroEstudiantes)
{
    float Promedio;
    for (int i = 0; i < NumeroEstudiantes; i++)
    {
        printf("\nEstudiante %d\n", i + 1);
        printf("  Codigo: ");
        scanf("%s", estudiante[i].Codigo);

        printf("  Nombre: ");
        scanf("%s", estudiante[i].Nombre);

        printf("  Nota 1: ");
        scanf("%f", &estudiante[i].Nota1);

        printf("  Nota 2: ");
        scanf("%f", &estudiante[i].Nota2);

        printf("  Nota 3: ");
        scanf("%f", &estudiante[i].Nota3);

        Promedio = ((estudiante[i].Nota1 + estudiante[i].Nota2 + estudiante[i].Nota3) / 3);
        printf("\nPromedio del estudiante: %.2f\n------------\n", Promedio);
    }
}

void BuscarEstudiante(Estudiante estudiante[], int n)
{
    float Promedio;
    char codigo[6];

    printf("\nBuscar estudiante\n");
    scanf("%s", codigo);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(estudiante[i].Codigo, codigo) == 0)
        {
            printf("Datos del estudiante: \n");
            printf(" - Codigo: %s \n", estudiante[i].Codigo);
            printf(" - Nombre: %s \n", estudiante[i].Nombre);
            printf(" - Nota 1: %.2f \n", estudiante[i].Nota1);
            printf(" - Nota 2: %.2f \n", estudiante[i].Nota2);
            printf(" - Nota 3: %.2f \n", estudiante[i].Nota3);
            Promedio = ((estudiante[i].Nota1 + estudiante[i].Nota2 + estudiante[i].Nota3) / 3);
            printf(" - Promedio: %.2f \n", Promedio);
            break;
        }

        printf("EL estudiante no fue encontrado");
    }
}

void ListaEstudiantes(Estudiante estudiante[], int n)
{
    float Promedio;
    printf("\nCodigo\tNombre\tNota 1\tNota2\tNota 3\tPromedio\n");
    for (int i = 0; i < n; i++)
    {
        Promedio = ((estudiante[i].Nota1 + estudiante[i].Nota2 + estudiante[i].Nota3) / 3);
        printf("%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n  ", estudiante[i].Codigo, estudiante[i].Nombre, estudiante[i].Nota1, estudiante[i].Nota2, estudiante[i].Nota3, Promedio);
    }
}