#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

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

void quickSortDeterministic(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortDeterministic(arr, low, pi - 1);
        quickSortDeterministic(arr, pi + 1, high);
    }
}

int partitionRandomized(vector<int>& arr, int low, int high) {
    int randomPivot = low + rand() % (high - low + 1);
    swap(arr[randomPivot], arr[high]);
    return partition(arr, low, high);
}

void quickSortRandomized(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionRandomized(arr, low, high);
        quickSortRandomized(arr, low, pi - 1);
        quickSortRandomized(arr, pi + 1, high);
    }
}

double measureTime(void (*sortFunc)(vector<int>&, int, int), vector<int>& arr, int low, int high) {
    auto start = high_resolution_clock::now();
    sortFunc(arr, low, high);
    auto stop = high_resolution_clock::now();
    return duration_cast<microseconds>(stop - start).count() / 1000.0;
}

void fillRandomArray(vector<int>& arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }
}

void fillSortedArray(vector<int>& arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
}

void fillReverseSortedArray(vector<int>& arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = size - i - 1;
    }
}

int main() {
    srand(time(0));

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arrRandom(n);
    vector<int> arrSorted(n);
    vector<int> arrReverseSorted(n);

    fillRandomArray(arrRandom, n);
    fillSortedArray(arrSorted, n);
    fillReverseSortedArray(arrReverseSorted, n);

    vector<int> tempArr = arrRandom;
    double timeDeterministic = measureTime(quickSortDeterministic, tempArr, 0, n - 1);
    cout << "\nDeterministic Quick Sort Time (Random Array): " << timeDeterministic << " ms\n";

    tempArr = arrRandom;
    double timeRandomized = measureTime(quickSortRandomized, tempArr, 0, n - 1);
    cout << "Randomized Quick Sort Time (Random Array): " << timeRandomized << " ms\n";

    tempArr = arrSorted;
    timeDeterministic = measureTime(quickSortDeterministic, tempArr, 0, n - 1);
    cout << "Deterministic Quick Sort Time (Sorted Array): " << timeDeterministic << " ms\n";

    tempArr = arrSorted;
    timeRandomized = measureTime(quickSortRandomized, tempArr, 0, n - 1);
    cout << "Randomized Quick Sort Time (Sorted Array): " << timeRandomized << " ms\n";

    tempArr = arrReverseSorted;
    timeDeterministic = measureTime(quickSortDeterministic, tempArr, 0, n - 1);
    cout << "Deterministic Quick Sort Time (Reverse Sorted Array): " << timeDeterministic << " ms\n";

    tempArr = arrReverseSorted;
    timeRandomized = measureTime(quickSortRandomized, tempArr, 0, n - 1);
    cout << "Randomized Quick Sort Time (Reverse Sorted Array): " << timeRandomized << " ms\n";

    return 0;
}