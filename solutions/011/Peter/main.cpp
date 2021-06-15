#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<string> return_autocomplete(set<string> set, string s){
    auto start = set.upper_bound(s);
    if (start == set.end()) return {};
    vector<string> ans;
    for (auto it = start; it != set.end(); it++){
        if (s == it->substr(0, s.length()))
            ans.push_back(*it);
    }
    return ans;
}

int main(){
    set<string> s;
    s.insert("dog");
    s.insert("deer");
    s.insert("deal");
    s.insert("detrimental");
    s.insert("alabama");
    s.insert("doctor");
    string str = "de";
    vector<string> ans = return_autocomplete(s, str);
    for (string x: ans)
        cout << x << " ";
    cout << endl;
}