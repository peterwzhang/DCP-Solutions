#include <iostream>
#include <vector>

using namespace std;
// modified binary search to work with rotated sorted arrays
// we just check if the element can fit on either half since it is sorted
// then we continue binary search as normal on that single side.
int binary_search(vector<int> arr, int element) {
    int low = 0, high = arr.size() - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] == element) return mid;
        if (arr[low] <= arr[mid]) { // left half sorted
            if (arr[low] <= element && arr[mid] >= element)
                high = mid - 1;
            else // arr[low] > element && arr[mid] < element
                low = mid + 1;
        }
        else { // right half sorted
            if (arr[mid] <= element && arr[high] >= element)
                low = mid + 1;
            else // arr[mid] > element && arr[high] < element
                high = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> array = {13, 18, 25, 2, 8, 10};
    int element_to_find = 8;
    cout << binary_search(array, 8) << endl;
}