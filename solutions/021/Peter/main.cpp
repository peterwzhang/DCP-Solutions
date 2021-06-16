#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
// O(n^2) when each class requires its own classroom
// this uses a greedy algorithm to choose earliest ending event first
int num_classrooms(vector<pair<int, int>> t_i) {
    sort(t_i.begin(), t_i.end(),
         [](auto &l, auto &r) { return l.second < r.second; });
    int num_classrooms = 0;
    while (!t_i.empty()) {
        int last_time = t_i.begin()->second;
        iter_swap(t_i.begin(), t_i.end() - 1);
        t_i.pop_back();
        for (auto it = t_i.begin(); it != t_i.end(); it++) {
            if (it->first > last_time) {
                last_time = it->second;
                iter_swap(t_i.begin(), t_i.end() - 1);
                t_i.pop_back();
            }
        }
        num_classrooms++;
    }
    return num_classrooms;
}

int main() {
    vector<pair<int, int>> time_intervals = {{30, 75}, {0, 50}, {60, 150}};
    cout << num_classrooms(time_intervals) << endl;
    time_intervals = {{30, 75}, {0, 60}, {60, 150}};
    cout << num_classrooms(time_intervals) << endl;
}