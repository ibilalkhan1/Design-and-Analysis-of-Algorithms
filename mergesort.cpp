#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void measureExecutionTime(vector<int>& arr, const string& caseType) {
    vector<int> tempArr = arr;
    auto start = high_resolution_clock::now();
    mergeSort(tempArr, 0, tempArr.size() - 1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    cout << "Merge Sort (" << caseType << " case): " << duration << " microseconds\n";
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

    cout << "Execution Times for Merge Sort:\n";
    measureExecutionTime(bestCase, "Best");
    measureExecutionTime(avgCase, "Average");
    measureExecutionTime(worstCase, "Worst");

    return 0;
}
