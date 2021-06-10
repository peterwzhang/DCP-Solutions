#include <iostream>
#include <vector>

using namespace std;

// Kadane's algorithm
int solve_max(const vector<int> &array) {
    if (array.size() == 0) return 0;
    int cur_max = array[0], max_sum = array[0];
    for (int i = 1; i < array.size(); i++) {
        cur_max += array[i];
        max_sum = max(cur_max, max_sum);
        if (cur_max < 0) {
            cur_max = 0;
        }
    }
    return (max_sum < 0) ? 0 : max_sum;
}

int main() {
    vector<int> arr = {34, -50, 42, 14, -5, 86};
    vector<int> arr2 = {-5, -1, -8, -9};
    cout << solve_max(arr) << endl;
    cout << solve_max(arr2) << endl;
}