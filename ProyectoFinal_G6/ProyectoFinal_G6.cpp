// ProyectoFinal-Gato.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream> //Cargar archivos.

using namespace std;

//Prototipos.
void crearTablaGato();
void jugadorX();
void jugadorO();

//Estructuras.


//Variables globales.
char* gato;
int casilla;

int main()
{

    return 0;
}

void crearTablaGato()
{
    cout << "\n" << endl;
    cout << "\t    " << "    |   " << "    |    " << endl;
    cout << "\t    " << gato[0] << "   |   " << gato[1] << "   |   " << gato[2] << endl;
    cout << "\t    " << "    |   " << "    |    " << endl;
    cout << "\t-------------------------" << endl;
    cout << "\t    " << "    |   " << "    |    " << endl;
    cout << "\t    " << gato[3] << "   |   " << gato[4] << "   |   " << gato[5] << endl;
    cout << "\t    " << "    |   " << "    |    " << endl;
    cout << "\t-------------------------" << endl;
    cout << "\t    " << "    |   " << "    |    " << endl;
    cout << "\t    " << gato[6] << "   |   " << gato[7] << "   |   " << gato[8] << endl;
    cout << "\t    " << "    |   " << "    |    " << endl;
    cout << "\n" << endl;
}

void jugadorX()
{
    while (true)
    {
        cout << "Ingrese una casilla vacia (1 - 9): ";
        cin >> casilla;
        casilla--; //Las posiciones de gato comienzan desde 0,ya que el numero que ingrese se debe restar 1 para marcar la posicion correcta

        //Validacion en caso que se haya seleccionado anteriormente.
        if (gato[casilla] != ' ')
        {
            cout << "Debe escoger una casilla vacia!" << endl;
        }
        //Validacion por si se ingrese un numero fuera del rango de posiciones
        else if (casilla < 0 || casilla > 8)
        {
            cout << "Intente de nuevo, las opciones validas son del 1 - 9" << endl;
        }
        else
        {
            gato[casilla] = 'X'; //indicandole que la casilla seleccionada es con la X
            break;
        }
    }
}

void jugadorO()
{
    while (true)
    {
        cout << "Escoja una casilla vacia (1 - 9): ";
        cin >> casilla;
        casilla--; //Las posiciones de gato comienzan desde 0,ya que el numero que ingrese se debe restar 1 para marcar la posicion correcta

        //Validacion en caso que se haya seleccionado anteriormente.
        if (gato[casilla] != ' ')
        {
            cout << "Debe escoger una casilla vacia!" << endl;
        }
        //Validacion por si se ingrese un numero fuera del rango de posiciones
        else if (casilla < 0 || casilla > 8)
        {
            cout << "Intente de nuevo, las opciones validas son del 1 - 9" << endl;
        }
        else
        {
            gato[casilla] = 'O'; //indicandole que la casilla seleccionada es con la O
            break;
        }
    }
}
