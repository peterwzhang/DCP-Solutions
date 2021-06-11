#include <iostream>
#include <vector>
using namespace std;

int find_max_product(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int s = 0;
    int e = arr.size() - 1;
    return max(arr[e] * arr[e - 1] * arr[e - 2], arr[s] * arr[s + 1] * arr[e]);
}
int main() {
    vector<int> arr = {-10, -10, 5, 2};
    cout << find_max_product(arr) << endl;
}