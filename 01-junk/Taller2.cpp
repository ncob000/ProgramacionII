#include <stdio.h>

void menu();
int SumDigitos(int num);
void SignoZodiacal(int dia, int mes);
void Bisiesto(int year);
void MenorNumeros(int numero1, int numero2, int numero3);
void OrdenDes(int numero1, int numero2, int numero3);
void NumeroMedio(int numero1, int numero2, int numero3);
void AtletaMaraton(int sexo, int edad, int tiempo);
void Comision();
void Salario();
void PrecioLibro();

int main(){
	menu();
	return 0;
}

void menu(){
	int opcion = 0;

	printf("1. Suma de dos digitos\n");
    printf("2. Determinar signo Zodiacal\n");
    printf("3. Determinar si un anio es bisiesto\n");
    printf("4. Determinar el menor de 3 numeros\n");
    printf("5. Imprimir numeros de manera decendente\n");
    printf("6. Imprimir el numero del medio\n");
    printf("7. Seleccionar un atleta para una maraton\n");   
    printf("8. Calcular la comision de un vendedor\n");
    printf("9. Calcular el salario neto de un empleado\n");
    printf("10. Calcular el precio de un libro\n");
    printf("11. Salir\n");
    printf("\nIngrese una opcion: ");
    scanf("%d", &opcion);

	if (opcion == 1){

		int num;
        printf("Ingrese un numero: ");
        scanf("%d", &num);
        printf("El resultado es: %d", SumDigitos(num) );
		menu();

	} else if (opcion == 2){

		int dia = 0, mes = 0;
		printf("Ingrese el dia de nacimiento: ");
        scanf("%d", &dia);
        printf("Ingrese el mes de nacimiento: ");
        scanf("%d", &mes);
        SignoZodiacal(dia, mes);
		menu();

	} else if (opcion == 3){

		int year;
        printf("Ingrese el año: ");
        scanf("%d", &year);
        Bisiesto(year);
		menu();

	} else if (opcion == 4){

        int numero1, numero2, numero3;
        printf("Ingrese el primer numero: ");
        scanf("%d", &numero1);
        printf("Ingrese el segundo numero: ");
        scanf("%d", &numero2);
        printf("Ingrese el tercer numero: ");
        scanf("%d", &numero3);
        MenorNumeros(numero1, numero2, numero3);
		menu();

	} else if (opcion == 5){
	
        int numero1, numero2, numero3;
		printf("Ingrese el primer numero: ");
        scanf("%d", &numero1);
        printf("Ingrese el segundo numero: ");
        scanf("%d", &numero2);
        printf("Ingrese el tercer numero: ");
        scanf("%d", &numero3);
        OrdenDes(numero1, numero2, numero3);
		menu();

	} else if (opcion == 6){
		
		int numero1, numero2, numero3;
		printf("Ingrese el primer numero: ");
        scanf("%d", &numero1);
        printf("Ingrese el segundo numero: ");
        scanf("%d", &numero2);
        printf("Ingrese el tercer numero: ");
        scanf("%d", &numero3);
        NumeroMedio(numero1, numero2, numero3);
		menu();

	} else if (opcion == 7){
		
		int sexo, edad, tiempo;
        printf("Ingrese el sexo (1 = hombre, 2 = mujer): ");
        scanf("%d", &sexo);
        printf("Ingrese la edad: ");
        scanf("%d", &edad);
        printf("Ingrese el tiempo: ");
        scanf("%d", &tiempo);
        AtletaMaraton(sexo, edad, tiempo);
		menu();

	} else if (opcion == 8){
		Comision();
		menu();

	} else if (opcion == 9){

		Salario();
		menu();

	} else if (opcion == 10){
		PrecioLibro();
		menu();
	} else if (opcion == 11){
		
	} else {
		printf("\nOpcion no valida...\n");
		menu();
	}
}

int SumDigitos(int num)
{
    int resultado;
    int digito1 = num / 10;
    int digito2 = num % 10;
    
	if (digito2 == 1){
        resultado = digito1 + digito2;
    } else if (digito2 == 2){
        resultado = digito1 * digito2;
    } else if (digito2 == 3){
        resultado = digito1 - digito2;
    } else if (digito2 == 4) {
        resultado = digito2 - digito1;
    }
	else {
        resultado = digito1 + digito2;
    }
    return resultado;
}

void SignoZodiacal(int dia, int mes){
    if ((mes == 3 && dia >= 21) || (mes == 4 && dia <= 19))
        printf("Aries\n");
    else if ((mes == 4 && dia >= 20) || (mes == 5 && dia <= 20))
        printf("Tauro\n");
    else if  ((mes == 5 && dia >= 21) || (mes == 6 && dia <= 20))
        printf("Geminis\n");
    else if  ((mes == 6 && dia >= 21) || (mes == 7 && dia <= 22))
        printf("Cancer\n");
    else if  ((mes == 7 && dia >= 23) || (mes == 8 && dia <= 22))
        printf("Leo\n");
    else if  ((mes == 8 && dia >= 23) || (mes == 9 && dia <= 22))
        printf("Virgo\n");
    else if  ((mes == 9 && dia >= 23) || (mes == 10 && dia <= 22))
        printf("Libra\n");
    else if  ((mes == 10 && dia >= 23) || (mes == 11 && dia <= 21))
        printf("Escorpio\n");
    else if  ((mes == 11 && dia >= 22) || (mes == 12 && dia <= 21))
        printf("Sagitario\n");
    else if  ((mes == 12 && dia >= 22) || (mes == 1 && dia <= 19))
        printf("Capricornio\n");
    else if  ((mes == 1 && dia >= 20) || (mes == 2 && dia <= 18))
        printf("Acuario\n");
    else if  ((mes == 2 && dia >= 19) || (mes == 3 && dia <= 20))
        printf("Piscis\n");
    else
        printf("Error en la fecha\n");
}

