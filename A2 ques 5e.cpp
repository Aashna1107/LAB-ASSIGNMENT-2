#include <iostream>
using namespace std;
void set(int A[], int n, int i, int j, int x) {
    if (i >= j) {
        int index = (i*(i-1))/2 + (j-1);
        A[index] = x;
    }
}
int get(int A[], int n, int i, int j) {
    if (i >= j) {
        int index = (i*(i-1))/2 + (j-1);
        return A[index];
    } else {
        
        int index = (j*(j-1))/2 + (i-1);
        return A[index];
    }
}
void display(int A[], int n) {
    cout << "Symmetric Matrix:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << get(A, n, i, j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter dimension of matrix: ";
    cin >> n;

    int size = n*(n+1)/2; 
    int *A = new int[size];

    cout << "Enter matrix elements (row-wise):" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            set(A, n, i, j, x); 
        }
    }

    display(A, n);

    delete[] A;
    return 0;
}

