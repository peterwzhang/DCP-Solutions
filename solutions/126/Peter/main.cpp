#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// assuming k is always positive
void rotate(int k, vector<int> &a){
    reverse(a.begin(), a.begin() + k - 1);
    reverse(a.begin() + k, a.end());
    reverse(a.begin(), a.end());
}

void print(const vector<int> &a){
    for (auto i: a)
        cout << i << " ";
    cout << endl;
}

int main(){
    vector<int> array = {1, 2, 3, 4, 5, 6};
    rotate(2, array);
    print(array);
    return 0;
}