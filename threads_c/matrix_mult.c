#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 4

int matA[MAX][MAX];
int matB[MAX][MAX];
int matC[MAX][MAX];

void* multiplyRow(void* arg) {
    int r = *((int*)arg); // get row index
    for (int c = 0; c < MAX; c++) {
        matC[r][c] = 0;
        for (int k = 0; k < MAX; k++) {
            matC[r][c] += matA[r][k] * matB[k][c];
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX];
    int rows[MAX];

    srand(time(NULL)); // Random seed

    // Generate random matrices
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            matA[i][j] = rand() % 10;
            matB[i][j] = rand() % 10;
        }
    }

    // Display Matrix A
    printf("Matrix A:\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d ", matA[i][j]);
        }
        printf("\n");
    }

    // Display Matrix B
    printf("Matrix B:\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d ", matB[i][j]);
        }
        printf("\n");
    }

    // Create threads
    for (int i = 0; i < MAX; i++) {
        rows[i] = i;
        pthread_create(&threads[i], NULL, multiplyRow, &rows[i]);
    }

    // Join threads
    for (int i = 0; i < MAX; i++) {
        pthread_join(threads[i], NULL);
    }

    // Display Result Matrix
    printf("Matrix C (Result of A x B):\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d ", matC[i][j]);
        }
        printf("\n");
    }

    return 0;
}
