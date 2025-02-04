/*
 * Arch 2024 fall course code.
 * - This is an example C code of Binary Search algorithm.
 * - This code is generated by Github Copilot.
 * - The array is directly included to avoid the reading process for a
 * quicker simulation.
 * - This program will search multiple targets in the array using Binary
 * Search algorithm.
 * - This program is used for benchmarking the Branch Predictor and Cache
 * Prefetcher in gem5.
 */

#include "binary_search.in"

int binary_search(int arr[], int n, int target) {
    int left  = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main(int argc, char *argv[]) {
    for (int i = 0; i < M; i++) {
        binary_search(ARR, N, TARGETS[i]);
    }
    return 0;
}
