#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
void interleave(stack<int> &s, queue<int> &q){
    for (int i = 1; i < s.size(); i++){
        while (s.size() > i){
            q.push(s.top());
            s.pop();
        }
        while (!q.empty()){
            s.push(q.front());
            q.pop();
        }
    }
}
// this function is destructive
void print_stack(stack<int> &s){
    // print_stack is a reverse of our stack so it prints like in the readme.
    // The actual answer in our stack is correct, it is just harder to print like the example.
    stack<int> print_stack;
    while (!s.empty())
    {
     print_stack.push(s.top());
     s.pop();
    }
    while (!print_stack.empty())
    {
     cout << print_stack.top() << ' ';
     print_stack.pop();
    }
    cout << endl;
}

int main(){
    stack<int> s;
    queue<int> q;
    s.push(1); s.push(2); s.push(3); s.push(4); s.push(5);
    interleave(s, q);
    print_stack(s);
    s.push(1); s.push(2); s.push(3); s.push(4);
    interleave(s, q);
    print_stack(s);





}