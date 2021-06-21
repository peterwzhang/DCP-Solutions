#include <iostream>
#include <list>

using namespace std;

list<int> int_to_list(int i) {
    list<int> new_list;
    while (i > 0) {
        new_list.push_back(i % 10);
        i /= 10;
    }
    if (new_list.size() == 0) new_list.push_front(0);
    return new_list;
}

int list_to_int(const list<int> &l) {
    int multiplier = 1;
    int total = 0;
    for (auto it = l.begin(); it != l.end(); it++) {
        total += *it * multiplier;
        multiplier *= 10;
    }
    return total;
}

list<int> add_lists(const list<int> &l1, const list<int> &l2) {
    int val1 = list_to_int(l1);
    int val2 = list_to_int(l2);
    int sum = val1 + val2;
    return int_to_list(sum);
}

void print_list(const list<int> &l) {
    for (const auto &i : l) {
        cout << i << " ";
    }
    cout << endl;
}

int main(void) {
    list<int> l1 = {9, 9};
    list<int> l2 = {5, 2};
    print_list(add_lists(l1, l2));
}