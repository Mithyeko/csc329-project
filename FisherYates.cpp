//
// Created by rabii on 5/5/2025.
//
#include <algorithm> // for std::swap
#include <random>

void generateUniqueRandom(int arr[], int n) {
    // Fill with 0 to n-1
    for (int i = 0; i < n; ++i)
        arr[i] = i;

    // Shuffle using Fisher-Yates
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = n - 1; i > 0; --i) {
        std::uniform_int_distribution<> dist(0, i);
        int j = dist(gen);
        std::swap(arr[i], arr[j]);
    }
}
