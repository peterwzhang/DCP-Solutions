#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

using namespace std;

double apply_operand(int op, int num1, int num2){
    double returnVal;
    switch (op) {
        case 0:  // add
            returnVal = (double)num1 + num2;
            break;
        case 1:  // subtract
            returnVal = (double)num1 - num2;
            break;
        case 2:  // multiply
            returnVal = (double)num1 * num2;
            break;
        case 3:  // divide
            if (num2 == 0){
                returnVal = num1 / 0.0000001;
                break;
            }
            returnVal = (double)num1 / num2;
            break;
    }
    return returnVal;
}

double solve(int op, int op2, int op3, vector<int> arr, int order) {
    double returnVal;
    double returnVal2;
    switch (order) {
        case 0:  // 123
            returnVal = apply_operand(op, arr[0], arr[1]);
            returnVal = apply_operand(op2, returnVal, arr[2]);
            returnVal = apply_operand(op3, returnVal, arr[3]);
            break;
        case 1:  // 132
        case 4:  // 312
            returnVal = apply_operand(op, (double)arr[0], (double)arr[1]);
            returnVal2 = apply_operand(op3, (double)arr[2], (double)arr[3]);
            returnVal = apply_operand(op2, returnVal, returnVal2);
            break;
        case 2:  // 213
            returnVal2 = apply_operand(op2, arr[1], arr[2]);
            returnVal = apply_operand(op, arr[0], returnVal2);
            returnVal = apply_operand(op3, returnVal, arr[3]);
            break;
        case 3:  // 231
            returnVal2 = apply_operand(op2, arr[1], arr[2]);
            returnVal = apply_operand(op3, returnVal2, arr[3]);
            returnVal = apply_operand(op, arr[0], returnVal);
            break;
        case 5:  // 321
            returnVal2 = apply_operand(op3, arr[2], arr[3]);
            returnVal = apply_operand(op2, arr[1], returnVal2);
            returnVal = apply_operand(op, arr[0], returnVal);
            break;
    }
    return returnVal;
}


bool try_permutation(vector<int> nums) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 6; l++) {
                    double ans = solve(i, j, k, nums, l);
                    if (24 - 0.0001 < ans && ans < 24 + 0.0001) return true;
                }
            }
        }
    }
    return false;
}

bool try_all_permutation(vector<int> numbers){
    do {
        if (try_permutation(numbers)) return true;
    } while (next_permutation(numbers.begin(), numbers.end()));
    return false;
}

// cs 100 throwback
int main() {
    cout << "Enter 4 numbers:" << endl;
    vector<int> numbers(4);
    for (int i = 0; i < numbers.size(); i++) {
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    cout << boolalpha << try_all_permutation(numbers) << endl;
    return 0;
}