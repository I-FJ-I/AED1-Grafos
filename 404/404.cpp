#include <iostream>
#include <algorithm>
#include <limits>
#define MAX_NODOS 1500
#define INFINITO numeric_limits<uint16_t>::max()

using namespace std;

int numero_nodos;
int numero_aristas;
int inicio;
int paso;
int fin;
int G[MAX_NODOS][MAX_NODOS];
int D[MAX_NODOS];
int P[MAX_NODOS];
bool S[MAX_NODOS];

void lee_grafo() {
    cin >> numero_nodos >> numero_aristas >> inicio >> fin >> paso;
    if (numero_nodos < 0 || numero_nodos > MAX_NODOS) {
        cerr << "Número de nodos (" << numero_nodos << ") no valido" << endl;
        exit(0);
    }
    inicio -= 1;
    fin -= 1;
    paso -= 1;
    for (int i = 0; i < numero_nodos; i++)
        for (int j = 0; j < numero_nodos; j++)
            G[i][j] = INFINITO;
    for (int i = 0; i < numero_aristas; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u -= 1;
        v -= 1;
        G[u][v] = c;
        G[v][u] = c;
    }
}

int escoger_nodo() {
    int elegido = inicio;
    int peso = INFINITO;
    for (int i = 0; i < numero_nodos; i++) {
        if (!S[i] && D[i] < peso) {
            elegido = i;
            peso = D[i];
        }
    }
    return elegido;
}

void dijkstra(int origen, int destino) {
    for (int i = 0; i < numero_nodos; i++) {
        D[i] = G[origen][i];
        P[i] = origen;
        S[i] = false;
    }
    P[origen] = -1;
    S[origen] = true;
    for (int i = 0; i < numero_nodos; i++) {
        int v = escoger_nodo();
        S[v] = true;
        for (int w = 0; w < numero_nodos; w++) {
            if (!S[w] && D[v] + G[v][w] < D[w]) {
                D[w] = D[v] + G[v][w];
                P[w] = v;
            }
        }
    }
}

int main() {
    int numero_casos;
    cin >> numero_casos;
    for (int i = 0; i < numero_casos; i++) {
        lee_grafo();
        int peso = 0;
        dijkstra(inicio, paso);
        peso += D[paso];
        dijkstra(paso, fin);
        peso += D[fin];
        if (peso < INFINITO)
            cout << peso << endl;
        else
            cout << "IMPOSIBLE" << endl;
    }
}
