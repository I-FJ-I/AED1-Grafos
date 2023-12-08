#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <list>
using namespace std;

#define MAX_NODOS 20000  

int numero_nodos;
list<int> G[MAX_NODOS];
bool visitado[MAX_NODOS];

void lee_grafo() {
    cin >> numero_nodos;
    if (numero_nodos < 0 || numero_nodos > MAX_NODOS) {
        cerr << "Número de nodos (" << numero_nodos << ") no valido" << endl;
        exit(0);
    }
    int n;
    cin.ignore();
    string linea;
    for (int i = 0; i < numero_nodos; i++) {
        G[i].clear();
        getline(cin, linea);
        istringstream stream(linea);
        while (stream >> n) 
            G[i].push_back(n - 1);
    }
}

void bpp(int v, string &camino, int &pasos) {
    visitado[v] = true;
    pasos++;
    camino += "\n" + to_string(v + 1);
    for (list<int>::iterator siguiente = G[v].begin(); siguiente != G[v].end(); siguiente++) {
        if (!visitado[*siguiente] && !visitado[numero_nodos - 1]) { 
            bpp(*siguiente, camino, pasos); 
            if (!visitado[numero_nodos - 1]) {
                camino += "\n" + to_string(v + 1);
                pasos++;
            }
        }
    }
}

void camino_pablito() {
    fill(visitado, visitado + MAX_NODOS, false);
    string camino;
    int pasos = 0;
    bpp(0, camino, pasos);
    if (visitado[numero_nodos - 1])
        cout << endl << pasos << camino;
    else 
        cout << "\nINFINITO";
}

int main() {
    int numero_casos;
    cin >> numero_casos;
    for (int i = 0; i < numero_casos; i++) {
        lee_grafo();
        cout << "Caso " << i + 1;
        camino_pablito();
        cout << endl;
    }
}
