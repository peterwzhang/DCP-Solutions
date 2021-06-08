#include <iostream>
#include <vector>
using namespace std;

// solve num ways with only being able to take 1 or 2 steps.
int solve_num_ways(int n) {
    if (n < 0) return 0;
    if (n == 0 || n == 1) return 1;
    vector<int> num_ways = {1, 1};
    for (int i = 2; i <= n; i++) {
        num_ways.push_back(num_ways[i - 1] + num_ways[i - 2]);
    }
    return num_ways.back();
}

// solve num ways while being able to take any number of steps.
int solve_num_ways_2(int n, vector<int> steps) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    vector<int> num_ways = {1};
    for (int i = 1; i <= n; i++) {
        int new_num_way = 0;
        for (int j = 0; j < steps.size(); j++) {
            if (i - steps[j] < 0) continue;
            new_num_way += num_ways[i - steps[j]];
        }
        num_ways.push_back(new_num_way);
    }
    return num_ways.back();
}
int main() {
    cout << solve_num_ways(4) << endl;
    cout << solve_num_ways(10) << endl;
    cout << solve_num_ways_2(4, vector<int>{1, 2, 3}) << endl;
    cout << solve_num_ways_2(4, vector<int>{1, 3, 5}) << endl;
}