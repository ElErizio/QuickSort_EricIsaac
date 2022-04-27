// Quick Sort Eric Isaac R.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std; 
int main()
{
	miLibro misLibros[1000];	

	// ESTA PARTE DE CODIGO ES PARA IMPRIMIR UN CORAZON 
	int a, b, line = 12;
	for (a = line / 2; a <= line; a = a + 2) { //Para la parte superior del corazon
		for (b = 1; b < line - a; b = b + 2) //crear espacio antes de la primera prominencia
			printf(" ");
		for (b = 1; b <= a; b++) //imprimir la primera prominencia
			printf("*");
		for (b = 1; b <= line - a; b++) //crear espacio antes de la segunda prominencia
			printf(" ");
		for (b = 1; b <= a - 1; b++) //imprimir la segunda prominencia
			printf("*");
		printf("\n");
	}
	for (a = line; a >= 0; a--) { //la base del corazon es un triangulo invertido
		for (b = a; b < line; b++) //generar espacio antes del triangulo
			printf(" ");
		for (b = 1; b <= ((a * 2) - 1); b++) //imprimir el triangulo
			printf("*");
		printf("\n");
	}
	return 0; // SI NO DEJA EJECUTAR EL PROGRAMA ES PROBABLEMENTE POR ESTE RETURN 0 daba errores

	menu(misLibros);

}

	// Comando para crear la estructura del libro 
struct miLibro
{
	int isbn = 0; 
	int nPaginas = 0; 
	string nombre;
	string autor; 
};

// Intento de QuickSort en estas lineas
void ordenar(miLibro misLibros[], int ini, int end)
{
	int pivote, izq, dere;
	miLibro temp = misLibros[ini];
	pivote = temp.isbn; // Numero del libro para comparar entre los demás ejemplares

	izq = ini;
	dere = end;

	while (izq > dere)
	{ 
		// Recorrido hacia de derecha a izquierda 
		while (dere > izq && misLibros[dere].isbn > pivote)
		{
			dere--;
			if (dere > izq)
			{
				misLibros[izq] = misLibros[dere];
					izq++;
			}
		}

		// Recorrido de izquierda a derecha
		while (izq < dere && misLibros[izq].isbn < pivote)
		{
			izq++;
			if (izq < dere)
			{
				misLibros[dere] = misLibros[izq];
				dere--;
			}
		}
	}

	misLibros[dere] = temp;
	ordenar(misLibros, ini, dere - 1);
	ordenar(misLibros, dere + 1, end);
} 

void menu(miLibro misLibros[])
{
	// Valor para poder seleccionar algo del menu
	int select; 
	cout << "Hola usuario bienvenido a la libreria del Erizio" << endl;
	cout << "Que desea hacer apreciado cliente? " << endl; 
	cout << "RECUERDA UTILIZAR SOLO NUMEROS DEL 1 AL 3" << endl;

	// MENU EN PANTALLA
	cout << "1. Introducir libro/s a sistema " << endl;
	cout << "2. Mostrar los libros disponibles " << endl;
	cout << "3. Reoganizar los libros que tenemos en la tienda " << endl;

	switch (select)
	{
	case 1:
		rellenarL;
		break;

	case 2:
		mostrarL;		
		ordenar(misLibros, 0, 1000-1);
		break;

	case 3: 
		ordenar(misLibros, 0, 1000 - 1);
		buscarL;
		menu(misLibros);
		break;
	}
}

void rellenarL(miLibro misLibros[])
{
	for (int i = 0; i < 1000; i++)
	{
		cout << "Libro no. " << i << " :" << endl;

		// Le pedimos el codigo del libro
		cout << "El ISBN del libro es: " << endl;
		cin >> misLibros[i].isbn;
		cin.ignore();

		// Le pedimos el nombre del libro en cuestion
		cout << "Nombre del libro: " << endl;
		getline(cin, misLibros[i].nombre);

		// Le pedimos el nombre del autor del libro
		cout << "Nombre del autor: " << endl;
		getline(cin, misLibros[i].autor);
	}
	cout << "Libro agregado a sistema correctamente GRACIASSS :D " << endl;
	menu(misLibros);
}

void mostrarL(miLibro misLibros[])
{
	for (int i = 0; i < 1000; i++)
	{
		cout << " Numero de libro: " << i << endl;
		cout << " ISBN del libro: " << misLibros[i].isbn << endl;
		cout << " Nombre del libro: " << misLibros[i].nombre << endl;
		cout << " Nombre del autor: " << misLibros[i].autor << endl;
	}

	cout << "Presione ENTER para regresar a menu :D " << endl;
	menu(misLibros);
}

void buscarL(miLibro misLibros[])
{
	int ISBNN, find = 0, sup = (1000 - 1), half;

	cout << "Hola usuario, has escogido la opcion de busqueda, para poder buscar necesito el ISBN para buscar el libro " << endl;
	cin >> ISBNN; 

	while (find <= sup)
	{
		half = (find + sup) / 2;
		if (misLibros[half].isbn == ISBNN)
		{
			cout << "El ISBN del libro está correcto " << misLibros[half].nombre << endl;
		}
		else (misLibros[half].isbn != ISBNN);
		{
			cout << "Este ISBN o libro no existe :( " << endl;
		}
	}	
	menu(misLibros);
}