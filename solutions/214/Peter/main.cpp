#include <iostream>

using namespace std;

int longest_one_run (int n){
    int highest = 0;
    int cur = 0;
    while (n != 0){
        int r = n % 2;
        n = n / 2;
        if (r == 0){
            cur = 0;
        }
        else {
            cur++;
            highest = max(cur, highest);
        }
    }
    return highest;
}

int main(){
    int n = 156;
    cout << longest_one_run(n) << endl;
}