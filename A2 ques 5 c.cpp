#include <iostream>
using namespace std;

class LowerTriangular {
private:
    int *A; 
    int n;
public:
    LowerTriangular(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
    }

    ~LowerTriangular() {
        delete[] A;
    }

    void set(int i, int j, int x) {
        if (i >= j) {
            int index = (i*(i-1))/2 + (j-1);
            A[index] = x;
        }
    }

   
    int get(int i, int j) {
        if (i >= j) {
            int index = (i*(i-1))/2 + (j-1);
            return A[index];
        }
        else
            return 0;
    }

    void display() {
        cout << "Lower Triangular Matrix:" << endl;
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

    LowerTriangular lt(n);

    cout << "Enter all matrix elements (row-wise): " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            lt.set(i, j, x);
        }
    }
    
     lt.display();

    return 0;
}

