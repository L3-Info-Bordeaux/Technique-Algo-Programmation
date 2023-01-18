#include <assert.h>

#include "tools.h"

//
//  TSP - BRUTE-FORCE
//
// -> la structure "point" est définie dans "tools.h"
// -> tsp_main peut être testé dès les 3 premières fonctions codées
//

double dist(point A, point B) {
    return sqrt(
        pow(B.x - A.x, 2) +
        pow(B.y - A.y, 2)
    );
}

double value(point *V, int n, int *P) {
    double distance = 0;
    for (int i = 0; i < n - 1; i++) {
        distance += dist(V[P[i]], V[P[i + 1]]);
    }
    distance += dist(V[P[n - 1]], V[0]);
    return distance;
}

double tsp_brute_force(point *V, int n, int *Q) {
    int *P = malloc(sizeof(int) * n);
    assert(P != NULL);

    for (int i = 0; i < n; i++) { P[i] = i; }

    double dist = DBL_MAX;
    do {
        double new_d = value(V, n, P);
        if (new_d < dist) {
            dist = new_d;
            Q = memcpy(Q, P, n * sizeof(int));
        }
    } while (NextPermutation(P, n));
    return dist;
}

void MaxPermutation(int *P, int n, int k) {
  ;
  ;
  ;
  return;
}

double value_opt(point *V, int n, int *P, double w) {
    double distance = 0;
    for (int i = 0; i < n - 1; i++) {
        distance += dist(V[P[i]], V[P[i + 1]]);
        if (distance + dist(V[P[i]], V[0]) > w) { return -i; }
    }
    distance += dist(V[P[n - 1]], V[0]);
    return distance < w ? distance : -n;
}

double tsp_brute_force_opt(point *V, int n, int *Q) {
    int *P = malloc(sizeof(int) * n);
    assert(P != NULL);

    for (int i = 0; i < n; i++) { P[i] = i; }

    double dist = DBL_MAX;
    do {
        double new_d = value_opt(V, n, P, dist);
        if (new_d < dist) {
            dist = new_d;
            Q = memcpy(Q, P, n * sizeof(int));
        }
    } while (NextPermutation(P + 1, n - 1));
    return dist;
}
