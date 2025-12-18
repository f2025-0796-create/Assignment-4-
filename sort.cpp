#include<iostream>
using namespace std;

void sortMatrix(int arr[][100], int n) {
    int temp[10000];
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[count++] = arr[i][j];
        }
    }
    
    int size = n * n;
    
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                // Swap
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }
    
    count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = temp[count++];
        }
    }
}

void printMatrix(int arr[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the order of square matrix: ";
    cin >> n;
    
    int arr[100][100];
    
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    cout << "\nOriginal Matrix:\n";
    printMatrix(arr, n);
    
    sortMatrix(arr, n);
    
    cout << "\nSorted Matrix:\n";
    printMatrix(arr, n);
    
    return 0;
}
