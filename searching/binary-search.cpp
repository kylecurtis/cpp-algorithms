#include <iostream>
#include <vector>
#include <cassert>

/* BINARY SEARCH
============================================================================= */
int binarySearch(const std::vector<int>& arr, int target) {
    int L = 0, R = arr.size() - 1;

    while (L <= R) {
        int mid = L + (R - L) / 2;

        if (target > arr[mid]) {
            L = mid + 1;
        } else if (target < arr[mid]) {
            R = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

/* MAIN (TESTS)
============================================================================= */
int main() {

    // Test 1: Target present in the middle
    std::vector<int> arr1{1, 2, 3, 4, 5};
    assert(binarySearch(arr1, 3) == 2);

    // Test 2: Target present at the beginning
    std::vector<int> arr2{10, 20, 30, 40, 50};
    assert(binarySearch(arr2, 10) == 0);

    // Test 3: Target present at the end
    std::vector<int> arr3{10, 20, 30, 40, 50};
    assert(binarySearch(arr3, 50) == 4);

    // Test 4: Target not present
    std::vector<int> arr4{10, 20, 30, 40, 50};
    assert(binarySearch(arr4, 60) == -1);

    // Test 5: Empty array
    std::vector<int> arr5{};
    assert(binarySearch(arr5, 10) == -1);

    // Test 6: Single element array, target found
    std::vector<int> arr6{42};
    assert(binarySearch(arr6, 42) == 0);

    // Test 7: Single element array, target not found
    std::vector<int> arr7{42};
    assert(binarySearch(arr7, 99) == -1);

    std::cout << "All tests passed!" << '\n';

    return 0;
}