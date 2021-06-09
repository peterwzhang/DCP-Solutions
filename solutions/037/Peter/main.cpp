#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int> > ps){
    cout << "{";
    for (int i = 0; i < ps.size(); i++){
        cout << "{";
        for (int j = 0; j < ps[i].size(); j++){
            if (j == 0) cout << ps[i][j];
            else cout << ", " << ps[i][j];
        }
        if (i == ps.size() - 1) cout << "}";
        else cout << "}, ";
    }
    cout << "{";
}

vector<vector<int> > power_set(vector<int> set){
    vector<vector<int> > power_set;
    int num_combinations = pow(2, set.size());
    for (int i = 0; i < num_combinations; i++){
        vector<int> new_set = {};
        for (int j = 0; j <= set.size(); j++){
            if (i & (1 << j)) {
                new_set.push_back(set[j]);
            }
        }
        power_set.push_back(new_set);
    }
    return power_set;
}

int main(){
    // solution is in slightly different order since I used the binary counter method,
    // but all the subsets will still be in the power set.
    vector<int> set = {1,2,3};
    print(power_set(set));
}