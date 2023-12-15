#include <iostream>
#include <string.h>
#define MAX_NODOS 2000

using namespace std;
bool G[MAX_NODOS][MAX_NODOS];
bool hombre_da_like[MAX_NODOS];
int pareja_de[MAX_NODOS];
int numero_hombres, numero_mujeres, numero_relaciones, parejitas;

void lee_grafo() {
    cin >> numero_hombres >> numero_mujeres >> numero_relaciones;
    memset(G, 0, sizeof(G));
    for (int i = 0; i < numero_relaciones; i++) {
        int h, m;
        cin >> h >> m;
        G[h-1][m-1] = true;
        G[m-1][h-1] = true;
    }
}

bool le_gusta_a_alguien(int h) {
    for (int m = numero_hombres; m < numero_hombres+numero_mujeres; m++) {
        int identificador_femenino = m-numero_hombres;
        if (G[h][m] && !hombre_da_like[identificador_femenino]) {
            hombre_da_like[identificador_femenino] = true;
            if (pareja_de[identificador_femenino] < 0 || le_gusta_a_alguien(pareja_de[identificador_femenino])) {
                pareja_de[identificador_femenino] = h;
                return true;
            }
        }
    }
    return false;
}

void calcula_relaciones() {
    memset(pareja_de, -1, sizeof(pareja_de));
    parejitas = 0;
    for (int h = 0; h < numero_hombres; h++) {
        memset(hombre_da_like, 0, sizeof(hombre_da_like));
        if (le_gusta_a_alguien(h))
            parejitas++;
    }
}

int main() {
    int numero_casos;
    cin >> numero_casos;
    while (numero_casos--) {
        lee_grafo();
        calcula_relaciones();
        cout << parejitas << endl;
    }
}
