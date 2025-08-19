#include <iostream>

using namespace std;

int countDistinct(int arr[], int n) {
    unordered_set<int> s; 
    for (int i = 0; i < n; i++) {
        s.insert(arr[i]);
    }
    return s.size(); 
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int result = countDistinct(arr, n);
    cout << "Total number of distinct elements = " << result << endl;

    return 0;
}

