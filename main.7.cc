#include <iostream>
#include <vector>
#include "lab7.h"

using namespace std;

int main() {
    vector<string> stuff;
    stuff = InputFile();
    // for(auto it = stuff.begin(); it != stuff.end(); it++) {
    //     cout << *it << endl;
    // }
    set<string> s;
    FindTimeSet(50000, stuff, s);
    cout << endl;
    unordered_set<string> us;
    cout << FindTimeSet(50000, stuff, us);
    return 0;
}