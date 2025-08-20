#include <iostream>
using namespace std;

int countPairsWithDiff(int arr[], int n, int k) {
    int count = 0;

   for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((arr[i] - arr[j] ) == k) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    int result = countPairsWithDiff(arr, n, k);
    cout << "Total pairs with difference " << k << " = " << result << endl;

    return 0;
}

