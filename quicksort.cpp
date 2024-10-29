#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void measureExecutionTime(vector<int>& arr, const string& caseType) {
    vector<int> tempArr = arr;
    auto start = high_resolution_clock::now();
    quickSort(tempArr, 0, tempArr.size() - 1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    cout << "Quick Sort (" << caseType << " case): " << duration << " microseconds\n";
}

int main() {
    int n = 1000;
    
    // Best case: already sorted array
    vector<int> bestCase(n);
    for (int i = 0; i < n; i++) bestCase[i] = i;

    // Average case: random shuffled array
    vector<int> avgCase = bestCase;
    random_device rd;
    mt19937 g(rd());
    shuffle(avgCase.begin(), avgCase.end(), g);

    // Worst case: sorted in descending order
    vector<int> worstCase = bestCase;
    reverse(worstCase.begin(), worstCase.end());

    cout << "Execution Times for Quick Sort:\n";
    measureExecutionTime(bestCase, "Best");
    measureExecutionTime(avgCase, "Average");
    measureExecutionTime(worstCase, "Worst");

    return 0;
}
