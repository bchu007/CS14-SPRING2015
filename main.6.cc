#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include "lab6.h"

using namespace std;


int main() {
    vector<int> v;
    v.push_back(10);
    v.push_back(5);
    v.push_back(7);
    v.push_back(2);
    v.push_back(0);
    v.push_back(80);
    
    cout<< "vector of ints" << endl;
    cout << "pre: ";
    for(int i = 0; i < v.size(); i++) {
     cout << v.at(i) << " " << flush;   
    }
    cout << endl;
    selectionsort<vector<int> >(v);
    cout << "post: ";
    for(int i = 0; i < v.size(); i++) {
     cout << v.at(i) << " " << flush;   
    }
    cout << endl;
    cout << "moves: " << numMoves << endl;
    
    list<int> v2;
    v2.push_back(1);
    v2.push_back(45);
    v2.push_back(34);
    v2.push_back(152);
    v2.push_back(3);
    v2.push_back(87);
    v2.push_back(3);
    
    cout << "list of ints" << endl;
    cout << "pre: ";
    for(list<int>::iterator it = v2.begin(); it != v2.end(); it++) {
      cout << *it  << " ";
    }
    cout << endl;
    selectionsort<list<int> >(v2);
    cout << "post: ";
    for(list<int>::iterator it = v2.begin(); it != v2.end(); it++) {
      cout << *it << " " ;
    }
    cout << endl;
    cout << "moves: " << numMoves << endl;
    
    //pair example 2
    // multimap<int, int> m;
    // m.insert(make_pair<int, int>(1, 2));
    // m.insert(make_pair<int, int>(3,-1));
    // m.insert(make_pair<int, int>(-1,3));
    // m.insert(make_pair<int, int>(0, 0));
    // m.insert(make_pair<int, int>(2, 3));
    // m.insert(make_pair<int, int>(1, 2));
    // m.insert(make_pair<int, int>(1,-2));
    // m.insert(make_pair<int, int>(8,10));
    
    // selectionsort<multimap<pair<int, int> > >(m);

    
    return 0;
}

// template <typename L>
// void selectionsort(L &l) {
//     numMoves = 0;
//     for(auto it = l.begin(); it != l.end(); it++){
//         // cout << "test: FIRST LOOP: " << *it <<  endl;
//         auto ptr = next(it);
//         auto min = it;
//         for(auto it2 = ptr; it2 != l.end(); it2++) {
//             // cout << "test: SECOND LOOP: " << *it2 << endl;
//             if(*it2 < *it) {
//                 // cout << "NEW MIN: " << "IT2: " << *it2 << " IT" << *it << endl;
//                 min = it2;
//             }
//             ptr = next(ptr);
//         }
//         swap(*it, *min);
//         numMoves += 3;
//     }
    
// }

