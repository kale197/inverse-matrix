#include <stdio.h>
#include "funcs.h"

// function to calculate final inverse matrix.
void Inverzna(matrix mat, matrix adjug, fmatrix final, int dimension)
{
    float scalar = 1.00 / Determinant(mat, dimension);    
    TimesScalar(scalar, adjug, final, dimension);
    
}

int main(int argc, char const *argv[])
{
    matrix m1;
    int dim;
    matrix adj;
    fmatrix in_mx;

    
    printf("\t\tInverse Matrix Calculator\t\t\n");
    printf("\t\t-------------------------\t\t\n");
    printf("Enter matrix dimension: ");
    scanf("%d", &dim);
    InputMatrix(m1,dim);
    printf("Your matrix:\n");
    PrintMatrix(m1,dim);
    printf("Inverse matrix:\n");
    Adjugate(m1,adj,dim);
    Inverzna(m1, adj, in_mx,dim);
    PrintFMatrix(in_mx,dim);

    

    return 0;
}
