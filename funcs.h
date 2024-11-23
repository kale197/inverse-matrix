#include <stdio.h>

typedef int matrix[10][10];
typedef float fmatrix[10][10]; // datatype for matrix with floating-point elements

//function to input square matrix
void InputMatrix(matrix mat, int dimension)
{
    int i, j;
    for ( i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            printf("Enter element %d, %d: ",i+1,j+1);
            scanf("%d",&mat[i][j]);
        }    
    }
    
}

//function to print square matrix
void PrintMatrix(matrix mat, int dimension)
{
    int i, j;
    for ( i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n\n");    
    }
}

//function to determine the minor of the matrix 'mat', row and col are to be eliminated.
void FindMinor(matrix mat, matrix temp, int row, int col, int dimension){

    //initialize counters
    int i=0, j=0;
    
    for(int r = 0; r < dimension; r++) // going through 'mat'
        for (int k = 0; k < dimension; k++)
        {
            //checking if the current counters are the ones to be eliminated. If so, they're skipped
            if (r != row && k != col)
            {
                //j needs to be incremented in order to go to next row, otherwise it will fill in the 1st row only
                temp[i][j++]= mat[r][k];

                // checking if loop got to the end of the matrix. If so, reset the column counter, head to next row
                if (j == dimension-1) 
                {
                    j=0;
                    i++;
                }
            }
        }
}
//Recursive function to calculate the determinant (square matrix)
int Determinant(matrix mat, int dimension)
{    
    int result=0;

    if (dimension == 1) return mat[0][0]; //base case for 1x1 matrix

    if (dimension == 2) //base case for 2x2 matrix (or minor)
    {
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }

    matrix temp; //this is where the minor elements will be stored

    int sign = 1;

    for (int kol = 0; kol < dimension; kol++)
    {
        //find minor of mat[0][kol]
        FindMinor(mat, temp, 0, kol, dimension);

        //recursive call 
        result += sign * mat[0][kol] * Determinant(temp, dimension-1);

        sign = -sign;
    }
    
    return result;   
}

// Formatted output of the float matrix
void PrintFMatrix(fmatrix fmat, int dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            printf("%.2f\t",fmat[i][j]);
        }

        printf("\n\n");
    }
    
}

//function that multiplies integer elements with scalar and places it into float matrix.
void TimesScalar(float scal, matrix mat, fmatrix fmat, int dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            fmat[i][j] = scal * mat[i][j];
        }   
    }
}

// function that calculates adjugate matrix which will be multiplied with the determinant.
void Adjugate(matrix mat, matrix result, int dimension)
{
    matrix temp;
    int sign;

    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            FindMinor(mat, temp, i,j,dimension);

            if ((i+j) %2 == 0) sign = 1; else sign=-1;

            result[j][i] = sign * Determinant(temp, dimension-1);
        }  
    }
}
