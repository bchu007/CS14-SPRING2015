///////////////////////////////////////////////
// Name: Chu, Brian
// SID: 861174197
// Date: April 20, 2015
// Approach: ?
///////////////////////////////////////////////

#include <iostream>
#include <stack>
#include "lab3.h"

using namespace std;
// typedef int T;

template <typename T>
void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C);

template <typename T>
void display(stack<T>& A, stack<T>& B, stack<T>& C);

int main() {
    //problem 1
    TwoStackFixed<int> stack1(10, 5);
    stack1.pushStack1(5);
    stack1.pushStack1(4);
    stack1.pushStack1(3);
    stack1.pushStack1(2);
    stack1.pushStack1(1);
    
    stack1.pushStack2(10);
    stack1.pushStack2(20);
    stack1.pushStack2(30);
    stack1.pushStack2(40);
    stack1.pushStack2(50);
    stack1.pushStack2(60);

    stack1.display();
    

    stack1.popStack1();
    stack1.popStack1();
    stack1.popStack1();
    stack1.popStack1();
    stack1.popStack1();

    stack1.display();
    
    //problem 2
    TwoStackOptimal<int> s(10);
    s.pushFlexStack1(1);
    s.pushFlexStack1(2);
    s.pushFlexStack1(3);
    s.pushFlexStack1(4);
    s.pushFlexStack1(5);
    s.pushFlexStack1(6);
    s.pushFlexStack2(10);
    s.pushFlexStack2(20);
    s.pushFlexStack2(30);
    s.display();
    
    //ex 3
    stack<int> s1;
    stack<int> s2;
    stack<int> s3;
    
    s1.push(10);
    s1.push(9);
    s1.push(8);
    s1.push(7);
    s1.push(6);
    s1.push(5);
    s1.push(4);
    s1.push(3);
    s1.push(2);
    s1.push(1);
    
    display(s1, s2, s3);
    showTowerStates(s1.size(), s1, s2, s3);
    display(s1, s2, s3);
    
    return 0;
}

template <typename T>
void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C) {


    if(n != 0) {
        showTowerStates(n-1, A, C, B);
        C.push(A.top());
        A.pop();
        showTowerStates(n-1, B, A, C);
    }
    
}

template <typename T>
void display(stack<T>& A, stack<T>& B, stack<T>& C) {
    stack<T>  s1 = A;
    stack<T>  s2 = B;
    stack<T>  s3 = C;
    
    cout << "STACK 1: ";
    while(!s1.empty()) {
        cout << s1.top() << " " << flush;
        s1.pop();
    }
    cout << endl;
    
    cout << "STACK 2: ";
    while(!s2.empty()) {
        cout << s2.top() << " " << flush;
        s2.pop();
    }
    cout << endl;
    
    cout << "STACK 3: ";
    while(!s3.empty()) {
        cout << s3.top() << " " << flush;
        s3.pop();
    }
    cout << endl;
}












