#include <iostream>
#include <utility>

using namespace std;

pair<int, int> cons(int a, int b) {
    auto f = [&](int a, int b){return make_pair(a, b);};
    auto pair = [&]() { return f(a, b); };
    return pair();
}

int car(pair<int, int> pair){
    auto returnfirst = [&](){return pair.first;};
    return returnfirst();
}

int cdr(pair<int, int> pair){
    auto returnlast = [&](){return pair.second;};
    return returnlast();
}

int main() {
    auto pair = cons(3, 4);
    cout << car(pair) << endl << cdr(pair) << endl;
    return 0;
}