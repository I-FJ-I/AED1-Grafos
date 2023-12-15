#include <iostream>
#include <string.h>
#define MAX_DIMEN 1000

using namespace std;

int celda[MAX_DIMEN][MAX_DIMEN];
bool visitada[MAX_DIMEN][MAX_DIMEN];
int ancho, largo;

void lee_grafo() {
    cin >> ancho >> largo;
    for (int i = 0; i < ancho; i++) 
        for (int j = 0; j < largo; j++) {
            cin >> celda[i][j];
            visitada[i][j] = false;
    }
}

bool alien_escapa(int veneno, int x, int y, int altura_anterior) {
    if (x < 0 || x >= ancho || y < 0 || y >= largo || visitada[x][y] || celda[x][y] < veneno || celda[x][y]-altura_anterior > 1 || celda[x][y]-altura_anterior < -1)
        return false;
    if (x == ancho - 1 && y == largo - 1)
        return true;
    visitada[x][y] = true;
    return alien_escapa(veneno, x + 1, y, celda[x][y]) ||
           alien_escapa(veneno, x, y + 1, celda[x][y]) ||
           alien_escapa(veneno, x - 1, y, celda[x][y]) ||
           alien_escapa(veneno, x, y - 1, celda[x][y]);
}

int veneno_pa_tu_piel() {
    int veneno = 0;
    while (alien_escapa(veneno, 0, 0, celda[0][0])) {
        memset(visitada, 0, sizeof(visitada));
        veneno++;
    }
    return veneno;
}

int main() {
    int numero_casos;
    cin >> numero_casos;
    for (int i = 0; i < numero_casos; i++) {
        lee_grafo();
        cout << "Caso #" << i+1 << ": " << veneno_pa_tu_piel() << endl;
    }
}
