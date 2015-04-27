///////////////////////////////////////////////
// Name: Chu, Brian
// SID: 861174197
// Date: April 20, 2015
// Approach: ?
///////////////////////////////////////////////
#ifndef __LAB3_H__
#define __LAB3_H__

#include <iostream>
#include <array>

using namespace std;

template <typename T>
// typedef int T;

class TwoStackFixed {
    public:
    
        TwoStackFixed(int size, int maxtop)
        :top1(-1), top2(size), split(maxtop), size(size) { 
            if(maxtop >= size) {
                cout << "Error: maxtop is greater than array size" << endl;
                return;
            }
            ptr = new T[size];
            
        }
        void pushStack1(T value) {
            if(top1 > split) {
                cout << "Invalid: stack1 full" << endl;
                return;
            }
            
            top1++;
            ptr[top1] = value;

            
            
        }
        void pushStack2(T value) {
            if(isFullStack2()) {
                cout << "Invalid: stack2 full" << endl;
                return;
            }
            top2--;
            ptr[top2] = value;
        }
        T popStack1() {
            if(isEmptyStack1()) {
                cout << "Invalid: stack1 empty" << endl;
                return 0;
            }
            top1--;
            return ptr[top1 + 1];
        }
        
        T popStack2() {
            if(isEmptyStack2()) {
                cout << "Invalid: stack2 empty" << endl;
                return 0;
            }
            top2++;
            return ptr[top2 - 1];
        }
        bool isFullStack1() {
            if(top1 > split) return true;
            return false;
        }
        bool isFullStack2() {
            if(top2 <= split) return true;
            return false;
        }
        bool isEmptyStack1() {
            if(top1 == -1) return true;
            return false;
        }
            
        bool isEmptyStack2() {
            if(top2 == size) return true;
            return false;
        }
        void display() {
            for(int i = 0; i < size; i++) {
                cout << i << ": " << ptr[i] << " " << endl;
            }
            cout << endl;
        }
        
    private:
        
        T *ptr;
        int top1;
        int top2;
        int size;
        int split;
    
        
    
};

template <typename T>
class TwoStackOptimal {
    public:
        TwoStackOptimal(int size)
        : top1(-1), top2(size) {
            sz = size;
            ptr = new T[size];
            
        }
        void pushFlexStack1(T value) {
            if(top1 + 1 == top2 && top1 + 1 == sz) {
                cout << "Invalid: stacks full" << endl;
                return;
            }
            
            top1++;
            ptr[top1] = value;
            
        }
        void pushFlexStack2(T value) {
            if(top2 - 1 == top1 && top2 == 0) {
                cout << "Invalid: stacks full" << endl;
                return;
            }
            
            top2--;
            ptr[top2] = value;
        }
        
        bool isFullStack1() {
            if(top1 + 1 == top2) {
                return true;
            }
            return false;
        }
        
        bool isFullStack2() {
            if(top2 - 1 = top1) {
                return true;
            }
            return false;
        }
        
        bool isEmptyStack1() {
            if(top1 == -1) {
                return true;
            }
            return false;
        }
        
        bool isEmptyStack2() {
            if(top2 == sz) {
                return true;
            }
            return false;
        }
        
        void display() {
            cout << "stack 1: " << flush;
            for(int i = 0; i <= top1; i++) {
                cout << ptr[i] << " " << flush;
            }
            
            cout << endl << "stack 2: " << flush;
            for(int j = sz - 1; j >= top2; j--) {
                cout << ptr[j] << " " << flush;
            }
            cout << endl;
        }
        
        
        
    
    private:
        T* ptr;
        int top1;
        int top2;
        int sz;
        
    
};

#endif