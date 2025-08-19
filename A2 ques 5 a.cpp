#include <iostream>
using namespace std;

void setDiagonal(int diagonal[], int n, int i, int j, int x) {
    if (i == j) {
        diagonal[i - 1] = x; 
    }
}

int getDiagonal(int diagonal[], int n, int i, int j) {
    if (i == j) 
        return diagonal[i - 1];
    else 
        return 0; 
}

void displayDiagonal(int diagonal[], int n) {
    cout << "Diagonal Matrix: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                cout << diagonal[i - 1] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter dimension of matrix: ";
    cin >> n;

    int *diagonal = new int[n]; 

    cout << "Enter diagonal elements: " << endl;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        setDiagonal(diagonal, n, i, i, x);
    }

    displayDiagonal(diagonal, n);
    cout << "Element at (2,2): " << getDiagonal(diagonal, n, 2, 2) << endl;
    cout << "Element at (2,3): " << getDiagonal(diagonal, n, 2, 3) << endl;

    delete[] diagonal;
    return 0;
}

