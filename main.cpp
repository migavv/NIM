/*
JUEGO DE NIM

Reglas del Juego:
Se juega entre 2 jugadores.
En una partida de NIM se tiene un número arbitrario de pilas que contienen un
número arbitrario de piezas. Los jugadores se deben turnar para extraer piezas 
de las pilas. En su respectivo turno, cada jugador podrá escoger únicamente una
pila y extraer la cantidad de piezas que desee extraer de dicha pila.
En esta versión de NIM gana el jugador que tome la última pieza.

Programa:
Este código permite al usuario jugar contra una IA que usa una estrategia
perfecta.
El usuario puede escoger el número de pilas y la cantidad de piezas por pila en
cada partida.
La IA escogerá los turnos y nuca perderá.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n; //Número de pilas
vector<int> stacks; //Tablero de juego

//Este método retorna 0 si la IA debe jugar para ganar. Cualquier otro número en caso contrario:
int getState() { 
    int v = 0;
    for(int i = 0; i < stacks.size(); i++) //Se hace XOR entre todas las pilas
        v ^= stacks[i]; 
    return v;
}

//Método auxiliar que muestra en consola los movimientos realizados:
void printMove(int r, int v) {
    cout << "IA>>Tomo " << v << " pieza(s) de la pila " << r                                                                                                                  << endl;
}

/*
Método que escoge la jugada perfecta para la IA:

El método consiste en encontrar una pila pi de las pilas de la partida y número
x tales que la operación XOR entre todas las pilas excluyendo pi con x sea igual
a 0 y x sea menor que el valor en pi.
Luego el movimiento que hará la IA consistirá en sustituir el valor en pi por x.
*/
void IA() { //Complejidad: O(n)
    int s = getState(); //XOR entre todas las pilas
    int i = 0, x;
    do {
        x = s ^ stacks[i]; //Excluye una pila de la operación XOR, aprovechando que XOR es reversible:
    } while(x >= stacks[i++]);
    printMove(i + 1, stacks[--i] - x);
    if(x) stacks[i] = x;
    else stacks.erase(stacks.begin() + i);
}

//Método auxiliar para hacer una jugada aleatoria.
void aut() {
    int r = rand() % stacks.size();
    int val = rand() % stacks[r] + 1;
    printMove(r + 1, val);
    if(stacks[r] == val) stacks.erase(stacks.begin() + r);
    else stacks[r] -= val;
}

//Método para gestionar las jugadas del usuario
void player() {
    int r, val;
    cout << "Elige la pila de la cual vas a tomar piezas\n>>";
    cin >> r;
    cout << "Elige el numero de piezas que vas a tomar\n>>";
    cin >> val;
    if(stacks[r-1] == val) stacks.erase(stacks.begin() + r-1);
    else stacks[r - 1] -= val;
}

//Método auxiliar para probar a la IA con jugadas aleatorias
void test() {
    int games;
    cout << "pruebas >>"; cin >> games;
    for(int g = 0; g < games; g++) {
        stacks.assign(rand() % 100 + 1, 0);
        for(int &v : stacks)
            v = rand() % 100 + 1;
        bool turn = getState();
        while(stacks.size()){
            cout << "---------\n";
            for(int i = 0; i < stacks.size(); i++)
                cout << i + 1 << ": " << stacks[i] << endl;
            cout << "---------\n";
            if(!turn) aut();
            else IA();
            turn = !turn;
        }
        if(turn) cout << "Ganaste! :(\n";
        else cout << "Perdiste\n";
    }
}

//Gestión de la partida:
void play() {
    cout << "Ingrese el numero de pilas\n>>";
    cin >> n;
    stacks.assign(n, 0);
    cout << "Ahora ingresa el numero de piezas por pila:\n";
    for(int i =0; i < n; i++) {
        cout << "Fila " << i + 1 << ": ";
        cin >> stacks[i];
    }
    bool turn = getState();
    while(stacks.size()){
        cout << "---------\n";
        for(int i = 0; i < stacks.size(); i++)
            cout << i + 1 << ": " << stacks[i] << endl;
        cout << "---------\n";
        if(!turn) player();
        else IA();
        turn = !turn;
    }
    if(turn) cout << "Ganaste!\n\n\n";
    else cout << "Perdiste :(\n\n\n";
}

//Ejecución del programa:
int main() {
    srand(time(NULL));
    int input;
    do {
        cout << "BIENVENIDO A NIM\n\nIngresa 1 para jugar, 0 para salir\n>>";
        cin >> input;
        if(input == 1) {
            play();
        }
        else if(input == 2) {
            test();
        }
    } while(input);
}
