#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j){
        do { i++; } while(i <= high && arr[i] <= pivot);
        do { j--; } while(arr[j] > pivot);

        if(i < j)
            swap(&arr[i], &arr[j]);
    }

    swap(&arr[low], &arr[j]);
    return j;
}

void quicksort(int arr[], int low, int high){
    if(low < high){
        int k = partition(arr, low, high);
        quicksort(arr, low, k-1);
        quicksort(arr, k + 1, high);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));


    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }

    clock_t start, end;

    start = clock();

    quicksort(arr, 0, n);

    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken to sort %d elements: %f seconds\n", n, time_taken);

    free(arr);
    return 0;
}
