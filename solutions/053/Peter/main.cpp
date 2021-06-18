#include <iostream>
#include <stack>
using namespace std;
template <typename T>
class GhettoQueue {
    stack<T> s1;
    stack<T> s2;

   public:
    GhettoQueue<T>() {}

    void enqeue(T item) { s1.push(item); }

    T deqeue() {
        if (s1.empty()) return T{};  // no elements
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        T ret = s2.top();
        s2.pop();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return ret;
    }
};

int main() {
    GhettoQueue<int> gq;
    gq.enqeue(1);
    gq.enqeue(2);
    gq.enqeue(3);
    gq.enqeue(4);
    cout << gq.deqeue() << endl;
    cout << gq.deqeue() << endl;
    gq.enqeue(5);
    gq.enqeue(6);
    cout << gq.deqeue() << endl;
    cout << gq.deqeue() << endl;
    cout << gq.deqeue() << endl;
    cout << gq.deqeue() << endl;
    return 0;
}