#include <iostream>
#include "SortMetrics.h"
#include "sort.h"
#include "FisherYates.h"
using namespace std;



int main()
{
    writeCSVHeader("../results.csv");

    int sizeOfArr[] = {100, 300, 500, 1000, 3000, 5000, 10000, 50000};
    for (int i = 0; i < 8; i++) {
        int n = sizeOfArr[i];
        int arr[n];
        for (int j = 0; j < n; j++) {      // Sorted Array
            arr[j] = j + 1;
        }
        SortMetrics metrics;

        metrics.inputType = "Sorted";
        bubbleSort(arr, n, metrics);
        appendMetricsToCSV(metrics, "../results.csv");

        metrics.inputType = "Sorted";
        insertionSort(arr, n, metrics);
        appendMetricsToCSV(metrics, "../results.csv");

        metrics.inputType = "Sorted";
        selectionSort(arr, n, metrics);
        appendMetricsToCSV(metrics, "../results.csv");

        metrics.inputType = "Sorted";
        quickSort(arr, n, metrics);
        appendMetricsToCSV(metrics, "../results.csv");

        metrics.inputType = "Sorted";
        mergeSort(arr, n, metrics);
        appendMetricsToCSV(metrics, "../results.csv");

        metrics.inputType = "Sorted";
        heapSort(arr, n, metrics);
        appendMetricsToCSV(metrics, "../results.csv");

        metrics.inputType = "Sorted";
        introSort(arr, n, metrics);
        appendMetricsToCSV(metrics, "../results.csv");

        metrics.inputType = "Sorted";
        countingSort(arr, n, metrics);
        appendMetricsToCSV(metrics, "../results.csv");

        for (int j = n; j <= 0; j--) {      // Reverse Sorted Array
            arr[j] = j + 1;
        }
        metrics.inputType = "Reverse";
        bubbleSort(arr, n, metrics);
        appendMetricsToCSV(metrics, "../results.csv");

        metrics.inputType = "Reverse";
        insertionSort(arr, n, metrics);
        appendMetricsToCSV(metrics, "../results.csv");

        metrics.inputType = "Reverse";
        selectionSort(arr, n, metrics);
        appendMetricsToCSV(metrics, "../results.csv");

        metrics.inputType = "Reverse";
        quickSort(arr, n, metrics);
        appendMetricsToCSV(metrics, "../results.csv");

        metrics.inputType = "Reverse";
        mergeSort(arr, n, metrics);
        appendMetricsToCSV(metrics, "../results.csv");

        metrics.inputType = "Reverse";
        heapSort(arr, n, metrics);
        appendMetricsToCSV(metrics, "../results.csv");

        metrics.inputType = "Reverse";
        introSort(arr, n, metrics);
        appendMetricsToCSV(metrics, "../results.csv");

        metrics.inputType = "Reverse";
        countingSort(arr, n, metrics);
        appendMetricsToCSV(metrics, "../results.csv");

        generateUniqueRandom(arr, n);   // Uses the reverse sorted array and turns it into a random array

        metrics.inputType = "Random";
        bubbleSort(arr, n, metrics);
        appendMetricsToCSV(metrics, "../results.csv");

        metrics.inputType = "Random";
        insertionSort(arr, n, metrics);
        appendMetricsToCSV(metrics, "../results.csv");

        metrics.inputType = "Random";
        selectionSort(arr, n, metrics);
        appendMetricsToCSV(metrics, "../results.csv");

        metrics.inputType = "Random";
        quickSort(arr, n, metrics);
        appendMetricsToCSV(metrics, "../results.csv");

        metrics.inputType = "Random";
        mergeSort(arr, n, metrics);
        appendMetricsToCSV(metrics, "../results.csv");

        metrics.inputType = "Random";
        heapSort(arr, n, metrics);
        appendMetricsToCSV(metrics, "../results.csv");

        metrics.inputType = "Random";
        introSort(arr, n, metrics);
        appendMetricsToCSV(metrics, "../results.csv");

        metrics.inputType = "Random";
        countingSort(arr, n, metrics);
        appendMetricsToCSV(metrics, "../results.csv");
    }

    return 0;
}
