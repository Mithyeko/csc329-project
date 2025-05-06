//
// Created by rabii on 5/1/2025.
//
#ifndef SORTMETRICS_H
#define SORTMETRICS_H
#include <string>
#include <fstream>
using namespace std;

struct SortMetrics {
    string algorithm;
    string inputType;
    int n = 0;
    long long comparisons = 0;
    long long swaps = 0;
    long long durationMicroseconds = 0;

    string toCSV() const {
        return algorithm + "," + inputType + "," +
               to_string(n) + "," +
               to_string(comparisons) + "," +
               to_string(swaps) + "," +
               to_string(durationMicroseconds);
    }
};

void appendMetricsToCSV(const SortMetrics& metrics, const std::string& filename);
void writeCSVHeader(const std::string& filename);
#endif //SORTMETRICS_H
