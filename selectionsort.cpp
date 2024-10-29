#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

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

void measureTime(vector<int>& arr, const string& caseType) {
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    selectionSort(arr);
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Selection Sort (" << caseType << " case): " << duration.count() << " microseconds\n";
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
