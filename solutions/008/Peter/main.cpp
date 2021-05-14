#include <iostream>

struct Node{
int value;
Node *left;
Node *right;

Node(int v, Node *l, Node*r) : value(v), left(l), right(r) {};
};

int countUnival(Node *root){
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    if (root->left->value == root->value && root->right->value == root->value) return 1 + countUnival(root->left) + countUnival(root->right);
    return countUnival(root->left) + countUnival(root->right);
}

using namespace std;

int main(){
    Node *node5 = new Node(1, nullptr, nullptr);
    Node *node6 = new Node(1, nullptr, nullptr);
    Node *node3 = new Node(1, node5, node6);
    Node *node4 = new Node(0, nullptr, nullptr);
    Node *node2 = new Node(0, node3, node4);
    Node *node1 = new Node(1, nullptr, nullptr);
    Node *root = new Node(0, node1, node2);
    cout << countUnival(root) << endl;

}