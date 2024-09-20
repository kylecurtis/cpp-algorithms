#include <iostream>
#include <vector>
#include <algorithm>  // For std::swap
#include <cassert>

/* INSERTION SORT
============================================================================= */
void insertionSort(std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int j = i - 1;
        while (j >= 0 && arr[j + 1] < arr[j]) {
            std::swap(arr[j], arr[j + 1]);
            j--;
        }
    }
}

/* MAIN (TESTS)
============================================================================= */
int main() {

    // Test 1: Empty array
    std::vector<int> arr1{};
    insertionSort(arr1);
    assert((arr1 == std::vector<int>{}));

    // Test 2: Single element array
    std::vector<int> arr2{42};
    insertionSort(arr2);
    assert((arr2 == std::vector<int>{42}));

    // Test 3: Already sorted array
    std::vector<int> arr3{1, 2, 3, 4, 5};
    insertionSort(arr3);
    assert((arr3 == std::vector<int>{1, 2, 3, 4, 5}));

    // Test 4: Reverse sorted array
    std::vector<int> arr4{5, 4, 3, 2, 1};
    insertionSort(arr4);
    assert((arr4 == std::vector<int>{1, 2, 3, 4, 5}));

    // Test 5: Array with duplicates
    std::vector<int> arr5{3, 1, 2, 3, 1};
    insertionSort(arr5);
    assert((arr5 == std::vector<int>{1, 1, 2, 3, 3}));

    std::cout << "All tests passed!" << '\n';

    return 0;
}