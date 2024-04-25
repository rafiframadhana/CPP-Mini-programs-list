#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
  int i, j, minIndex, temp;
  for (i = 0; i < n-1; i++) {
    minIndex = i;
    for (j = i+1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    temp = arr[minIndex];
    arr[minIndex] = arr[i];
    arr[i] = temp;
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  int n;
  cout << "Enter the number of elements: ";
  cin >> n;
  int arr[n];
  cout << "Enter the elements: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "Before sorting: ";
  printArray(arr, n);

  selectionSort(arr, n);

  cout << "After sorting: ";
  printArray(arr, n);

  return 0;
}
