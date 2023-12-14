#include <iostream>
#include <string.h>
#include <limits>
#include <cmath>
#define MAX_NODOS 2000

using namespace std;

typedef struct {
    int x;
    int y;
} coordenadas;
coordenadas ciudades[MAX_NODOS];
int G[MAX_NODOS][MAX_NODOS];
int mas_cercano[MAX_NODOS];
int menor_coste[MAX_NODOS];
bool U[MAX_NODOS];
int numero_ciudades;

inline int cuadrado(int a) {
    return a*a; 
}

int distancia_euclidea(coordenadas c1, coordenadas c2) {
    return trunc(sqrt(cuadrado(c2.x-c1.x)+cuadrado(c2.y-c1.y))); 
}

void lee_grafo() {
    int x, y;
    cin >> numero_ciudades;
    for (int i = 0; i < numero_ciudades; i++) {
        cin >> x >> y;
        ciudades[i].x = x;
        ciudades[i].y = y;
    }
    memset(U, 0, sizeof(U));
    for (int i = 0; i < numero_ciudades; i++) {
        for (int j = 0; j < numero_ciudades; j++) {
            int dist = distancia_euclidea(ciudades[i], ciudades[j]);
            G[i][j] = dist;
            G[j][i] = dist;
        }
    }
}

int escoger_nodo() {
    int escogido = -1;
    int distancia_min = -1;
    for (int v = 0; v < numero_ciudades; v++) {
        if (!U[v] && (menor_coste[v] < distancia_min || distancia_min == -1)) {
            escogido = v;
            distancia_min = menor_coste[v];
        }
    }
    return escogido;
}

void prim() {
   U[0] = true;
   for (int v = 1; v < numero_ciudades; v++) {
       mas_cercano[v] = 0;
       menor_coste[v] = G[0][v];
   }
   int v;
   int total_cable = 0;
   for(int i = 1; i < numero_ciudades; i++) {
        v = escoger_nodo();
        total_cable += menor_coste[v];
        for (int w = 0; w < numero_ciudades; w++) {
            if (menor_coste[w] > G[v][w]) {
                menor_coste[w] = G[v][w];
                mas_cercano[w] = v;
            }
        }
        U[v] = true;
   }
   cout << total_cable << endl;
}

int main() {
    int numero_casos;
    cin >> numero_casos;
    while (numero_casos--) {
        lee_grafo();
        prim();
    }
}
