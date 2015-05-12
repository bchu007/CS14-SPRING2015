//Name: Brian Chu
//SID: 861174197
//Date: May 4, 2015

#include <iostream>
#include "lab5.h"

using namespace std;

int main() {
    BST<int> tree1;
    tree1.insert(50);
    tree1.insert(20);
    tree1.insert(60);
    tree1.insert(10);
    tree1.insert(40);
    tree1.insert(35);
    tree1.insert(45);
    tree1.insert(70);
    
    tree1.minCover();
    tree1.displayMinCover();
    cout << endl << tree1.getMarkSize() << endl;

    //int* buffer;
    cout << endl << "Part 2" << endl;
    tree1.findSumPath(80);
    
    
    map<int, int> m;
    cout << endl << "Part 3" << endl;
    tree1.vertSum(m);
    return 0;
}