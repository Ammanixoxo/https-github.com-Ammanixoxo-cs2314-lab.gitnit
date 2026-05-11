#include <stdio.h>

static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Q1: Bubble Sort
void bubbleSort(int arr[], int size) {
    if (size <= 1) {
        return;
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Q2: Merge Sort
static void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftArr[n1];
    int rightArr[n2];

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }
    while (i < n1) {
        arr[k++] = leftArr[i++];
    }
    while (j < n2) {
        arr[k++] = rightArr[j++];
    }
}

static void mergeSortHelper(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSortHelper(arr, left, mid);
    mergeSortHelper(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void mergeSort(int arr[], int size) {
    if (size <= 1) {
        return;
    }
    mergeSortHelper(arr, 0, size - 1);
}

// Q3: Quick Sort
static int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

static void quickSortHelper(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSortHelper(arr, low, pivotIndex - 1);
        quickSortHelper(arr, pivotIndex + 1, high);
    }
}

void quickSort(int arr[], int size) {
    if (size <= 1) {
        return;
    }
    quickSortHelper(arr, 0, size - 1);
}

// Q4: Insertion Sort
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Q5: Selection Sort
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

// Q7: Merge Sort with Insertion Sort on small subarrays
static void mergeInsertionSortHelper(int arr[], int left, int right, int k) {
    if (left >= right) {
        return;
    }

    int size = right - left + 1;
    if (size <= k) {
        for (int i = left + 1; i <= right; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= left && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        return;
    }

    int mid = left + (right - left) / 2;
    mergeInsertionSortHelper(arr, left, mid, k);
    mergeInsertionSortHelper(arr, mid + 1, right, k);
    merge(arr, left, mid, right);
}

void mergeInsertionSort(int arr[], int size, int k) {
    if (size <= 1) {
        return;
    }
    mergeInsertionSortHelper(arr, 0, size - 1, k);
}

static void printArray(const char *label, int arr[], int size) {
    printf("%s", label);
    for (int i = 0; i < size; i++) {
        printf("%s%d", (i == 0 ? "" : " "), arr[i]);
    }
    printf("\n");
}

int main(void) {
    int q1[] = {5, 1, 4, 2, 8};
    bubbleSort(q1, 5);
    printArray("Q1 sorted: ", q1, 5);

    int q2[] = {38, 27, 43, 3, 9, 82, 10};
    mergeSort(q2, 7);
    printArray("Q2 sorted: ", q2, 7);

    int q3[] = {10, 7, 8, 9, 1, 5};
    quickSort(q3, 6);
    printArray("Q3 sorted: ", q3, 6);

    int q4[] = {5, 1, 4, 2, 8};
    insertionSort(q4, 5);
    printArray("Q4 sorted: ", q4, 5);

    int q5[] = {5, 1, 4, 2, 8};
    selectionSort(q5, 5);
    printArray("Q5 sorted: ", q5, 5);

    int q7[] = {39, 9, 81, 45, 90, 27, 72, 18};
    mergeInsertionSort(q7, 8, 4);
    printArray("Q7 sorted: ", q7, 8);

    printf("Q6: Insertion sort is faster than selection sort on average by a constant factor because it can stop shifting early and performs fewer swaps when the array is partially sorted.\n");
    printf("Q7 complexity: insertion sort on n/k subarrays of size k is Theta(nk); merge of all subarrays is Theta(n log(n/k)).\n");

    return 0;
}
