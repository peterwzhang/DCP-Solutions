#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<char> apply_permutation(vector<char> &arr, vector<int> &perm) {
    vector<char> new_arr;
    for (int i = 0; i < arr.size(); i++){
        new_arr.push_back(arr[perm[i]]);
    }
    return new_arr;
}

void print(vector<char> array){
    for (int i = 0; i < array.size(); i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<char> array = {'a', 'b', 'c'};
    vector<int> permutation = {2,1,0};
    print(apply_permutation(array, permutation));
    return 0;
}