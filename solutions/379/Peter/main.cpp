#include <iostream>
#include <vector>
using namespace std;

void print(vector<string> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<string> all_subsequences(string s) {
    int num_combinations = pow(2, s.size());
    vector<string> arr(num_combinations);
    for (int i = 0; i < num_combinations; i++) {
        vector<int> new_set = {};
        for (int j = 0; j <= s.size(); j++) {
            if (i & (1 << j)) {
                arr[i] += s[j];
            }
        }
    }
    arr.erase(arr.begin());  // remove empty
    return arr;
}

int main() {
    string s = "xyz";
    print(all_subsequences(s));
}