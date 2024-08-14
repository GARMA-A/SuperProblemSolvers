#include <iostream>
using namespace std;

// Function to partition the array
int partition(int arr[], int low, int high) 
{
    int pivot = arr[high];
    int i = low - 1;
    
    int j = low;
    while (j <= high - 1) {
        if (arr[j] < pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        j++;
    }

    // Swap arr[i + 1] and arr[high] (or pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

// Function to implement Quick Sort using while loop
void quickSort(int arr[], int low, int high) //O(n*log(n))
{
    while (low < high) {
        int pi = partition(arr, low, high);

        // Recur for the left side
        quickSort(arr, low, pi - 1);
        
        // Update the low index toX sort the right side in the next iteration
        low = pi + 1;
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    int i = 0;
    while (i < size) {
        cout << arr[i] << " ";
        i++;
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}
