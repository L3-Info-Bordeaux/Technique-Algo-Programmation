#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

typedef struct {
    double x;
    double y;
} point;

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

    double dist = value(V, n, P);
    
}

int main(int argc, const char *argv[]) {

    return EXIT_SUCCESS;
}