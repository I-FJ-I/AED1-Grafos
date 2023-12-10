#include <iostream>
#define MAX_NODOS 500
using namespace std;

bool G[MAX_NODOS][MAX_NODOS];
bool P[MAX_NODOS];
int islas[MAX_NODOS];
int isla;
int numero_nodos;
int numero_aristas;

void leer_grafo() {
    fill(P, P + MAX_NODOS, false);
    isla = 0;
    cin >> numero_nodos >> numero_aristas;
    for (int i = 0; i < numero_nodos; i++)
        for (int j = 0; j < numero_nodos; j++)
            G[i][j] = false;
    int persona1, persona2;
    for (int i = 0; i < numero_aristas; i++) {
        cin >> persona1 >> persona2;
        G[persona1-1][persona2-1] = true;
        G[persona2-1][persona1-1] = true;
    }
}

void bpp(int v) {
    P[v] = true;
    islas[v] = isla;
    for (int i = 0; i < numero_nodos; i++) {
        if (!P[i] && G[v][i])
            bpp(i);
    }
}

void obtener_islas() {
    for (int i = 0; i < numero_nodos; i++) {
        if (!P[i]) {
            isla++;
            bpp(i);
        }
    }
    cout << isla << endl;
    for (int i = 0; i < numero_nodos; i++) {
        cout << islas[i] << endl;
    }
}

int main() {
    int numero_casos;
    cin >> numero_casos;
    for (int i = 0; i < numero_casos; i++) {
        cout << "Caso " << i + 1 << endl;
        leer_grafo();
        obtener_islas();
    }
}
