#include <iostream>
#include <algorithm>
#include <limits>
#define MAX_NODOS 200
#define INFINITO numeric_limits<uint16_t>::max()

using namespace std;

string ciudades[MAX_NODOS];
int D[MAX_NODOS][MAX_NODOS];
int numero_nodos;

void leer_grafo() {
    cin >> numero_nodos;
    cin.ignore();
    for (int i = 0; i < numero_nodos; i++) 
        getline(cin, ciudades[i]);
    for (int i = 0; i < numero_nodos; i++) 
        for (int j = 0; j < numero_nodos; j++) {
            if (i == j)
                D[i][j] = 0;
            else
                D[i][j] = INFINITO;
        }

    int a, b, l;
    while (true) {
        cin >> a >> b >> l;
        if (a == 0 && b == 0 && l == 0)
            break;
        D[a][b] = l;
        D[b][a] = l;
    } 
}

void floyd() {
    for (int k = 0; k < numero_nodos; k++)
        for (int i = 0; i < numero_nodos; i++)
            for (int j = 0; j < numero_nodos; j++)
                D[i][j] = min<int>(D[i][j], D[i][k] + D[k][j]);
}

void excentricidad() {
    int excentr;
    int excentr_cap = INFINITO;
    int capital = -1; 
    for (int i = 0; i < numero_nodos; i++) {
        excentr = -1;
        for (int j = 0; j < numero_nodos; j++)
            if (D[i][j] > excentr)
                excentr = D[i][j];
        if (excentr < excentr_cap) {
            excentr_cap = excentr;
            capital = i;
        } else if (excentr == excentr_cap && ciudades[i] < ciudades[capital])
            capital = i;
    }
    cout << ciudades[capital] << endl << excentr_cap << endl;
}

int main() {
    int numero_casos;
    cin >> numero_casos;
    for (int i = 0; i < numero_casos; i++) {
        leer_grafo();
        floyd();
        excentricidad();
    }
}
