//
// Created by rabii on 5/5/2025.
//

#ifndef SORT_H
#define SORT_H
#include "SortMetrics.h"

void bubbleSort(int arr[], int n, SortMetrics& metrics);
void insertionSort(int arr[], int n, SortMetrics& metrics);
void selectionSort(int arr[], int n, SortMetrics& metrics);
void quickSort(int arr[], int n, SortMetrics& metrics);
void mergeSort(int arr[], int n, SortMetrics& metrics);
void heapSort(int arr[], int n, SortMetrics& metrics);
void introSort(int arr[], int n, SortMetrics& metrics);
void countingSort(int arr[], int n, SortMetrics& metrics);

#endif //SORT_H
