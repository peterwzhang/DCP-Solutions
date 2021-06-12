#include <iostream>
#include <set>
#include <vector>
using namespace std;

int longest_distinct_subarray(vector<int> arr) {
    set<int> s;
    int max_len = 0;
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (s.find(arr[i]) != s.end()) {
            max_len = max(max_len, count);
            count = 0;
            s.clear();
        }
        count++;  // count still needs to increment as the previously duplicated
                  // element is now unique for the next subarray
        s.insert(arr[i]);
    }
    return count;
}

int main() {
    vector<int> array = {5, 1, 3, 5, 2, 3, 4, 1};
    cout << longest_distinct_subarray(array) << endl;
    return 0;
}