void Bisiesto(int year)
{
    if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0 && year > 1000)
        printf("Es bisiesto\n");
    else
        printf("No es bisiesto\n");
}

void MenorNumeros(int numero1, int numero2, int numero3)
{
    if (numero1 < numero2 && numero1 < numero3)
        printf("El numero %d es el menor\n", numero1);
    else if (numero2 < numero1 && numero2 < numero3)
        printf("El numero %d es el menor\n", numero2);
    else if (numero3 < numero1 && numero3 < numero2)
        printf("El numero %d es el menor\n", numero3);
    else
        printf("Los numeros son iguales\n");
}

void OrdenDes(int numero1, int numero2, int numero3){
    
	int mayor, intermedio, menor;
    
	if (numero1 >= numero2 && numero1 >= numero3){
        mayor = numero1;
        if (numero2 >= numero3){
            intermedio = numero2;
            menor = numero3;
        }
        else{
            intermedio = numero3;
            menor = numero2;
        }
    } else if (numero2 >= numero1 && numero2 >= numero3){
        mayor = numero2;
        if (numero1 >= numero3){
            intermedio = numero1;
            menor = numero3;
        }
        else{
            intermedio = numero3;
            menor = numero1;
        }
    } else {
        mayor = numero3;
        if (numero1 >= numero2){
            intermedio = numero1;
            menor = numero2;
        }
        else{
            intermedio = numero2;
            menor = numero1;
        }
    }
    printf("\nEl orden es: %d, %d, %d\n", mayor, intermedio, menor);
}

void NumeroMedio(int numero1, int numero2, int numero3){
    
	int mayor, medio, menor;
    if (numero1 >= numero2 && numero1 >= numero3){
        mayor = numero1;
        if (numero2 >= numero3){
            medio = numero2;
            menor = numero3;
        }
        else{
            medio = numero3;
            menor = numero2;
        }
    } else if (numero2 >= numero1 && numero2 >= numero3){
        mayor = numero2;
        if (numero1 >= numero3){
            medio = numero1;
            menor = numero3;
        }
        else{
            medio = numero3;
            menor = numero1;
        }
    }
    else{
        mayor = numero3;
        if (numero1 >= numero2){
            medio = numero1;
            menor = numero2;
        }
        else {
            medio = numero2;
            menor = numero1;
        }
    }
    printf("El numero de medio es %d\n", medio);
}

void AtletaMaraton(int sexo, int edad, int tiempo)
{
    if (sexo == 1 && edad < 40 && tiempo <= 150){
        printf("El atleta a sido seleccionado\n");
	} else if (sexo == 1 && edad >= 40 && tiempo <= 175){
        printf("EL atleta a sido seleccionado\n");
	} else if (sexo == 2 && tiempo <= 180){
        printf("El atleta a sido Seleccionado\n");
	} else{
        printf("El atleta No a sido seleccionado\n");
	}
}

void Comision()
{
    char nombre[50];
    int codigo;
    float ventas, comision;

	printf("Ingrese el nombre del vendedor: ");
    scanf("%s", nombre);
    
	printf("Ingrese el codigo del producto: ");
    scanf("%d", &codigo);
    
	printf("Ingrese el total de ventas: ");
    scanf("%f", &ventas);
    
	if (codigo == 1){
        comision = ventas * 0.05;
	} else if (codigo == 2){
        comision = ventas * 0.08;
	} else if (codigo == 3){
        comision = ventas * 0.03;
	} else{
        printf("Codigo invalido\n");
	}
    
	printf("El vendedor %s tiene una comision de %f\n", nombre, comision);
}

void Salario()
{
    int horas;
    float salario, salario_bruto, salario_neto, descuento, bonificacion;

    printf("Ingrese el numero de horas trabajadas: ");
    scanf("%d", &horas);

    printf("Ingrese el salario basico por hora: ");
    scanf("%f", &salario);
    
	salario_bruto = horas * salario;
    
	if (salario_bruto > 100000){
        descuento = salario_bruto * 0.02;
	} else if (salario_bruto >= 90000 && salario_bruto <= 100000){
        descuento = salario_bruto * 0.01;
	} else{
        bonificacion = salario_bruto * 0.04;
	}

	salario_neto = salario_bruto - descuento + bonificacion;
    
	printf("El salario neto es %f\n", salario_neto);
    printf("El descuento es %f\n", descuento);
    printf("La bonificacion es %f\n", bonificacion);
}

void PrecioLibro()
{
    char nombre[20];
    int hojas;
    float precio;

    printf("Ingrese el nombre del libro: ");
    scanf("%s", &nombre);
    
	printf("Ingrese el numero de hojas: ");
    scanf("%d", &hojas);
    
	if (hojas < 100){
        precio = 5000;
	} else if (hojas >= 100 && hojas < 200){
        precio = 5000 + (hojas * 7);
	} else if (hojas >= 200 && hojas < 300){
        precio = 5000 + (hojas * 8);
	} else if (hojas >= 300){
        precio = 5000 + (hojas * 9);
	}
    
	printf("El precio del libro %s es %f\n", nombre, precio);
}
