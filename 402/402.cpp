#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <queue>
using namespace std;

#define MAX_NODOS 26

int n_nodos;
int n_aristas;
bool G[MAX_NODOS][MAX_NODOS];
bool visitado[MAX_NODOS];

void lee_grafo(void) {
    cin >> n_nodos >> n_aristas;
    if (n_nodos < 0 || n_nodos > MAX_NODOS) {
        cerr << "Número de nodos (" << n_nodos << ") no valido" << endl;
        exit(0);
    }
    memset(G, 0, sizeof(G));
    char c1, c2;
    for (int i = 0; i < n_aristas; i++) {
        cin >> c1 >> c2;
        G[c1-'A'][c2-'A'] = true;
    }
}

void bpa(int v) {
    queue<int> cola;
    visitado[v] = true;
    cola.push(v);
    while (!cola.empty()) {
        int x = cola.front();
        cola.pop();
        cout << char(x + 'A');    
        for (int i = 0; i < n_nodos; i++) 
            if (!visitado[i] && G[x][i]) {
                cola.push(i); 
                visitado[i] = true;
        }
    }
}

void busqueda(void) {
    memset(visitado, 0, sizeof(visitado));
    for (int i = 0; i < n_nodos; i++)
        if (!visitado[i]) {
            bpa(i);
        }
    cout << endl;
}

int main(void) {
    int n_casos;
    cin >> n_casos;
    for (int i = 0; i < n_casos; i++) {
        lee_grafo();
        busqueda();
    }
}
