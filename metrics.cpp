//
// Created by rabii on 5/5/2025.
//
#include <fstream>
#include "SortMetrics.h"

void writeCSVHeader(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "Algorithm,InputType,n,Comparisons,Swaps,CPUTime\n";
        file.close();
    }
}

void appendMetricsToCSV(const SortMetrics& metrics, const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << metrics.toCSV() << "\n";
        file.close();
    }
}
