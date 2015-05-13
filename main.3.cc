#include <iostream>
#include <string>
#include "priorityqueue.h"


using namespace std;

int main() {
    priorityqueue<string> PQ;
    PQ.push("hello", 1.0);
    PQ.push("world", 4.0);
    PQ.push("this", 5.0);
    
    cout << PQ.front() << endl;
    PQ.pop();
    cout << PQ.front() << endl;
    PQ.pop();
    cout << PQ.front() << endl;
    PQ.pop();
    return 0;
}