#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int compute_edit_distance(const string &s1, const string &s2) {
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        table[i][0] = i;
    }
    for (int i = 1; i <= n; i++) {
        table[0][i] = i;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // 3 cases
            // x is the current substring of x
            // insert character at end of x
            // remove last character of x
            // modify last character of x (if needed)
            table[i][j] =
                min(min(table[i][j - 1] + 1, table[i - 1][j] + 1),
                    table[i - 1][j - 1] + ((s1[i - 1] == s2[j - 1]) ? 0 : 1));
        }
    }
    return table[m][n];
}

int main() {
    cout << compute_edit_distance("love", "movie") << endl;
    cout << compute_edit_distance("kitten", "sitting") << endl;
    return 0;
}