#include <iostream>
#include <fstream> //Cargar archivos.

using namespace std;

// Estructuras.
struct Partida
{
    string ganador;
    string perdedor;
    string estado;
    Partida* siguiente;
};

// Prototipos.
void crearTablaGato();
void jugadorX();
void jugadorO();
void jugarConContrincante();
int espaciosLlenos(char);
char revisarPartida();
void guardarPartida(Partida*&, string, string, string);
void mostrarPartidas(Partida*);
void guardarPartidasEnArchivo(Partida*, const string&);
void menu();

// Variables globales.
char* gato;
int casilla;
string jugadorUno;
string jugadorDos;
Partida* resultado = NULL;
bool bandera = false;

int main()
{
    // Inicializar el tablero de gato.
    gato = new char[9];
    for (int i = 0; i < 9; i++)
        gato[i] = ' ';

    menu();

    // Liberar la memoria asignada para el tablero.
    delete[] gato;

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
        casilla--; // Las posiciones de gato comienzan desde 0

        // Validación en caso que se haya seleccionado anteriormente.
        if (gato[casilla] != ' ')
        {
            cout << "Debe escoger una casilla vacia!" << endl;
        }
        // Validación por si se ingresa un número fuera del rango de posiciones
        else if (casilla < 0 || casilla > 8)
        {
            cout << "Intente de nuevo, las opciones validas son del 1 - 9" << endl;
        }
        else
        {
            gato[casilla] = 'X'; // Indicando que la casilla seleccionada es con la X
            break;
        }
    }
}

void jugadorO()
{
    while (true)
    {
        cout << "Escoja una casilla vacía (1 - 9): ";
        cin >> casilla;
        casilla--; // Las posiciones de gato comienzan desde 0

        // Validación en caso que se haya seleccionado anteriormente.
        if (gato[casilla] != ' ')
        {
            cout << "Debe escoger una casilla vacia!" << endl;
        }
        // Validación por si se ingresa un número fuera del rango de posiciones
        else if (casilla < 0 || casilla > 8)
        {
            cout << "Intente de nuevo, las opciones validas son del 1 - 9" << endl;
        }
        else
        {
            gato[casilla] = 'O'; // Indicando que la casilla seleccionada es con la O
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
    // Buscando el Ganador de Arriba hacia Abajo
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

    // Buscando el Ganador de Izquierda a Derecha
    if (gato[0] == gato[1] && gato[1] == gato[2] && gato[0] != ' ')
    {
        return gato[0]; // Retornando la X o el O
    }
    if (gato[3] == gato[4] && gato[4] == gato[5] && gato[3] != ' ')
    {
        return gato[3];
    }
    if (gato[6] == gato[7] && gato[7] == gato[8] && gato[6] != ' ')
    {
        return gato[6];
    }

    // Buscando el Ganador en Diagonal
    if (gato[0] == gato[4] && gato[4] == gato[8] && gato[0] != ' ')
    {
        return gato[0];
    }
    if (gato[2] == gato[4] && gato[4] == gato[6] && gato[2] != ' ')
    {
        return gato[2];
    }

    // Revisando si fue un empate
    if (espaciosLlenos('X') + espaciosLlenos('O') < 9)
    {
        return 'C'; // ContinUa el juego
    }
    else
    {
        return 'E'; // Empate
    }
}

void guardarPartida(Partida*& resultado, string ganador, string perdedor, string estado)
{
    // Creando espacio en memoria para almacenar la partida
    Partida* nuevaPartida = new Partida();

    // Cargando partida
    nuevaPartida->ganador = ganador;
    nuevaPartida->perdedor = perdedor;
    nuevaPartida->estado = estado;
    nuevaPartida->siguiente = resultado;

    resultado = nuevaPartida;
}

void jugarConContrincante()
{
        // Reiniciar el tablero antes de iniciar la partida
        delete[] gato; // Liberar la memoria previamente asignada
        gato = new char[9]; // Asignar nueva memoria para el tablero
        for (int i = 0; i < 9; i++)
            gato[i] = ' '; // Inicializar el tablero

        bandera = false; // Reiniciar la bandera

        cout << "Iniciando Partida..." << endl;
        cout << "Nombre del Jugador 1 (X): ";
        cin >> jugadorUno;
        cout << "Nombre del Jugador 2 (O): ";
        cin >> jugadorDos;
        do
        {
            system("cls"); // Reemplaza o elimina esta línea si no estás en Windows
            crearTablaGato(); // Mostrando la tabla del gato que fue inicializada o cargada antes
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

            // Revisando si ya hay un jugador que ganó
            char ganador = revisarPartida();

            switch (ganador)
            {
            case 'X':
                system("cls"); // Reemplaza o elimina esta línea si no estás en Windows
                crearTablaGato();
                cout << "El jugador " << jugadorUno << " (X)" << " gano la partida" << endl;
                guardarPartida(resultado, jugadorUno, jugadorDos, "UN SOLO GANADOR");
                bandera = true;
                break;
            case 'O':
                system("cls"); // Reemplaza o elimina esta línea si no estás en Windows
                crearTablaGato();
                cout << "El jugador " << jugadorDos << " (O)" << " gano la partida" << endl;
                guardarPartida(resultado, jugadorDos, jugadorUno, "UN SOLO GANADOR");
                bandera = true;
                break;
            case 'E':
                system("cls"); // Reemplaza o elimina esta línea si no estás en Windows
                crearTablaGato();
                cout << "¡La partida termino en empate!" << endl;
                guardarPartida(resultado, jugadorUno, jugadorDos, "EMPATE");
                bandera = true;
                break;
            }
        } while (!bandera);

        cout << "Fin de la partida!" << endl;
}

void guardarPartidasEnArchivo(Partida* resultado)
{
    const string nombreArchivo = "score.txt";
    ofstream archivo(nombreArchivo);
    if (archivo.is_open())
    {
        Partida* actual = resultado;
        while (actual != nullptr)
        {
            archivo << "Ganador: " << actual->ganador << "\n";
            archivo << "Perdedor: " << actual->perdedor << "\n";
            archivo << "Estado: " << actual->estado << "\n";
            archivo << "--------------------------\n";
            actual = actual->siguiente;
        }
        archivo.close();
        cout << "Partidas guardadas en el archivo " << nombreArchivo << " exitosamente." << endl;
    }
    else
    {
        cout << "Error al abrir el archivo." << endl;
    }
}


void mostrarPartidas(Partida* resultado)
{
    Partida* actual = resultado;
    while (actual !=  NULL)
    {
        cout << "Ganador: " << actual->ganador << endl;
        cout << "Perdedor: " << actual->perdedor << endl;
        cout << "Estado: " << actual->estado << endl;
        cout << "--------------------------" << endl;
        actual = actual->siguiente;
    }
}

void menu()
{
    int opcion;
    string nombreArchivo;
    do
    {
        cout << "----- Menu Principal -----" << endl;
        cout << "1. Jugar con contrincante" << endl;
        cout << "2. Mostrar partidas" << endl;
        cout << "3. Guardar partidas en archivo" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            system("cls");
            jugarConContrincante();
            break;
        case 2:
            mostrarPartidas(resultado);
            break;
        case 3:
            guardarPartidasEnArchivo(resultado);
            break;
        case 4:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 3);
}
