# Inverse Matrix Calculator

- Written in C
- User inputs an `int` square matrix ($n \times n$)
- The script calculates:
    1. the *determinant*
    2. the *adjugate matrix*
    3. the *cofactors* for the *adjugate matrix*
    4. the *minors* for the *cofactors*
- Output is a formatted, `float` inverse matrix. 
## Notable Functions

### `FindMinor`
This function calculates the minor of a matrix by eliminating a specified row and column.

```c
// Function to determine the minor of the matrix 'mat'
// 'row' and 'col' are to be eliminated.
void FindMinor(matrix mat, matrix temp, int row, int col, int dimension) {
    // Initialize counters
    int i = 0, j = 0;

    for (int r = 0; r < dimension; r++) { // Traverse 'mat'
        for (int k = 0; k < dimension; k++) {
            // Skip the specified row and column
            if (r != row && k != col) {
                temp[i][j++] = mat[r][k]; // Assign value to temp

                // Move to the next row when the column limit is reached
                if (j == dimension - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
```
### `Determinant`
A recursive function to compute the determinant of a square matrix. It handles base cases for 1x1 and 2x2 matrices.

```c
// Recursive function to calculate the determinant of a square matrix
int Determinant(matrix mat, int dimension) {
    int result = 0;

    // Base case for 1x1 matrix
    if (dimension == 1) return mat[0][0];

    // Base case for 2x2 matrix
    if (dimension == 2) {
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }

    matrix temp; // Temporary matrix to store minors
    int sign = 1;

    for (int kol = 0; kol < dimension; kol++) {
        // Find minor of mat[0][kol]
        FindMinor(mat, temp, 0, kol, dimension);

        // Recursive call
        result += sign * mat[0][kol] * Determinant(temp, dimension - 1);

        // Alternate sign for cofactor expansion
        sign = -sign;
    }

    return result;
}
```
### `Adjugate`
Calculates the adjugate (or adjoint) of a matrix, which will be multiplied by the determinant to compute the inverse.

```c
// Function to calculate the adjugate matrix
void Adjugate(matrix mat, matrix result, int dimension) {
    matrix temp;
    int sign;

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            // Calculate the minor of the element at (i, j)
            FindMinor(mat, temp, i, j, dimension);

            // Determine the sign based on position
            sign = ((i + j) % 2 == 0) ? 1 : -1;

            // Assign cofactor to the transposed position
            result[j][i] = sign * Determinant(temp, dimension - 1);
        }
    }
}

```
### `Inverse`
Calculates the final inverse of a matrix using its adjugate and determinant.

```c
// Function to calculate the inverse matrix
void Inverse(matrix mat, matrix adjug, fmatrix final, int dimension) {
    float scalar = 1.00 / Determinant(mat, dimension);    
    TimesScalar(scalar, adjug, final, dimension);
}
```
## Timeline
#### Oct 9 2024
- Final touches
#### Oct 1 2024 
- Added the `Adjugate` function
- Testing calculation accuracy
#### Sept 22 2024
- Added header file
- Added the `Transpose` function
#### Sept 18 2024 - Project initiated

