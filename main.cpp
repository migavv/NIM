#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n;
bool testing = false;
vector<int> stacks;

int getState() {
    int v = 0;
    for(int i = 0; i < stacks.size(); i++)
        v ^= stacks[i];
    return v;
}

void printMove(int p, int r, int v) {
    cout << p << ">>Tomo " << v << " pieza(s) de la pila " << r << endl;
}

void IA() {
    if(stacks[stacks.size() - 1] == 1) {
        printMove(2, stacks.size(), stacks[stacks.size() - 1]);
        stacks.pop_back();
    }
    else if(stacks.size() == 1) {
        if(!testing) printMove(2, 1, stacks[0] - 1);
        stacks[0] = 1;
    }
    else if(stacks[stacks.size()-2] == 1) {
        int m = stacks.size()-1;
        if(stacks.size() % 2 == 0) {
            printMove(2, m + 1, stacks[m]);
            stacks.pop_back();
        }
        else {
            printMove(2, m + 1, stacks[m] - 1);
            stacks[m] = 1;
        }
    }
    else {
        int s = getState();
        int i = 0, aux;
        do {
            aux = s ^ stacks[i];
        } while(aux >= stacks[i++]);
        if(!testing) printMove(2, i + 1, stacks[--i] - aux);
        if(aux) stacks[i] = aux;
        else stacks.erase(stacks.begin() + i);
    }
}

void aut() {
    int r = rand() % stacks.size();
    int val = rand() % stacks[r] + 1;
    if(!testing) printMove(3, r + 1, val);
    if(stacks[r] == val) stacks.erase(stacks.begin() + r);
    else stacks[r] -= val;
}

void player() {
    int r, val;
    cout << "Elige la pila de la cual vas a tomar piezas\n>>";
    cin >> r;
    cout << "Elige el numero de piezas que vas a tomar\n>>";
    cin >> val;
    if(stacks[r-1] == val) stacks.erase(stacks.begin() + r-1);
    else stacks[r - 1] -= val;
}

void test() {
    int games;
    cout << "pruebas >>"; cin >> games;
    for(int g = 0; g < games; g++) {
        stacks.assign(rand() % 100 + 1, 0);
        for(int &v : stacks)
            v = rand() % 100 + 1;
        bool turn = getState();
        while(stacks.size()){
            sort(stacks.begin(), stacks.end());
            cout << "---------\n";
            for(int i = 0; i < stacks.size(); i++)
                cout << i + 1 << ": " << stacks[i] << endl;
            cout << "---------\n";
            if(!turn) aut();
            else IA();
            turn = !turn;
        }
        if(turn) cout << "Perdiste :(\n";
        else cout << "Ganaste!\n";
        system("pause");
    }
}

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
    system("cls");
    while(stacks.size()){
        sort(stacks.begin(), stacks.end());
        cout << "---------\n";
        for(int i = 0; i < stacks.size(); i++)
            cout << i + 1 << ": " << stacks[i] << endl;
        cout << "---------\n";
        if(!turn) player();
        else IA();
        turn = !turn;
    }
    if(turn) cout << "Perdiste :(\n";
    else cout << "Ganaste!\n";
    system("pause");
}

int main() {
    srand(time(NULL));
    int input;
    do {
        cout << "BIENVENIDO A NIM\n\nIngresa 1 para jugar, 0 para salir\n>>";
        cin >> input;
        system("cls");
        if(input == 1) {
            play();
        }
        else if(input == 2) {
            testing = false;
            test();
        }
        system("cls");
    } while(input);
}
