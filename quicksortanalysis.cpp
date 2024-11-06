//quicksort temporary
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Stats {
    int comparisons = 0;
    int swaps = 0;
};

// Deterministic partition function using the last element as pivot
int partitionDeterministic(vector<int>& arr, int low, int high, Stats& stats) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        stats.comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            stats.swaps++;
        }
    }
    swap(arr[i + 1], arr[high]);
    stats.swaps++;
    return i + 1;
}

// Deterministic Quick Sort
void quickSortDeterministic(vector<int>& arr, int low, int high, Stats& stats) {
    if (low < high) {
        int pi = partitionDeterministic(arr, low, high, stats);
        quickSortDeterministic(arr, low, pi - 1, stats);
        quickSortDeterministic(arr, pi + 1, high, stats);
    }
}

// Randomized partition function
int partitionRandomized(vector<int>& arr, int low, int high, Stats& stats) {
    int pivotIndex = low + rand() % (high - low + 1);  // Random pivot
    swap(arr[pivotIndex], arr[high]);
    stats.swaps++;
    return partitionDeterministic(arr, low, high, stats);
}

// Randomized Quick Sort
void quickSortRandomized(vector<int>& arr, int low, int high, Stats& stats) {
    if (low < high) {
        int pi = partitionRandomized(arr, low, high, stats);
        quickSortRandomized(arr, low, pi - 1, stats);
        quickSortRandomized(arr, pi + 1, high, stats);
    }
}

// Analysis function to compare the two variants
void analyzeQuickSorts(vector<int> arr) {
    vector<int> arrDeterministic = arr;
    vector<int> arrRandomized = arr;

    Stats statsDeterministic, statsRandomized;

    // Run deterministic quicksort
    quickSortDeterministic(arrDeterministic, 0, arrDeterministic.size() - 1, statsDeterministic);

    // Run randomized quicksort
    quickSortRandomized(arrRandomized, 0, arrRandomized.size() - 1, statsRandomized);

    // Display results
    cout << "Deterministic Quick Sort:" << endl;
    cout << "Sorted Array: ";
    for (int num : arrDeterministic) cout << num << " ";
    cout << "\nComparisons: " << statsDeterministic.comparisons << endl;
    cout << "Swaps: " << statsDeterministic.swaps << endl;

    cout << "\nRandomized Quick Sort:" << endl;
    cout << "Sorted Array: ";
    for (int num : arrRandomized) cout << num << " ";
    cout << "\nComparisons: " << statsRandomized.comparisons << endl;
    cout << "Swaps: " << statsRandomized.swaps << endl;
}

int main() {
    srand(time(0));  // Seed random number generator

    // Test array
    vector<int> arr = {1,2,3,4,5};

    analyzeQuickSorts(arr);

    return 0;
}