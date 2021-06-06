#include <iomanip>
#include <iostream>
#include <random>

using namespace std;

int main() {
    const int sq_max = 1;
    const int sq_min = -1;
    random_device rd;
    default_random_engine engine(rd());
    uniform_real_distribution<double> dist(sq_min, sq_max);
    int num_square = 1000000;
    int num_circle = 0;
    for (int i = 0; i < num_square; i++) {
        double x = dist(engine);
        double y = dist(engine);
        double dist_to_origin = sqrt(x * x + y * y);
        if (dist_to_origin <= 1) num_circle++;
    }
    double Pi = 4.0 * num_circle / num_square;
    cout << setprecision(4) << Pi << endl;
}