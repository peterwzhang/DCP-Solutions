#include <iostream>
#include <vector>

using namespace std;
// Kadane's Algorithm, but modified to find the minsum also
// when the circular array property is used, the answer will be
// total sum - min sum rather than max sum
int compute_max_subarray(vector<int> array) {
    int cur_max = array[0], max_sum = array[0];
    int cur_min = array[0], min_sum = array[0];
    for (int i = 1; i < array.size(); i++) {
        cur_max = max(array[i], array[i] + max_sum);
        max_sum = max(cur_max, max_sum);
        cur_min = min(array[i], array[i] + min_sum);
        min_sum = min(cur_min, min_sum);
    }
    int total_sum = 0;
    for (int i = 0; i < array.size(); i++) {
        total_sum += array[i];
    }
    if (total_sum == min_sum) return max_sum;  // handle all negative case
    return max(total_sum - min_sum, max_sum);
}

int main() {
    vector<int> array = {8, -1, 3, 4};
    vector<int> array2 = {-4, 5, 1, 0};
    cout << compute_max_subarray(array) << endl;
    cout << compute_max_subarray(array2) << endl;
}