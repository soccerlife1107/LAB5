#include <stdio.h>

void bubbleSort(int arr[], int n, int *totalSwaps, char *arrayName) {
    int i, j, temp;
    int swaps[101] = {0}; 
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps[temp]++;
                swaps[arr[j]]++;
                (*totalSwaps)++;
            }
        }
    }

    printf("%s bubble sort:\n", arrayName);
    for (i = 0; i < 101; i++) {
        if (swaps[i] > 0) {
            printf("%d: %d\n", i, swaps[i]);
        }
    }
    printf("total: %d\n\n", *totalSwaps);
}

void selectionSort(int arr[], int n, int *totalSwaps, char *arrayName) {
    int i, j, minIndex, temp;
    int swaps[101] = {0}; // Initialize all values to 0

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps[temp]++; // Increment the swap count for the value
            (*totalSwaps)++; // Increment the total swap count
        }
    }

    printf("%s selection sort:\n", arrayName);
    for (i = 0; i < 101; i++) {
        if (swaps[i] > 0) {
            printf("%d: %d\n", i, swaps[i]);
        }
    }
    printf("\n");
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);
    int totalSwaps1 = 0, totalSwaps2 = 0;

    bubbleSort(array1, n1, &totalSwaps1, "array1");
    printf("\n");
    bubbleSort(array2, n2, &totalSwaps2, "array2");
    printf("\n");

    totalSwaps1 = 0;
    totalSwaps2 = 0;

    selectionSort(array1, n1, &totalSwaps1, "array1");
    printf("\n");
    selectionSort(array2, n2, &totalSwaps2, "array2");
    printf("\n");

    return 0;
}
