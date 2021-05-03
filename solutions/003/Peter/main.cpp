#include <iostream>
#include <sstream>
using namespace std;

class Node{
    public:
        string val;
        Node *left;
        Node *right;

        Node(string v, Node *l, Node *r){
            val = v;
            left = l;
            right = r;
        }
};

void serializeHelper(Node *n, stringstream &ss){
    if (n == nullptr) {
        // assuming nullptr will never be actual used as a value
        ss << "nullptr ";
        return;
    }
    ss << n->val << " ";
    serializeHelper(n->left, ss);
    serializeHelper(n->right, ss);
}

string serialize(Node *root){
    stringstream ss;
    serializeHelper(root, ss);
    return ss.str();
}

Node *deserializeHelper(stringstream &ss){
    string cur;
    ss >> cur;
    if (cur == "nullptr") return nullptr;
    Node* curNode = new Node(cur, nullptr, nullptr);
    curNode->left = deserializeHelper(ss);
    curNode->right = deserializeHelper(ss);
    return curNode;
}

Node *deserialize(string s){
    stringstream ss(s);
    Node *root = deserializeHelper(ss);
    return root;
}

//unneeded
Node *createNode(string v, Node *l, Node *r){
    Node *newN = new Node(v, l, r);
    return newN;
}

int main(){
    Node *root = new Node("root", new Node("left", new Node("left.left", nullptr, nullptr), nullptr), new Node("right", nullptr, nullptr));
    //cout << root->val;
    //cout << serialize(root) << endl;
    Node *root2 = deserialize(serialize(root));
    //cout << serialize(root2) << endl;
    assert(root2->left->left->val == "left.left");
    cout << "assert passed" << endl;
}