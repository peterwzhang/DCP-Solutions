#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int> &array) {
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// O(n) with division
// does not work with 0s
vector<int> solution1(const vector<int> &array) {
    int total = 1;
    for (int i = 0; i < array.size(); i++) {
        total *= array[i];
    }
    vector<int> solution(array.size());
    for (int i = 0; i < array.size(); i++) {
        solution[i] = total / array[i];
    }
    return solution;
}

// O(n) no divison
vector<int> solution2(const vector<int> &array) {
    vector<int> leftProduct(array.size()), rightProduct(array.size());
    // calculate left products
    for (int i = 0; i < array.size(); i++) {
        if (i == 0)
            leftProduct[0] = 1;
        else
            leftProduct[i] = leftProduct[i - 1] * array[i - 1];
    }
    // calculate right products
    for (int i = array.size() - 1; i >= 0; i--) {
        if (i == array.size() - 1)
            rightProduct[array.size() - 1] = 1;
        else
            rightProduct[i] = rightProduct[i + 1] * array[i + 1];
    }
    vector<int> solution(array.size());
    // calculate final answer
    for (int i = 0; i < array.size(); i++) {
        solution[i] = leftProduct[i] * rightProduct[i];
    }
    // printVector(leftProduct);
    // printVector(rightProduct);
    return solution;
}

int main() {
    cout << "Test 1" << endl;
    vector<int> inputList = {1, 2, 3, 4, 5};
    printVector(solution1(inputList));
    printVector(solution2(inputList));

    cout << "Test 2" << endl;
    vector<int> inputList2 = {0, 2, 3, 4, 5};
    // printVector(solution1(inputList2)); does not work with 0's
    printVector(solution2(inputList2));

    cout << "Test 3" << endl;
    vector<int> inputList3 = {7, 10, 15, 9, 2, 3, 21};
    printVector(solution1(inputList3));
    printVector(solution2(inputList3));
    return 0;
}