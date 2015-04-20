//Name: Brian Chu
//SID: 861174197
//Date: 4/13/15


#include <iostream>
#include <forward_list>
#include <string>
#include <vector>

#include "lab2.h"

using namespace std;


int primeCount( forward_list<int> lst );
bool isPrime(int j);

template<typename T>
void listCopy(forward_list<T>L, forward_list<T> &P);

template<typename T>
void printLots(forward_list<T> L, forward_list<int> P);

int main() {\
    //question #1
    
    forward_list<int> lst1(0);
    lst1.push_front(30);
    lst1.push_front(20);
    lst1.push_front(10);
    lst1.push_front(7);
    lst1.push_front(5);
    lst1.push_front(3);
    lst1.push_front(2);
    
    cout << "Number of prime in list: " << primeCount(lst1) << endl;
    
    //question #2
    
    List<int> list1(50);
    list1.push(40);
    list1.push(30);
    list1.push(20);
    list1.push(10);
    list1.display();
    
    list1.elementSwap(3);
    list1.display();
    
    
    // list1.elementSwap(2);
    // list1.display();
    
    //question 3
    forward_list<char> L = {'h', 'e', 'l', 'l', 'o'};
    forward_list<char> P = {'w', 'o', 'r', 'l', 'd'};
        
    listCopy(L, P);
    for(auto it = P.begin(); it != P.end(); ++it) {
        cout << *it << flush; 
    }
    cout << endl;
    
    forward_list<char> L2 = {'h', 'e', 'l', 'l', 'o'};
    forward_list<int> P2 = {1, 4, 5};
    printLots(L2, P2);
    
    cout << endl;
    return 0;
}

bool isPrime(int i) {
    for(int j = 2; j < i; j++) {
        if(i % j == 0) {
            return false;
        }
    }
    return true;
}

int primeCount( forward_list<int> lst ) {
    int primecounter = 0;
    for(auto it = lst.begin(); it != lst.end(); ++it) {
        if(isPrime(*it)){
            cout << *it << " is prime" << endl; 
            primecounter++;
        }
    }
    return primecounter;
}

template <typename T>
void listCopy(forward_list<T>L, forward_list<T> &P) {
       
    forward_list<T> pCopy(P);

    
    pCopy.reverse();
    P.clear();
    
    for(auto it = L.begin(); it != L.end(); ++it) {
        P.push_front(*it);
    }
    for(auto it = pCopy.begin(); it != pCopy.end(); ++it) {
        P.push_front(*it);
    }
    
    
    
}

template <typename T>
void printLots(forward_list<T> L, forward_list<int> P) {
    vector<int> store;
    for(auto it = P.begin(); it != P.end(); ++it) {
        store.push_back(*it);
    }
    int index = 0;
    for(auto it = L.begin(); it != L.end(); ++it) {
        for(int i = 0; i < store.size(); i++) {
            if(index == i) {
                cout << *it << flush;
            }
        }
        index++;
    }

}

