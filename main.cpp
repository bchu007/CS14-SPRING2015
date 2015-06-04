#include <iostream>
#include "dfs.h"

using namespace std;

int main() {
    // int size = 3;
    // vector<vector<bool> >table(3, vector<bool>(3));
    // for(int i = 0; i < size; i++) {
    //     for(int j = 0; j < size; j++) {
    //         table[i][j] = false;
    //         if(i == 0 && j == 1) {
    //             table[i][j] = true;
    //         }
    //         if(i == 1 && j == 2) {
    //             table[i][j] = true;
    //         }
    //         if(i == 2 && j == 0) {
    //             table[i][j] = true;
    //         }
            
    //     }
    // }
    // for(int i = 0; i < table.size(); i++) {
    //     for(int j = 0; j < table.at(i).size(); j++) {
    //         cout << table[i][j] << "\t";
    //     }
    //     cout << endl;
    // }
    
    // dfs(table);
    
    // for(int i = 0; i < table.size(); i++) {
    //     for(int j = 0; j < table.at(i).size(); j++) {
    //         cout << table[i][j] << "\t";
    //     }
    //     cout << endl;
    // }

    vector<vector<bool> >table2(5, vector<bool>(5));
    table2[0][1] = true;
    table2[0][2] = true;
    table2[1][3] = true;
    table2[2][3] = true;
    table2[3][4] = true;
    
    
    for(int i = 0; i < table2.size(); i++) {
        for(int j = 0; j < table2.at(i).size(); j++) {
            cout << table2[i][j] << "\t";
        }
        cout << endl;
    }
    
    dfs(table2,1);
    cout << "after: " << endl;
    for(int i = 0; i < table2.size(); i++) {
        for(int j = 0; j < table2.at(i).size(); j++) {
            cout << table2[i][j] << "\t";
        }
        cout << endl;
    }
    
    return 0;
}