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


void addSparse(int A[MAX][3], int B[MAX][3], int C[MAX][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "Matrices cannot be added! Dimensions mismatch." << endl;
        C[0][2] = 0;
        return;
    }

    C[0][0] = A[0][0];  
    C[0][1] = A[0][1];  

    int i = 1, j = 1, k = 1;
    int t1 = A[0][2], t2 = B[0][2];

    while (i <= t1 && j <= t2) {
      
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        }
        else if (B[j][0] < A[i][0] || (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }
        else { 
            int sum = A[i][2] + B[j][2];
            if (sum != 0) {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = sum;
                k++;
            }
            i++; j++;
        }
    }

    while (i <= t1) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++; k++;
    }
    while (j <= t2) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++; k++;
    }

    C[0][2] = k - 1; }
    
    int main() {
    int A[MAX][3], B[MAX][3], C[MAX][3];

    cout << "Enter first matrix:" << endl;
    readSparse(A);

    cout << "Enter second matrix:" << endl;
    readSparse(B);

    cout << "\nFirst Matrix (Triplet Form):\n";
    displaySparse(A);

    cout << "\nSecond Matrix (Triplet Form):\n";
    displaySparse(B);

    addSparse(A, B, C);

    cout << "\nResultant Matrix After Addition (Triplet Form):\n";
    displaySparse(C);

    return 0;
}
    
    

