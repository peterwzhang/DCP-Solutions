#include <ios>
#include <iostream>

using namespace std;

class Node {
   public:
    int val;
    Node *left;
    Node *right;

    Node(int v, Node *l, Node *r) {
        val = v;
        left = l;
        right = r;
    }
    bool helper(Node *cur_node, int cur, int k) {
        if (cur_node == nullptr) return cur == k;
        return helper(cur_node->left, cur + cur_node->val, k) ||
               helper(cur_node->right, cur + cur_node->val, k);
    }
    bool path_exists(int k) { return helper(this, 0, k); }
};

int main() {
    // make example
    Node *root =
        new Node(8,
                 new Node(4, new Node(2, nullptr, nullptr),
                          new Node(6, nullptr, nullptr)),
                 new Node(13, nullptr, new Node(19, nullptr, nullptr)));
    int k = 18;
    cout << boolalpha << root->path_exists(k) << endl;
    root->val = 2;
    cout << boolalpha << root->path_exists(k) << endl;
}