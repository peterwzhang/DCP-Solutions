#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// O(n^2)
bool solution1(vector<int> list, int k) {
    for (int i = 0; i < list.size(); i++) {
        int numToFind = k - list[i];
        for (int j = 0; j < list.size(); j++) {
            if (i == j) continue;
            if (list[j] == numToFind) return true;
        }
    }
    return false;
}

// O(nlgn)
bool solution2(vector<int> list, int k) {
    sort(list.begin(), list.end());
    for (int i = 0; i < list.size(); i++) {
        if (i == 0) {
            int numToFind = k - list[0];
            if (binary_search(list.begin() + 1, list.end(), numToFind) == true)
                return true;
        } else {
            swap(list[0], list[i]);
            int numToFind = k - list[0];
            if (binary_search(list.begin() + 1, list.end(), numToFind) ==
                true) {
                swap(list[0], list[i]);
                return true;
            } else {
                swap(list[0], list[i]);
            }
        }
    }
    return false;
}

// O(n)
bool solution3(vector<int> list, int k) {
    unordered_set<int> presumVals;
    for (int i = 0; i < list.size(); i++) {
        int numToFind = k - list[i];
        if (presumVals.count(numToFind) > 0)
            return true;
        else
            presumVals.insert(list[i]);
    }
    return false;
}

int main() {
    vector<int> inputList = {10, 15, 3, 7};
    int k = 17;
    cout << solution1(inputList, k) << endl;
    cout << solution2(inputList, k) << endl;
    cout << solution3(inputList, k) << endl;

    k = 16;
    cout << solution1(inputList, k) << endl;
    cout << solution2(inputList, k) << endl;
    cout << solution3(inputList, k) << endl;
}