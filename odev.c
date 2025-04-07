
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define lineA 2
#define pillarA 3
#define lineB 3
#define pillarB 2

int A[lineA][pillarA];
int B[lineB][pillarB];
int C[lineA][pillarA];

// Matrisleri rastgele değerlerle doldur
void RandomGenerator() {
    for (int i = 0; i < lineA; i++)
        for (int j = 0; j < pillarA; j++)
            A[i][j] = rand() % 100 + 1;

    for (int i = 0; i < lineB; i++)
        for (int j = 0; j < pillarB; j++)
            B[i][j] = rand() % 100 + 1;
}

// Matris yazdırıcı
void PrintMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%4d ", matrix[i][j]);
        puts("");
    }
    puts("");
}

// Matris çarpımı: C = A x B
void MultiMatrix() {
    for (int i = 0; i < lineA; i++) {
        for (int j = 0; j < pillarB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < pillarA; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}

int main() {
    srand(time(NULL));

    RandomGenerator();
    MultiMatrix();

    printf("A Matrisi (2x3):\n");
    PrintMatrix(lineA, pillarA, A);

    printf("B Matrisi (3x2):\n");
    PrintMatrix(lineB, pillarB, B);

    printf("C Matrisi = A x B (2x2):\n");
    PrintMatrix(lineA, pillarB, C);

    printf("Toplama islemi yapilamaz, boyutlar uyusmuyor.\n");

    return 0;
}