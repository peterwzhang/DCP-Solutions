#include <iostream>
using namespace std;

// to get O(1) space we can just use DP with only two numbers held in memory.
int fib(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else {
        int count = 1;  // since our first two cases are handled already
        int cur_num = 0, next_num = 1, final_num = 0;
        while (count != n) {
            final_num = cur_num + next_num;
            cur_num = next_num;
            next_num = final_num;
            count++;
        }
        return final_num;
    }
}

int main() {
    cout << fib(0) << endl;
    cout << fib(2) << endl;
    cout << fib(5) << endl;
    cout << fib(3) << endl;
    cout << fib(10) << endl;
    return 0;
}