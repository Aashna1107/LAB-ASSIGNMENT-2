#include <iostream>
using namespace std;


void duplicateTwos(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == 2) {
          
            for (int j = n - 1; j > i; j--) {
                arr[j] = arr[j - 1];
            }
          
            if (i + 1 < n) arr[i + 1] = 2;
            i++; 
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    duplicateTwos(arr, n);

    cout << "Array after duplication: ";
    printArray(arr, n);

    return 0;
}

