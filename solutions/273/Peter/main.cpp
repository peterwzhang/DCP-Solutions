#include <iostream>
#include <vector>
using namespace std;

/*
    Array is sorted so we should look at binary search
*/

bool fix_point_exists(vector<int> array) {
    int start = 0;
    int end = array.size() - 1;
    while (end > start) {
        int mid = (start + end) / 2;
        if (array[mid] == mid)
            return true;  // you can return the mid here instead of true
        else if (array[mid] < mid)
            start = mid;
        else
            end = mid;
    }
    return false;
}

int main() {
    vector<int> test1 = {-6, 0, 2, 40};
    vector<int> test2 = {1, 5, 7, 8};
    cout << boolalpha << fix_point_exists(test1) << endl
         << fix_point_exists(test2) << endl;
}