#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <map>
#include <set>
#include <utility>
#include <queue>

using namespace std;

int numMoves = 0;


template <typename L>
void selectionsort(L &l) {
    numMoves = 0;
    for(auto it = l.begin(); it != l.end(); it++){
        // cout << "test: FIRST LOOP: " << *it <<  endl;
        auto ptr = next(it);
        auto min = it;
        for(auto it2 = ptr; it2 != l.end(); it2++) {
            // cout << "test: SECOND LOOP: " << *it2 << endl;
            if(*it2 < *it) {
                // cout << "NEW MIN: " << "IT2: " << *it2 << " IT" << *it << endl;
                min = it2;
            }
            ptr = next(ptr);
        }
        swap(*it, *min);
        numMoves += 3;
    }
    
}