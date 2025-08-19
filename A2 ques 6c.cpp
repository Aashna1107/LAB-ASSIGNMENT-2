#include <iostream>
using namespace std;

#define MAX 100

void readSparse(int triplet[MAX][3]) {
    int rows, cols, nonZero;
    cout << "Enter rows, cols and number of non-zero elements: ";
    cin >> rows >> cols >> nonZero;

    triplet[0][0] = rows;
    triplet[0][1] = cols;
    triplet[0][2] = nonZero;

    cout << "Enter row, col and value for each non-zero element:" << endl;
    for (int i = 1; i <= nonZero; i++) {
        cin >> triplet[i][0] >> triplet[i][1] >> triplet[i][2];
    }
}

void displaySparse(int triplet[MAX][3]) {
    int nonZero = triplet[0][2];
    cout << "Row Col Val" << endl;
    for (int i = 0; i <= nonZero; i++) {
        cout << triplet[i][0] << "   "
             << triplet[i][1] << "   "
             << triplet[i][2] << endl;
    }
}

void multiplySparse(int A[MAX][3], int B[MAX][3], int C[MAX][3]) {
    if (A[0][1] != B[0][0]) {
        cout << "Matrix multiplication not possible!" << endl;
        C[0][2] = 0;
        return;
    }

    int rows = A[0][0];
    int cols = B[0][1];
    int temp[rows][cols]; 

   
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            temp[i][j] = 0;

    int t1 = A[0][2], t2 = B[0][2];

    
    for (int i = 1; i <= t1; i++) {
        for (int j = 1; j <= t2; j++) {
            if (A[i][1] == B[j][0]) { 
                temp[A[i][0]][B[j][1]] += A[i][2] * B[j][2];
            }
        }
    }

    int k = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (temp[i][j] != 0) {
                C[k][0] = i;
                C[k][1] = j;
                C[k][2] = temp[i][j];
                k++;
            }
        }
    }

    C[0][0] = rows;
    C[0][1] = cols;
    C[0][2] = k - 1; 
}

int main() {
    int A[MAX][3], B[MAX][3], C[MAX][3];

    cout << "Enter first matrix (A):" << endl;
    readSparse(A);

    cout << "Enter second matrix (B):" << endl;
    readSparse(B);

    cout << "\nFirst Matrix (Triplet Form):\n";
    displaySparse(A);

    cout << "\nSecond Matrix (Triplet Form):\n";
    displaySparse(B);

    multiplySparse(A, B, C);

    cout << "\nResultant Matrix After Multiplication (Triplet Form):\n";
    displaySparse(C);

    return 0;
}

