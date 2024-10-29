#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

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

void measureTime(vector<int>& arr, const string& caseType) {
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(arr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Bubble Sort (" << caseType << " case): " << duration.count() << " seconds\n";
}

int main() {
    int n = 10000;
    vector<int> bestCase(n), avgCase(n), worstCase(n);
    for (int i = 0; i < n; i++) bestCase[i] = i;
    
    avgCase = bestCase;
    random_shuffle(avgCase.begin(), avgCase.end());
    
    worstCase = bestCase;
    reverse(worstCase.begin(), worstCase.end());
    
    measureTime(bestCase, "Best");
    measureTime(avgCase, "Average");
    measureTime(worstCase, "Worst");
    
    return 0;
}
