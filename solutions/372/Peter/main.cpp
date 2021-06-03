#include <iostream>
using namespace std;

// only natural numbers, so we can use the formula:
// floor(logbase10(n)) + 1
// and a special case for 0 as it is undefined for log.
int get_digits(int num) {
    if (num == 0)
        return 1;
    else
        return floor(log10(num)) + 1;
}

int main() {
    cout << get_digits(0) << endl;
    cout << get_digits(96) << endl;
    cout << get_digits(1337) << endl;
    cout << get_digits(12345) << endl;
    cout << get_digits(999999) << endl;
}