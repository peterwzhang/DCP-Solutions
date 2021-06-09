#include <iostream>
#include <random>

using namespace std;
double dice_game(int a, int b, int num_g) {
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist(1, 6);
    int total_cost = 0;
    for (int i = 0; i < num_g; i++) {
        int prev_num = dist(rng);
        int cur_plays = 1;
        while (true) {
            int cur_num = dist(rng);
            cur_plays++;
            if (prev_num == a && cur_num == b) {
                total_cost += cur_plays;
                break;
            }
            prev_num = cur_num;
        }
    }
    return double(total_cost) / double(num_g);
}
int main() {
    cout << "5->6 Game EV: " << dice_game(5, 6, 100000) << endl;
    cout << "5->5 Game EV: " << dice_game(5, 5, 100000) << endl;
}