// ProyectoFinal-Gato.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream> //Cargar archivos.

using namespace std;

//Prototipos.
void crearTablaGato();
void cargarTablaGato(char*&);
void jugadorX();
void jugadorO();
void jugarConContrincante();
int espaciosLlenos(char);
char revisarPartida();
void guardarPartida(Partida*&, string, string, string);


//Estructuras.
struct Partida
{
    string ganador;
    string perdedor;
    string estado;
    Partida* siguiente;
};

//Variables globales.
char* gato;
int casilla;
string jugadorUno;
string jugadorDos;
Partida* resultado = NULL;
bool bandera = false;

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

int espaciosLlenos(char letra)
{
    int espacios = 0;
    for (int i = 0; i < 9; i++)
    {
        if (gato[i] == letra)
        {
            espacios++;
        }
    }
    return espacios;
}

char revisarPartida()
{
    //Buscando el Ganador de Arriba hacia Abajo
    if (gato[0] == gato[3] && gato[3] == gato[6] && gato[0] != ' ')
    {
        return gato[0];
    }
    if (gato[1] == gato[4] && gato[4] == gato[7] && gato[1] != ' ')
    {
        return gato[1];
    }
    if (gato[2] == gato[5] && gato[5] == gato[8] && gato[2] != ' ')
    {
        return gato[2];
    }

    //Buscando el Ganador de Izquierda a Derecha
    if (gato[0] == gato[1] && gato[1] == gato[2] && gato[0] != ' ')
    {
        return gato[0]; //returnando la X o el O
    }
    if (gato[3] == gato[4] && gato[4] == gato[5] && gato[3] != ' ')
    {
        return gato[3];
    }
    if (gato[6] == gato[7] && gato[7] == gato[8] && gato[6] != ' ')
    {
        return gato[6];
    }

    //Buscando el Ganador en Diagonal
    if (gato[0] == gato[4] && gato[4] == gato[8] && gato[0] != ' ')
    {
        return gato[0];
    }
    if (gato[2] == gato[4] && gato[4] == gato[6] && gato[2] != ' ')
    {
        return gato[2];
    }

    //Revisando si fue un empate
    if (espaciosLlenos('X') + espaciosLlenos('O') < 9)
    {
        return 'C';
    }
    else
    {
        return 'E';
    }
}

void guardarPartida(Partida*& resultado, string ganador, string perdedor, string estado)
{
    //Creando espacio en memoria para almacenar la partida
    Partida* nuevaPartida = new Partida();

    //Cargando partida

    nuevaPartida->ganador = ganador;
    nuevaPartida->perdedor = perdedor;
    nuevaPartida->siguiente = resultado;

    resultado = nuevaPartida;
}

void jugarConContrincante()
{
    cout << "Iniciando Partida..." << endl;
    cout << "Nombre del Jugador 1 (X): ";
    cin >> jugadorUno;
    cout << "Nombre del Jugador 2 (O): ";
    cin >> jugadorDos;
    do
    {
        system("cls");
        crearTablaGato();//mostrando la tabla del gato que fue inicializada o cargada antes
        if (espaciosLlenos('X') == espaciosLlenos('O'))
        {
            cout << "Es el turno de " << jugadorUno << " (X)" << endl;
            jugadorX();
        }
        else
        {
            cout << "Es el turno de " << jugadorDos << " (O)" << endl;
            jugadorO();
        }


        //Revisando si ya hay un jugador que gano
        char ganador = revisarPartida();

        switch (ganador)
        {
        case 'X':
            system("cls");
            crearTablaGato();
            cout << "El jugador " << jugadorUno << " (X)" << " gano la partida" << endl;
            guardarPartida(resultado, jugadorUno, jugadorDos, "UN SOLO GANADOR");
            bandera = true;
            break;
        case 'O':
            system("cls");
            crearTablaGato();
            cout << "El jugador " << jugadorDos << " (O)" << " gano la partida" << endl;
            guardarPartida(resultado, jugadorDos, jugadorUno, "UN SOLO GANADOR");
            bandera = true;
            break;
        case 'E':
            system("cls");
            crearTablaGato();
            cout << "Nadie gano, es un Empate" << endl;
            guardarPartida(resultado, jugadorUno, jugadorDos, "EMPATE");
            bandera = true;
            break;
        }
    } while (bandera != true);
}
