#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void measureExecutionTime(vector<int>& arr, const string& caseType) {
    vector<int> tempArr = arr;
    auto start = high_resolution_clock::now();
    selectionSort(tempArr);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    cout << "Selection Sort (" << caseType << " case): " << duration << " microseconds\n";
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

    cout << "Execution Times for Selection Sort:\n";
    measureExecutionTime(bestCase, "Best");
    measureExecutionTime(avgCase, "Average");
    measureExecutionTime(worstCase, "Worst");

    return 0;
}
