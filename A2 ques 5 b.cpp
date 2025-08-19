#include <iostream>
using namespace std;

class TriDiagonal {
private:
    int *A;
    int n;
public:
    TriDiagonal(int n) {
        this->n = n;
        A = new int[3*n - 2];
    }

    ~TriDiagonal() {
        delete[] A;
    }

    void set(int i, int j, int x) {
        if (i - j == 1)       
            A[i - 2] = x;
        else if (i == j)      
            A[(n - 1) + (i - 1)] = x;
        else if (j - i == 1)  
            A[(2*n - 1) + (i - 1)] = x;
     
    }

    int get(int i, int j) {
        if (i - j == 1)
            return A[i - 2];
        else if (i == j)
            return A[(n - 1) + (i - 1)];
        else if (j - i == 1)
            return A[(2*n - 1) + (i - 1)];
        else
            return 0;
    }

    void display() {
        cout << "Tri-Diagonal Matrix: " << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter dimension of matrix: ";
    cin >> n;

    TriDiagonal td(n);

    cout << "Enter non-zero elements (tri-diagonal only):" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (i - j == 1 || i == j || j - i == 1) {
                td.set(i, j, x);
            }
        }
    }
    return 0;
}

