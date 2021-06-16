#include <cctype>
#include <iostream>
#include <bitset>

using namespace  std;

char first_recurring(const string & s){
    bitset<26> alphabet;
    for (char c: s){
        int index = 0;
        if (isupper(c))
            index = c - 'A';
        else
            index = c - 'a';
        if (alphabet[index] == 1)
            return c;
        alphabet[index] = 1;
    }
    return '\0';
}

int main(){
    string s = "acbbac";
    cout << first_recurring(s) << endl;
    s = "TESTINGTHIS";
    cout << first_recurring(s) << endl;
    s = "abcdef";
    cout << first_recurring(s) << endl;

    return 0;
}