#include <iostream>
#include <limits>
#define MAX_NODOS 1000
#define INFINITO numeric_limits<int>::max()

using namespace std;

int G[MAX_NODOS][MAX_NODOS];
int D[MAX_NODOS];
int P[MAX_NODOS];
bool S[MAX_NODOS];
int numero_aristas, numero_nodos;
bool primer_caso = true;

bool lee_grafo() {
    cin >> numero_nodos >> numero_aristas;
    if (!numero_nodos && !numero_aristas)
        return false;
    if (!primer_caso)
        cout << endl;
    else
        primer_caso = false;
    int x, y, z;
    for (int i = 0; i < numero_nodos; i++)
        for (int j = 0; j < numero_nodos; j++)
            G[i][j] = INFINITO;
    for (int i = 0; i < numero_aristas; i++) {
        cin >> x >> y >> z;
        G[x][y] = z;
        G[y][x] = z;
    }
    return true;
}

int escoger_nodo() {
    int elegido = 0;
    int peso = INFINITO;
    for (int i = 0; i < numero_nodos; i++) {
        if (!S[i] && D[i] < peso) {
            elegido = i;
            peso = D[i];
        }
    }
    return elegido;
}

void dijkstra(int origen) {
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
            if (!S[w] && G[w][v] != INFINITO && max<int>(D[v],G[w][v]) < D[w]) {
                D[w] = max<int>(D[v], G[w][v]);
                P[w] = v;
            }
        }
    }
}

void viaje() {
    int casos;
    cin >> casos;
    int origen, destino;
    for (int i = 0; i < casos; i++) {
        cin >> origen >> destino;
        dijkstra(origen);
        cout << D[destino] << endl;
    }
}

int main() {
    while (lee_grafo()) 
        viaje();
}
