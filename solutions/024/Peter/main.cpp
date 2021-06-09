#include <ios>
#include <iostream>

using namespace std;

class node {
    bool locked;
    node* left;
    node* right;
    node* parent;

    bool is_locked() { return locked; }
    int count_locks(node* cur) {
        if (cur == nullptr) return 0;
        if (cur->is_locked()) return 1;
        return count_locks(cur->left) + count_locks(cur->right);
    }
    bool is_changable() {
        node* cur = parent;
        while (cur != nullptr) {
            if (cur->is_locked()) return false;
            cur = cur->parent;
        }
        int num_locks = count_locks(this->left) + count_locks(this->right);
        if (num_locks == 0) return true;
        return false;
    }

   public:
    node(bool lock, node* l, node* r) : locked(lock), left(l), right(r){};
    bool lock() {
        if (is_changable()) {
            locked = true;
            return true;
        }
        return false;
    }
    bool unlock() {
        if (is_changable()) {
            locked = false;
            return true;
        }
        return false;
    }
    void update_parent(node* p) { parent = p; }
};

int main() {
    node* l = new node(false, nullptr, nullptr);
    node* r = new node(false, nullptr, nullptr);
    node* root = new node(false, l, r);
    l->update_parent(root);
    r->update_parent(root);
    root->update_parent(nullptr);
    cout << boolalpha;
    cout << root->lock() << endl;
    cout << l->lock() << endl;
    cout << root->unlock() << endl;
    cout << r->lock() << endl;
    cout << l->lock() << endl;
    cout << root->lock() << endl;
}