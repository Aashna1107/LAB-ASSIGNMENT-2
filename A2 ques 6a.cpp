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
void transposeSparse(int triplet[MAX][3], int trans[MAX][3]) {
    int rows = triplet[0][0];
    int cols = triplet[0][1];
    int nonZero = triplet[0][2];

    trans[0][0] = cols;
    trans[0][1] = rows;
    trans[0][2] = nonZero;

    int k = 1;
    
    for (int c = 0; c < cols; c++) {
        for (int i = 1; i <= nonZero; i++) {
            if (triplet[i][1] == c) {
                trans[k][0] = triplet[i][1];
                trans[k][1] = triplet[i][0];
                trans[k][2] = triplet[i][2];
                k++;
            }
        }
    }
}

int main() {
    int triplet[MAX][3], trans[MAX][3];

    readSparse(triplet);

    cout << "\nOriginal Sparse Matrix (Triplet Form):\n";
    displaySparse(triplet);

    transposeSparse(triplet, trans);

    cout << "\nTranspose Sparse Matrix (Triplet Form):\n";
    displaySparse(trans);

    return 0;
}

