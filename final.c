#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENTER 13
#define BACKSPACE 8

int opcion;
int salir = 0;
int i;

int main() {

 	system("cls");
	system("color 0f");
	printf("Menu Principal: \n\n\n");
	printf("1.Entrar usuario\n\n");
	printf("2.Registrar nuevo usuario y clave\n\n");
	printf("0.Salir\n\n");

	while (salir == 0) {

		printf("Opcion: ");
		
		scanf("%i", &opcion);
		fflush(stdin);
		
		if (opcion == 1)
			Entrar();
		else if (opcion == 2)
			Registrar();
		else if (opcion == 0)
			exit(0);
		else
			printf("\nN%cmero fuera de rango. Intente de nuevo.\n", 163);
	}
	return 0;
}

struct login {
	char usuario[30];
	char clave[30];
} login;

Entrar() {

	char user[30];
	char clave[30];

	system("cls");
	system("color 4f");

	printf("ENTRADA DE USUARIO: \n\n\n");

	if (ExisteArchivoUsuario()) {

		EstableceDatosDeUsuario();

		printf("USUARIO: ");
		scanf("%s", &user);

		printf("\nCLAVE: ");
		
		//-----------------------------2doNOMOSTRARPASS------------------------------------------------	

		char caracter;
		char fin = 1;
		i = 0;
		while (fin) {

			caracter = (char) getch();

			if (caracter == ENTER && i >= 1) {
				fin = 0;
	
			} else if (caracter == BACKSPACE) {
				if (i <= 0)
					i = 0;
				else
					i--;
				clave[i] = NULL;

			} else if (caracter != 9 || caracter != 32 && caracter != 13) {
				clave[i] = caracter;
				i++;
			}
		}
	
		//-----------------------------------------------------------------------------

		if ((strcmp(login.usuario, user) == 0)&& (strcmp(login.clave, clave) == 0)) {
			Menu();
		} else{
		
			printf("\nUps!!, tenemos un problemita :'( \nEl usuario o la clave ingresadas son incorrectas porfavor vuelva a intentar...\n\n");
			PausaInicio();	
		}

	} else {

		printf("No se ha registrado ningun usuario.\n");
		PausaInicio();
	}
}

int ExisteArchivoUsuario() {

	FILE* archivo;

	archivo = fopen("UsuarioRegistro.txt", "r");
	
	if (archivo != NULL) {
		return 1;
	} else {
		return 0;
	}
}

EstableceDatosDeUsuario() {
	FILE *archivo;

	archivo = fopen("UsuarioRegistro.txt", "r");

	if (archivo == NULL) {
		printf("\n**Ha ocurrido un error al tratar de leer el archivo**\n");
		return 1;
	}

	fscanf(archivo, " %[^\n]", &login.usuario);
	fscanf(archivo, " %[^\n]", &login.clave);
 }

Registrar() {

	system("cls");
	system("color f1");

	FILE *archivo;
	archivo = fopen("UsuarioRegistro.txt", "w+");

	printf("USUARIO: ");
	scanf("%s", &login.usuario);

	printf("\nCLAVE: ");

	NoMostrarClave();
	fprintf(archivo, "%s\n%s", login.usuario, login.clave);
	printf("\nUsuario Registrado!\n");

	fclose(archivo);
	PausaInicio();
}

NoMostrarClave(){
	
	for(i=0;i<=30;i++)
	login.clave[i] = NULL;	

	char caracter;
	i = 0;
	char fin = 1;

	while (fin) {

		caracter = (char) getch();

		if (caracter == ENTER && i >= 1) {
			fin = 0;

		} else if (caracter == BACKSPACE) {
			if (i <= 0)
				i = 0;
			else
				i--;
			login.clave[i] = NULL;

		} else if (caracter != 9 || caracter != 32 && caracter != 13) {
			login.clave[i] = caracter;
			i++;
		}
	}
}

Menu() {

	system("cls");
	system("color fc");

	printf("Menu Programas: \n\n\n");

	printf("1.Registro de clientes para hotel\n\n");
	printf("2.Calculadora\n\n");
	printf("3.Calculadora dias\n\n");
	printf("0.Salir\n\n");

	while (salir == 0) {
	
		printf("Opcion: ");
		scanf("%i", &opcion);
		fflush(stdin);


		if (opcion == 1)
			MenuHotel();
		else if (opcion == 2)
			Calculadora();
		else if (opcion == 3)
			Meses();
		else if (opcion == 0){	
			printf("\nSYSTEMA FINALIZADO\n");
			exit(0);
		}
		else
			printf("\nN%cmero fuera de rango. Intente de nuevo.\n", 163);
		fflush(stdin);
	}
}

