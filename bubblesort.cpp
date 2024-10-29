#include <iostream>
#include <vector>
#include <algorithm>  // For std::shuffle and std::reverse
#include <chrono>     // For timing
#include <random>     // For random number generation
using namespace std;
using namespace std::chrono;

// Bubble Sort Function
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Utility function to measure and print execution time
void measureExecutionTime(vector<int>& arr, const string& caseType) {
    vector<int> tempArr = arr;  // Copy the array to avoid modifying the original
    auto start = high_resolution_clock::now();
    bubbleSort(tempArr);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    cout << "Bubble Sort (" << caseType << " case): " << duration << " microseconds\n";
}

int main() {
    int n = 1000;  // Size of the arrays

    // Best case (already sorted array)
    vector<int> bestCase(n);
    for (int i = 0; i < n; i++) bestCase[i] = i;

    // Average case (random shuffled array)
    vector<int> avgCase = bestCase;
    random_device rd;
    mt19937 g(rd());
    shuffle(avgCase.begin(), avgCase.end(), g);

    // Worst case (sorted in descending order)
    vector<int> worstCase = bestCase;
    reverse(worstCase.begin(), worstCase.end());

    // Measure execution time for Bubble Sort on each case
    cout << "Execution Times for Bubble Sort:\n";
    measureExecutionTime(bestCase, "Best");
    measureExecutionTime(avgCase, "Average");
    measureExecutionTime(worstCase, "Worst");

    return 0;
}
