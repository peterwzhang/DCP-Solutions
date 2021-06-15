#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;
// O(nk) n = size of set, k = length of str
vector<string> return_sentence(set<string> set, string str) {
    unordered_set<string> uo_set(set.begin(), set.end());
    vector<string> ans;
    string cur_substr;
    for (char c : str) {
        cur_substr += c;
        if (uo_set.find(cur_substr) != uo_set.end()) {
            ans.push_back(cur_substr);
            cur_substr = "";
        }
    }
    return ans;
}

int main() {
    string s1 = "thequickbrownfox";
    string s2 = "bedbathandbeyond";
    set<string> set1 = {"quick", "brown", "the", "fox"};
    set<string> set2 = {"bed", "bath", "bedbath", "and", "beyond"};
    vector<string> sentence1 = return_sentence(set1, s1);
    vector<string> sentence2 = return_sentence(set2, s2);
    for (string s : sentence1) cout << s << " ";
    cout << endl;
    for (string s : sentence2) cout << s << " ";
    cout << endl;
}