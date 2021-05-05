#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &array) {
    int start = 1, end = array.size() - 1, pivot = 0;
    int partitionInd = 0;
    for (int i = start; i <= end; i++) {
        if (array[i] <= pivot) {
            swap(array[partitionInd], array[i]);
            partitionInd++;
        }
    }
    return partitionInd;
}

void printVec(const vector<int> &a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int findMissingInt(vector<int> &array) {
    int start = partition(array);
    int end = array.size();
    // special case if all negative #
    if (array[end - 1] < 0) start++;
    int max = end - start + 1;
    for (int i = start; i < end; i++) {
        if (array[i] <= max) {
            int index = abs(array[i]) + start - 1;
            // cout << index;
            if (index < end && array[index] > 0) array[index] *= -1;
        }
    }
    // printVec(array);
    for (int i = start; i < end; i++) {
        if (array[i] > 0) return i - start + 1;
    }
    return max;
}

int main() {
    vector<int> array1 = {3, 4, -1, 1};
    vector<int> array2 = {1, 2, 0};
    vector<int> array3 = {3, 4, -1, 1, -2};
    vector<int> array4 = {75, 90, 20, 12, 2, -1, 3, -1, 4, 5, 17, 99};
    vector<int> array5 = {-1, -2, -3};
    cout << findMissingInt(array1) << endl;
    cout << findMissingInt(array2) << endl;
    cout << findMissingInt(array3) << endl;
    cout << findMissingInt(array4) << endl;
    cout << findMissingInt(array5) << endl;
    return 0;
}