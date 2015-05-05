//Name: Brian Chu
//SID: 861174197
//Date: April 27, 2015
#include <iostream>

using namespace std;



void preorder(int k, int m, int n) {
    if(m + n > k) {
        return;
    }
    cout << m << " " << n << endl;
    preorder(k, (2*m - n), m);
    
    preorder(k, (2*m + n), m);
    
    preorder(k, (m + 2*n), n);
    
}

void preorder(int k) {
    
    preorder(k, 2, 1);    
    preorder(k, 3, 1);
}

void postorder(int k, int m, int n) {
    
    if(m + n > k) {
        return;
    }
    
    
    
    //left
    
    postorder(k, (2*m - n), m);
    
    //mid
    postorder(k, (2*m + n), m);
    
    //right
    postorder(k, (m + 2*n), n);
    cout << m << " " << n << endl;


    
}

void postorder(int k) {
    
    postorder(k, 2, 1);    
    postorder(k, 3, 1);
}

