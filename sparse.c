#include <stdio.h>

#define MAX_TERMS 100

// Structure to store individual non-zero elements
typedef struct {
    int row;
    int col;
    int value;
} Element;

// Structure to represent the sparse matrix
typedef struct {
    int rows;
    int cols;
    int num_non_zero;
    Element data[MAX_TERMS];
} SparseMatrix;

// Function to convert a dense 2D matrix into a sparse matrix
void createSparseMatrix(int mat[4][4], int r, int c, SparseMatrix *s) {
    s->rows = r;
    s->cols = c;
    s->num_non_zero = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] != 0) {
                s->data[s->num_non_zero].row = i;
                s->data[s->num_non_zero].col = j;
                s->data[s->num_non_zero].value = mat[i][j];
                s->num_non_zero++;
            }
        }
    }
}

// Function to print the sparse matrix in triplet form
void printSparseMatrix(SparseMatrix s) {
    printf("Matrix Dimensions: %d x %d\n", s.rows, s.cols);
    printf("Total Non-Zero Elements: %d\n\n", s.num_non_zero);
    printf("Row\tCol\tValue\n");
    printf("---------------------\n");
    for (int i = 0; i < s.num_non_zero; i++) {
        printf("%d\t%d\t%d\n", s.data[i].row, s.data[i].col, s.data[i].value);
    }
}

int main() {
    // A sample 4x4 matrix filled mostly with zeros (12 zeros, 4 non-zeros)
    int denseMatrix[4][4] = {
        {0, 0, 3, 0},
        {0, 4, 0, 0},
        {0, 0, 0, 5},
        {6, 0, 0, 0}
    };

    SparseMatrix sparse;
    createSparseMatrix(denseMatrix, 4, 4, &sparse);

    printSparseMatrix(sparse);

    return 0;
}