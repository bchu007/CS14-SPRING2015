//Name: Brian Chu
//SID: 861174197
//Date: April 27, 2015

#include <iostream>
#include <stack>
#include <queue>
#include <utility>
#include "lab4.h"

class sort {
    public:
        sort(int k): k(k) {};
        void sorted(int k, int m, int n) {
            if(m + n > k ) {
                return;
            }
            
            pair<int, int> insert = make_pair(m , n);
            Q.push(insert);
        
            sorted(k, (2*m - n), m);
            sorted(k, (2*m + n), m);
            sorted(k, (m + 2*n), n);
        }
        
        void sorted(int k) {
            sorted(k, 2, 1);    
            sorted(k, 3, 1);

        return;
        }
        
        void print(pair<int, int> p) {
            cout << p.first << " " << p.second << flush;
        }
                
        void print() {
            stack<pair<int, int> > s;
            while(!Q.empty()) {
                s.push(Q.top());
                Q.pop();
            }
            while(!s.empty()) {
                print(s.top());
                cout << endl;
                s.pop();
            }
        }
    private:
        int k;
        priority_queue<pair<int, int> > Q;
};




int main() {
    
    int k = 9;
    cout << "preorder" << endl;
    preorder(k);
    
    
    k = 8;
    cout << endl << "postorder" << endl;
    postorder(k);
    
    
    cout << endl << "inorder" << endl;
    k = 8;
    sort blah(k);
    blah.sorted(k);
    blah.print();
    
    
    
    return 0;
}