PausaInicio() {
	system("pause");
	main();
}

/*---------- HOTEL CODE----------*/

char HabitacionesOcupadas[20];

MenuHotel() {

	system("cls");
	system("color 1f");

	for(i=0;i<31;i++) printf("%c",205);
	printf("%c\n",187);
	printf("Registro de clientes para hotel%c\n",186);
	for(i=0;i<31;i++) printf("%c",205);
	printf("%c\n\n",188 );
	
	printf("1.Registrar cliente\n\n");
	printf("2.Ver clientes\n\n");
	printf("0.Volver al menu anterior\n");

	while (salir == 0) {

		printf("\nOpcion: ");
		scanf("%i", &opcion);
		fflush(stdin);

		if (opcion == 1)
			RegistrarCliente();
		else if (opcion == 2)
			VerClientes();
		else if (opcion == 0)
			Menu();
		else
			printf("\nN%cmero fuera de rango. Intente de nuevo.\n", 163);
 	}
}

RegistrarCliente() {

	FILE* archivo;
	char* nombreArchivo = "Clientes.txt";
	char nombre[30];
	char apellido[30];
	char edad[2];
	char sexo[2];
	char id[11];
	char Nhabitacion[2];

	archivo = fopen(nombreArchivo, "a+");

	printf("\nIngrese el nombre: ");

	scanf("%s", &nombre);
	fflush(stdin);

	printf("\nIngrese el apellido: ");

	scanf("%s", &apellido);
	fflush(stdin);

	printf("\nIngrese la edad: ");

	scanf("%s", &edad);
	fflush(stdin);

	printf("\nIngrese el sexo (F/M): ");

	scanf("%s", &sexo);
	fflush(stdin);

	printf("\nIngrese el id/cedula: ");

	scanf("%s", &id);
	fflush(stdin);

	BuscarImprimirHabitacionesOcupadas();

	printf("\nSeleccione la habitacion: ");

	scanf(" %s", &Nhabitacion);
	fflush(stdin);

	FILE* archivoHabitaciones;
	archivoHabitaciones = fopen("Habitaciones ocupadas.txt", "a+");

	fprintf(archivo,
			"Cedula: %s\nNombre: %s\nApellido: %s\nEdad: %s\nSexo: %s\nHabitacion: %s\n---------------------------\n--------------------------\n",
			id, nombre, apellido, edad, sexo, Nhabitacion);
	fprintf(archivoHabitaciones, "%s\n", Nhabitacion);

	fclose(archivo);
	fclose(archivoHabitaciones);

	printf("\nRegistrado con Exito!: \n");
	system("pause");
	MenuHotel();
}

int BuscarImprimirHabitacionesOcupadas() {
	
	/** BUSCO EL ARCHIVO------------------*/
	char nHabitaciones;
	FILE* archivo;
	char* nombreArchivo = "Habitaciones ocupadas.txt";
	archivo = fopen(nombreArchivo, "r+");
	int endoffile = 0; //sirve para saber si llege al fin del archivo

	if (archivo == NULL) {
		
		/* CREO EL ARCHIVO------------------*/
		archivo = fopen(nombreArchivo, "w+");
		fclose(archivo);
		return 1;
	}
	printf("\nEstas son las habitaciones que no estan disponibles: \n");

	while (endoffile != EOF) {
		
		endoffile = fscanf(archivo, " %[^\n]",&HabitacionesOcupadas[nHabitaciones]);
		
		if(endoffile != EOF)		
		printf(" %s", &HabitacionesOcupadas[nHabitaciones]);
		
		fflush(stdout);
		nHabitaciones++;
	}

	fclose(archivo);
	return 1;
}

