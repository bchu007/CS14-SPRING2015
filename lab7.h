#include <iostream>
#include <set>
#include <unordered_set>
#include <chrono>
#include <sstream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

vector<string> InputFile() {
    fstream fin;
    fin.open("words.txt");
    
    if(!fin.is_open()) {
        cout << "file not opened" << endl;
    }
    vector<string> v;
    string input;
    while(fin >> input) {
        v.push_back(input);
    }
    
    fin.close();
    return v;
}

void scramble(vector<string> &v) {
    rand(time(0));
    for(int i = 0; i < v.size(); i++) {
        string first = v.at(i);
        int random = rand() % v.size();
        string second = v.at(random);
        v.at(i) = second;
        v.at(random) = first;
    }
}

void FindTimeSet(int num, vector<string> v, set<string> s) {
    if(v.size() > num) {
        cout << "size too large" << endl;
        return;
    }
    
    auto start = chrono::high_resolution_clock::now();
    for(int i = 0; i < num; i++) {
        s.insert(v.at(i));
    }
    auto end = chrono::high_resolution_clock::now();
    // cout << "seconds " << chrono::duration_cast<chrono::seconds> (end - start).count()  << endl;
    // cout << "milliseconds " << chrono::duration_cast<chrono::milliseconds> (end - start).count()  << endl;
    // cout << "microseconds " << chrono::duration_cast<chrono::microseconds> (end - start).count() << endl;
    // cout << "nanoseconds " << chrono::duration_cast<chrono::nanoseconds> (end - start).count()  << endl;
}


int FindTimeSet(int num, vector<string> v, unordered_set<string> s) {
    if(v.size() > num) {
        cout << "size too large" << endl;
        return -1;
    }
    
    auto start = chrono::high_resolution_clock::now();
    for(int i = 0; i < num; i++) {
        s.insert(v.at(i));
    }
    auto end = chrono::high_resolution_clock::now();
    // cout << "seconds " << chrono::duration_cast<chrono::seconds> (end - start).count()  << endl;
    // cout << "milliseconds " << chrono::duration_cast<chrono::milliseconds> (end - start).count()  << endl;
    // cout << "microseconds " << chrono::duration_cast<chrono::microseconds> (end - start).count() << endl;
    // cout << "nanoseconds " << chrono::duration_cast<chrono::nanoseconds> (end - start).count()  << endl;
    
    return static_cast<int>(chrono::duration_cast<chrono::nanoseconds> (end - start).count());
}