#include <vector>
#include <map>

using namespace std;

void dfs(vector<vector<bool> >& adjacency, unsigned start = 0) {
    // static map<unsigned, bool> visited;
    static vector<bool> visited;
    visited.resize(adjacency.size());
    static int recursionDepth = 0; 
    ++recursionDepth;
    int i = start;
    int allfalse = 0;

    for(int j = 0; j < adjacency.at(i).size(); j++) {
        if(adjacency.at(i).at(j)) {
            // cout << "linked: " << i << " " << j << endl;
            visited.at(i) = true;
            if(visited.at(j)) {
                // cout << "visited: " << i << " " << j << endl;
                adjacency.at(i).at(j) = false;
            }
            else {
                dfs(adjacency, j);
            }
        }
        allfalse++;
        
        
    }
    if(allfalse == adjacency.size()) {
        visited.at(i) = true;
    }
    
    
    --recursionDepth;
    if(recursionDepth == 0) {
        for(int i = 0; i < visited.size(); i++) {
            if(!visited.at(i)) {
                // cout << "goto " << i << endl;
                dfs(adjacency, i);
            }
        }
        // cout << endl;
        visited.clear();
    }
    
    
}