VerClientes() {
	FILE* archivo;
	char* nombrearchivo = "Clientes.txt";
	char datosCliente[80];
	int endoffile = 0;

	archivo = fopen(nombrearchivo, "r");
	if (archivo != NULL) {

		printf("\n\nLista de Clientes: \n\n");

		while (endoffile != EOF) {
			endoffile = fscanf(archivo, " %s", &datosCliente);
			printf(" %s", datosCliente);
			endoffile = fscanf(archivo, " %s", &datosCliente); // esto es para que imprima dos lines
			printf(" %s", datosCliente);
			printf(" \n");
		}

	} else {

		printf("\nNo hay clientes.\n");

	}
	fclose(archivo);
}

/*---------- CALCULATE CODE----------*/

Calculadora() {

	system("cls");
	system("color 4f");

	for(i=0;i<11;i++) printf("%c",205);
	printf("%c\n",187);
	printf("Calculadora%c\n",186);
	for(i=0;i<11;i++) printf("%c",205);
	printf("%c\n\n",188 );
	
	printf("1.Suma\n\n");
	printf("2.Resta\n\n");
	printf("3.Multiplicacion\n\n");
	printf("4.Divicion\n\n");
	printf("5.Potencia\n\n");
	printf("6.Raiz\n\n");
	printf("0.Volver al menu anterior\n\n");
	int num1, num2;

	while (salir == 0) {

		printf("\nOpcion: ");
		scanf("%i", &opcion);
		fflush(stdin);

		if (opcion > 0 && opcion < 6) {
			printf("\nDigite numero el primer: ");
			scanf("%i", &num1);
			printf("\nDigite el Segundo numero: ");
			scanf("%i", &num2);
			fflush(stdin);
		} else if (opcion == 6) {
			printf("\nDigite el numero: ");
			scanf("%i", &num1);
			fflush(stdin);
		}

		if (opcion == 1) {

			Suma(num1, num2);
		} else if (opcion == 2)
			Resta(num1, num2);
		else if (opcion == 3)
			Multiplicacion(num1, num2);
		else if (opcion == 4)
			Divicion(num1, num2);
		else if (opcion == 5)
			Potencia(num1, num2);
		else if (opcion == 6)
			Raiz(num1);
		else if (opcion == 0)
			Menu();
		else
			printf("\nN%cmero fuera de rango. Intente de nuevo.\n", 163);
		printf("\n\n");
	}
}

Suma(int num1, int num2) {
	int result = num1 + num2;
	printf("\nEl Resultado: %d\n", result);
}

Resta(int num1, int num2) {
	int result = num1 - num2;
	printf("\nEl Resultado: %d\n", result);
}

Multiplicacion(int num1, int num2) {
	int result = num1 * num2;
	printf("\nEl Resultado: %d\n", result);
}

Divicion(int num1, int num2) {
	float result;

	if (num2 != 0) {
		result = (float) num1 / (float) num2;
		printf("\nEl Resultado: %.4f\n", result);
	} else
		printf("No Cero!\n");
}

Potencia(int num1, int num2) {
	int result = pow(num1, num2);
	printf("\nEl Resultado: %i\n", result);
}

Raiz(int num1) {
	float result = sqrt(num1);
	printf("\nEl Resultado: %f\n", result);
}

/*---------- MOUNTHs CODE----------*/

int ano, mes, dia, bis, agrega, newMounth, newDia, newYear = 0, newDay;

Meses(){
	
	system("cls");
	system("color 5f");
	
	for(i=0;i<16;i++) printf("%c",205);
	printf("%c",187);
	printf("\nCalculadora dias%c\n",186);
	
	
	for(i=0;i<16;i++) printf("%c",205);
		printf("%c",188 );
	printf("\n\n");

	printf("\nIngrese a%co:",164);
	scanf("%d", &ano);
	if (ano % 4 == 0) { //Validar si es bisiesto
		bis = 1;
	} else {
		bis = 0;
	}
	printf("\nIngrese mes:");
	scanf("%d", &mes);
	while (mes > 12 || mes < 1) { //Valida que el mes no sea mas que 13
		printf("\nIngrese mes correcto:");
		scanf("%d", &mes);
	}
	printf("\nIngrese dia:");
	scanf("%d", &dia);
	if (bis == 1 && mes == 2) { //valida dias en febrero bisisesto
		while (dia > 29) {
			printf(
					"Ingrese dia correcto, febrero bisisesto tiene hasta 29 dias:");
			scanf("%d", &dia);
		}
	}

	if (bis == 0 && mes == 2) { //Valida dias en febrero no bisiesto
		while (dia > 28) {
			printf("Ingrese dia correcto, febrero tiene solo 28 dias:");
			scanf("%d", &dia);
		}
	}
	printf("\n\nUsted a ingresado el dia %d del mes %d del a%co %d",dia, mes, 164, ano);
	printf("\n\nIngrese la cantidad de dias a sumar: ");
	scanf("%d", &agrega);
    CuentaDias();
	printf("\n\n La nueva fecha es dia %d del mes %d del a%co %d\n", newDay,
			newMounth, 164, newYear);
	fflush(stdin);
	system("pause");
	Menu();
}

