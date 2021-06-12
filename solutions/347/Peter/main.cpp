#include <iostream>
#include <vector>
using namespace std;

string smallest_string(string word, int k) {
    vector<pair<char, int>>
        moveable_chars;  // char value and original location in pair
    for (int i = 0; i < k; i++) {
        moveable_chars.push_back({word[i], i});
    }
    sort(moveable_chars.begin(),
         moveable_chars.end());  // sorts by first by default
    for (auto p = moveable_chars.begin(); p != moveable_chars.end(); p++) {
        if (p->first > word[k]) {  // everything <= gets moved to back
            word += p->first;
            word.erase(p->second, 1);
        }
    }
    return word;
}

int main() {
    string word = "daily";
    int k = 1;
    cout << smallest_string(word, k) << endl;
    cout << smallest_string("sunshine", 3) << endl;
    cout << smallest_string("placeboeffect", 7) << endl;
    return 0;
}