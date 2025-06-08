#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define T 2   // Taille des matrices
#define N 10  // Nombre de termes dans la somme

// Calcule la factorielle d'un entier
double factorial(int n) {
    if (n == 0) return 1.0;
    double result = 1.0;
    for (int i = 1; i <= n; i++)
        result *= i;
    return result;
}

// Multiplie deux matrices de taille T x T
void mat_mult(double A[T][T], double B[T][T], double result[T][T]) {
    double temp[T][T] = {0};
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            for (int k = 0; k < T; k++) {
                temp[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    // Copie dans result
    for (int i = 0; i < T; i++)
        for (int j = 0; j < T; j++)
            result[i][j] = temp[i][j];
}

// Calcule A^n pour une matrice carrée A
void mat_power(double A[T][T], int power, double result[T][T]) {
    // Initialise result à l'identité
    for (int i = 0; i < T; i++)
        for (int j = 0; j < T; j++)
            result[i][j] = (i == j) ? 1.0 : 0.0;

    double temp[T][T];
    for (int p = 0; p < power; p++) {
        mat_mult(result, A, temp);
        for (int i = 0; i < T; i++)
            for (int j = 0; j < T; j++)
                result[i][j] = temp[i][j];
    }
}

// Fonction Identite
void Identite(double A[T][T], double Somme[T][T]) {
    // Initialise la somme à zéro
    for (int i = 0; i < T; i++)
        for (int j = 0; j < T; j++)
            Somme[i][j] = 0.0;

    double temp[T][T];

    for (int i = 0; i < N; i++) {
        double pi = factorial(i);
        for (int j = 0; j < N; j++) {
            double pj = factorial(j);
            double coeff = pow(-1.0, j) / (pi * pj);
            mat_power(A, i + j, temp);
            for (int x = 0; x < T; x++)
                for (int y = 0; y < T; y++)
                    Somme[x][y] += coeff * temp[x][y];
        }
    }
}

// Affiche une matrice
void print_matrix(double M[T][T]) {
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            printf("%8.4f ", M[i][j]);
        }
        printf("\n");
    }
}

int main() {
    double A[T][T] = {
        {0, 1},
        {0.125, 0.25}
    };

    double S[T][T];
    Identite(A, S);

    printf("Resultat de la somme:\n");
    print_matrix(S);

    return 0;
}
