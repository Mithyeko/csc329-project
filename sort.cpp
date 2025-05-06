//
// Created by rabii on 5/1/2025.
//
#include <filesystem>
#include <cmath> // for log2
#include <chrono>
#include <iostream>

#include "SortMetrics.h"

using namespace std;
using namespace std::chrono;

void insertionSort(int arr[], int n, SortMetrics& metrics) {
    metrics.algorithm = "Insertion";
    metrics.n = n;

    auto start = high_resolution_clock::now();

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            metrics.comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                metrics.swaps++;
            } else {
                break;
            }
            --j;
        }
        arr[j + 1] = key;
    }

    auto end = high_resolution_clock::now();
    metrics.durationMicroseconds = duration_cast<microseconds>(end - start).count();

    appendMetricsToCSV(metrics, "results.csv");
}

void selectionSort(int arr[], int n, SortMetrics& metrics) {
    metrics.algorithm = "Selection";
    metrics.n = n;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            metrics.comparisons++;
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
            metrics.swaps++;
        }
    }

    auto end = high_resolution_clock::now();
    metrics.durationMicroseconds = duration_cast<microseconds>(end - start).count();

    appendMetricsToCSV(metrics, "results.csv");
}

void bubbleSort(int arr[], int n, SortMetrics& metrics) {
    metrics.algorithm = "Bubble";
    metrics.n = n;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            metrics.comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                metrics.swaps++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    auto end = high_resolution_clock::now();
    metrics.durationMicroseconds = duration_cast<microseconds>(end - start).count();

    appendMetricsToCSV(metrics, "results.csv");
}
void merge(int arr[], int l, int m, int r, SortMetrics& metrics) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        metrics.comparisons++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
        metrics.swaps++;
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSortHelper(int arr[], int l, int r, SortMetrics& metrics) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortHelper(arr, l, m, metrics);
        mergeSortHelper(arr, m + 1, r, metrics);
        merge(arr, l, m, r, metrics);
    }
}

void mergeSort(int arr[], int n, SortMetrics& metrics) {
    metrics.algorithm = "Merge";
    metrics.n = n;

    auto start = chrono::high_resolution_clock::now();
    mergeSortHelper(arr, 0, n - 1, metrics);
    auto end = std::chrono::high_resolution_clock::now();

    metrics.durationMicroseconds = std::chrono::duration_cast<chrono::microseconds>(end - start).count();
    appendMetricsToCSV(metrics, "results.csv");
}
int partition(int arr[], int low, int high, SortMetrics& metrics) {
    int mid = low + (high - low) / 2;
    int pivot = arr[mid];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        metrics.comparisons++;
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
            metrics.swaps++;
        }
    }
    std::swap(arr[i + 1], arr[high]);
    metrics.swaps++;
    return i + 1;
}

void quickSortHelper(int arr[], int low, int high, SortMetrics& metrics) {
    if (low < high) {
        int pi = partition(arr, low, high, metrics);
        quickSortHelper(arr, low, pi - 1, metrics);
        quickSortHelper(arr, pi + 1, high, metrics);
    }
}

void quickSort(int arr[], int n, SortMetrics& metrics) {
    metrics.algorithm = "Quick";
    metrics.n = n;

    auto start = std::chrono::high_resolution_clock::now();
    quickSortHelper(arr, 0, n - 1, metrics);
    auto end = std::chrono::high_resolution_clock::now();

    metrics.durationMicroseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    appendMetricsToCSV(metrics, "results.csv");
}
void heapify(int arr[], int n, int i, SortMetrics& metrics) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n) {
        metrics.comparisons++;
        if (arr[l] > arr[largest])
            largest = l;
    }

    if (r < n) {
        metrics.comparisons++;
        if (arr[r] > arr[largest])
            largest = r;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        metrics.swaps++;
        heapify(arr, n, largest, metrics);
    }
}

void heapSort(int arr[], int n, SortMetrics& metrics) {
    metrics.algorithm = "Heap";
    metrics.n = n;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, metrics);

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        metrics.swaps++;
        heapify(arr, i, 0, metrics);
    }

    auto end = std::chrono::high_resolution_clock::now();
    metrics.durationMicroseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    appendMetricsToCSV(metrics, "results.csv");
}
void introsortUtil(int arr[], int low, int high, int depthLimit, SortMetrics& metrics) {
    int size = high - low + 1;

    if (size <= 16) {
        insertionSort(arr + low, size, metrics);
        return;
    }

    if (depthLimit == 0) {
        heapSort(arr + low, size, metrics);
        return;
    }

    int pivotIndex = partition(arr, low, high, metrics);
    introsortUtil(arr, low, pivotIndex - 1, depthLimit - 1, metrics);
    introsortUtil(arr, pivotIndex + 1, high, depthLimit - 1, metrics);
}

void introSort(int arr[], int n, SortMetrics& metrics) {
    metrics.algorithm = "Intro";
    metrics.n = n;
    auto start = high_resolution_clock::now();

    int depthLimit = 2 * log2(n);
    introsortUtil(arr, 0, n - 1, depthLimit, metrics);

    auto end = high_resolution_clock::now();
    metrics.durationMicroseconds = duration_cast<microseconds>(end - start).count();
    appendMetricsToCSV(metrics, "results.csv");
}
void countingSort(int arr[], int n, SortMetrics& metrics) {
    metrics.algorithm = "Counting";
    metrics.n = n;

    auto start = high_resolution_clock::now();

    // Find the maximum value to size the count array
    int maxVal = arr[0];
    for (int i = 1; i < n; ++i) {
        metrics.comparisons++;
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    int* count = new int[maxVal + 1]();  // Initialize to 0
    int* output = new int[n];

    // Count occurrences
    for (int i = 0; i < n; ++i) {
        count[arr[i]]++;
    }

    // Cumulative count
    for (int i = 1; i <= maxVal; ++i) {
        count[i] += count[i - 1];
    }

    // Build output array (stable)
    for (int i = n - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
        metrics.swaps++;  // We treat writes into output as swaps
    }

    // Copy back to original array
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }

    delete[] count;
    delete[] output;

    auto end = high_resolution_clock::now();
    metrics.durationMicroseconds = duration_cast<microseconds>(end - start).count();

    appendMetricsToCSV(metrics, "results.csv");
}
