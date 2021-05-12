#include <iostream>

using namespace std;

template<typename type>
class DLL{
    private:
        typedef struct _node{
            type val;
            _node *both;
        } node;
        node *first;
        node *last;
        int numNodes;
    public:
        DLL(){
            first = nullptr;
            last = nullptr;
            numNodes = 0;
        };
        ~DLL(){
            if (first != nullptr){
                node *cur = first;
                node *prev = nullptr;
                while (cur != nullptr){
                    node *temp = cur;
                    cur = (node*)((uintptr_t)cur->both ^ (uintptr_t)prev);
                    node *nodetodel = prev;
                    prev = temp;
                    if (nodetodel != nullptr)
                        delete nodetodel;
                }
                delete prev; // delete last node
            }
        }
        void print(){
            if (first != nullptr){
                node *cur = first;
                node *prev = nullptr;
                while (cur != nullptr){
                    cout << cur->val << " ";
                    node *temp = cur;
                    cur = (node*)((uintptr_t)cur->both ^ (uintptr_t)prev);
                    prev = temp;
                }
                cout << endl;
            }
        }
        void add(type val){
            if (first == nullptr && last == nullptr){
                node *newNode =  new node();
                newNode->val = val;
                newNode->both = nullptr;
                first = newNode;
                last = newNode;
            }
            else {
                node *newNode =  new node();
                newNode->val = val;
                // really unneeded here but just to remind me to use all this type casting
                // XOR with nullptr should be the same as XOR with 0
                newNode->both = (node*)((uintptr_t)last ^ (uintptr_t)nullptr);
                node *prev = (node*)((uintptr_t)last->both ^ (uintptr_t)nullptr);
                last->both = (node*)((uintptr_t)prev ^ (uintptr_t)newNode);
                last = newNode;
            }
            numNodes++;
        }
        node *get(int index){
            if (numNodes == 0){
                cout << "empty list" << endl;
                return nullptr;
            }
            // start from front
            if (index + 1 < numNodes / 2){
                int count = 0;
                node *cur = first;
                node *prev = nullptr;
                while (cur != nullptr){
                    if (count == index){
                        return cur;
                    }
                    node *temp = cur;
                    cur = (node*)((uintptr_t)cur->both ^ (uintptr_t)prev);
                    prev = temp;
                    count++;
                }
            }
            else { // start from back
                int count = numNodes - 1;
                node *cur = last;
                node *next = nullptr;
                while (cur != nullptr){
                    if (count == index){
                        return cur;
                    }
                    node *temp = cur;
                    cur = (node*)((uintptr_t)cur->both ^ (uintptr_t)next);
                    next = temp;
                    count--;
                }
            }
            return nullptr;
        }
};

int main(){
    DLL<int> test;
    test.add(1);
    test.add(2);
    test.add(3);
    test.add(4);
    test.print();
    cout << test.get(0)->val << endl;
    cout << test.get(1)->val << endl;
    cout << test.get(2)->val << endl;
    cout << test.get(3)->val << endl;

}