int CuentaDias() {

	newDay = dia;
	newMounth = mes;
	newYear = ano;
	
	while (agrega != 0) {

		/*ENERO*/
		while (newMounth == 1) {

			newDay++;
			agrega--;

			if (newDay > 31) {
				newDay = 1;
				newMounth++;
				break;
			}
			if (agrega <= 0) {
				return 0;
			}
		}
		
		/*FEBRAURY BIS*/
		while (newMounth == 2 && bis == 1) {

			newDay++;
			agrega--;

			if (newDay > 29) {
				newDay = 1;
				newMounth++;
				break;
			}
			if (agrega <= 0) {
				return 0;
			}
		}

		/*FEBRAURY*/
		while (newMounth == 2 && bis == 0) {

			newDay++;
			agrega--;

			if (newDay > 28) {
				newDay = 1;
				newMounth++;
				break;
			}
			if (agrega <= 0) {
				return 0;
			}
		}

		/*MARCH*/
		while (newMounth == 3) {

			newDay++;
			agrega--;

			if (newDay > 31) {
				newDay = 1;
				newMounth++;
				break;
			}

			if (agrega <= 0) {
				return 0;
			}
		}
		
		/*APRIL*/
		while (newMounth == 4) {

			newDay++;
			agrega--;

			if (newDay > 30) {
				newDay = 1;
				newMounth++;
				break;
			}
			if (agrega <= 0) {
				return 0;
			}
		}

		/*MAY*/
		while (newMounth == 5) {

			newDay++;
			agrega--;

			if (newDay > 31) {
				newDay = 1;
				newMounth++;
				break;
			}
			if (agrega <= 0) {
				return 0;
			}
		}
		
		/*JUNE*/
		while (newMounth == 6) {

			newDay++;
			agrega--;

			if (newDay > 30) {
				newDay = 1;
				newMounth++;
				break;
			}
			if (agrega <= 0) {
				return 0;
			}
		}
		
		/*JULY*/
		while (newMounth == 7) {

			newDay++;
			agrega--;

			if (newDay > 31) {
				newDay = 1;
				newMounth++;
				break;
			}
			if (agrega <= 0) {
				return 0;
			}
		}
		
		/*AUGUST*/
		while (newMounth == 8) {

			newDay++;
			agrega--;

			if (newDay > 31) {
				newDay = 1;
				newMounth++;
				break;
			}
			if (agrega <= 0) {
				return 0;
			}
		}
		
		/*SETIEMBRE*/
		while (newMounth == 9) {

			newDay++;
			agrega--;

			if (newDay > 30) {
				newDay = 1;
				newMounth++;
				break;
			}
			if (agrega <= 0) {
				return 0;
			}
		}
		
		/*OCTOBER*/
		while (newMounth == 10) {

			newDay++;
			agrega--;

			if (newDay > 31) {
				newDay = 1;
				newMounth++;
				break;
			}
			if (agrega <= 0) {
				return 0;
			}
		}
		
		/*NOVIEMBRE*/
		while (newMounth == 11) {

			newDay++;
			agrega--;

			if (newDay > 30) {
				newDay = 1;
				newMounth++;
				break;
			}
			if (agrega <= 0) {
				return 0;
			}
		}
		
		/*DICIEMBRE*/
		while (newMounth == 12) {

			newDay++;
			agrega--;

			if (newDay > 31) {
				newDay = 1;
				newMounth = 1;
				newYear++;
				if (newYear % 4 == 0)
					bis = 1;
				else
					bis = 0;
				break;
			}

			if (agrega <= 0) {
				return 0;
			}
		}
	}
	return 0;
}


