#include <stdio.h>

#define SIZE 8

/* Print the current contents of the array */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1)
            printf(", ");
    }
    printf("\n");
}

/* -------------------- MERGE SORT -------------------- */

void merge(int arr[], int left, int mid, int right, long *comparisons) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        (*comparisons)++;

        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right, long *comparisons) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, comparisons);
        mergeSort(arr, mid + 1, right, comparisons);
        merge(arr, left, mid, right, comparisons);
    }
}

/* Run Merge Sort and display the array after each merge pass */
void runMergeSort(int original[], int n) {
    int arr[SIZE];

    for (int i = 0; i < n; i++)
        arr[i] = original[i];

    long comparisons = 0;
    int pass = 1;

    printf("\n========== MERGE SORT ==========\n");
    printf("Initial array: ");
    printArray(arr, n);

    /*
       Bottom-up Merge Sort is used here so that the array can be
       displayed clearly after every merge pass.
    */
    for (int width = 1; width < n; width *= 2) {
        for (int left = 0; left < n; left += 2 * width) {
            int mid = left + width - 1;
            int right = left + 2 * width - 1;

            if (mid >= n - 1)
                continue;

            if (right >= n)
                right = n - 1;

            merge(arr, left, mid, right, &comparisons);
        }

        printf("After merge pass %d: ", pass++);
        printArray(arr, n);
    }

    printf("Final sorted array: ");
    printArray(arr, n);
    printf("Merge Sort comparisons: %ld\n", comparisons);
}

/* -------------------- QUICK SORT -------------------- */

/*
   Quick Sort using the last element as the pivot.
   The function prints the array after every partition.
*/
int partition(int arr[], int low, int high, long *comparisons, int *partitionNo) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        (*comparisons)++;

        if (arr[j] <= pivot) {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    (*partitionNo)++;

    printf("Partition %d (pivot = %d): ", *partitionNo, pivot);
    printArray(arr, SIZE);

    return i + 1;
}

void quickSort(int arr[], int low, int high,
               long *comparisons, int *partitionNo) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons, partitionNo);

        quickSort(arr, low, pi - 1, comparisons, partitionNo);
        quickSort(arr, pi + 1, high, comparisons, partitionNo);
    }
}

void runQuickSort(int original[], int n) {
    int arr[SIZE];

    for (int i = 0; i < n; i++)
        arr[i] = original[i];

    long comparisons = 0;
    int partitionNo = 0;

    printf("\n========== QUICK SORT ==========\n");
    printf("Initial array: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1, &comparisons, &partitionNo);

    printf("Final sorted array: ");
    printArray(arr, n);
    printf("Quick Sort partitions: %d\n", partitionNo);
    printf("Quick Sort comparisons: %ld\n", comparisons);
}

/* -------------------- MAIN -------------------- */

int main(void) {
    int data[SIZE] = {324, 125, 456, 218, 102, 389, 275, 147};

    printf("SORTING ANALYSIS OF FIXED-LENGTH IDs\n");
    printf("====================================\n");
    printf("Input: ");
    printArray(data, SIZE);

    runMergeSort(data, SIZE);
    runQuickSort(data, SIZE);

    printf("\n========== COMPLEXITY ANALYSIS ==========\n");
    printf("Merge Sort:\n");
    printf("  Time Complexity: O(n log n) in best, average and worst cases\n");
    printf("  Additional Space: O(n)\n");
    printf("  Number of merge passes: ceil(log2(n))\n");

    printf("\nQuick Sort:\n");
    printf("  Time Complexity: O(n log n) average, O(n^2) worst case\n");
    printf("  Additional Space: O(log n) average recursion stack, O(n) worst case\n");
    printf("  Number of partitions: depends on pivot choices\n");

    printf("\nConclusion:\n");
    printf("For large fixed-length IDs, Merge Sort provides predictable O(n log n)\n");
    printf("performance and is not affected by poor pivot selection. Quick Sort can\n");
    printf("also be very efficient in practice, but its worst-case time is O(n^2).\n");

    return 0;
}
