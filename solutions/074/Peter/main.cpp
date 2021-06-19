#include <iostream>
#include <vector>

using namespace std;

void fill_table(vector<vector<int>> &table, int N) {
    int num = 1;
    table.assign(N, vector<int>(N, 0));
    for (auto &v : table) {
        int count = 1;
        for (auto &i : v) {
            i += num * count;
            count++;
        }
        num++;
    }
}

void print_table(const vector<vector<int>> &table) {
    for (auto v : table) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
}
// O(N)
int count_occurrences(int x, int N) {
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (x % i == 0 && x >= i && x <= i * N) count++;
    }
    return count;
}

int main() {
    int N = 6, X = 12;
    vector<vector<int>> table;
    fill_table(table, N);
    print_table(table);
    cout << count_occurrences(X, N) << endl;
    cout << count_occurrences(1, N) << endl;
    cout << count_occurrences(36, N) << endl;
    cout << count_occurrences(15, N) << endl;
    cout << count_occurrences(6, N) << endl;
    cout << count_occurrences(3, N) << endl;
    cout << count_occurrences(18, N) << endl;
}