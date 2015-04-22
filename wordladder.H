//Name: Chu, Brian
//Assignment 2: Word Ladders
//student ID: 861174197
//Date: 4/21/15
#include <list>
#include <queue>
#include <stack>
#include <iostream>
#include <fstream>

using namespace std;

class WordLadder {
    public: 
        WordLadder(const string lastfile) {
            fstream fin;
            string input;
            fin.open(lastfile);
            
            
            if(!fin.is_open()) {
                cout << "Error: File never opened" << endl;
            }
            
            while(fin >> input) {
                dict.push_back(input);

            }
            fin.close();
            
        }
        
        void outputLadder(const string start, const string end ) {
            // Create a stack of strings.
            // Push the start word on this stack.
            // Create a queue of stacks.
            // Enqueue this stack.
            
            //While the queue is not empty
            //  For each word in the dictionary
            //      If a word is exactly one letter different (in
            //          any position) from the top string of the front stack
            //              If this word is the end word
            //                  You are done! The front stack plus this
            //                  word is your word ladder. Don’t forget
            //                  to output this word ladder.
            //              Make a copy of the front stack.
            //           Push the found word onto the copy.
            //      Enqueue the copy.
            //  End of for-loop.
            //Dequeue front stack (i.e., remove it from the queue).
            
            if(start.size() != 5) {
                cout << "Error: start size is not 5 letters" << endl;
                return;
            }
            if(end.size() != 5) {
                cout << "Error: end size is not 5 letters" << endl;
                return;
            }
            

            stack<string> wLadder;
            wLadder.push(start);
            queue<stack<string> > wordList;
            wordList.push(wLadder);
            int samelet;
            int letcomp;
            bool more = false;

            


            //remove first word if ever found
            for(auto it = dict.begin(); it != dict.end(); ++it) {
                if(*it == start) {
                    it = dict.erase(it);
                    
                }
            }
            
            int count = fiveLetSameChar(wordList.front().top(), end);

            //loop through wordList until empty
            while(!wordList.empty()) {
                //go through dictionary
                
                for(auto it = dict.begin(); it != dict.end(); it++) {
                    
                    //check if valid word ladder
                    samelet = fiveLetSameChar(*it, wordList.front().top());
                    

                    //found a four letter different word
                    if(samelet == 4) {
                    
                        //found end word
                        if(!(*it).compare(end)) {
                            
                            stack<string> fin = wordList.front();
                            fin = reverse(fin);
                            
                            while(!fin.empty()) {
                                cout << fin.top() << " " << flush;
                                fin.pop();
                            }
                            cout << *it << endl;
                            
                            return;
                        }
                        //compares how many letters are shared with the end
                        letcomp = fiveLetSameChar(*it, end);
                    
                        //check how many words are different
                        count = fiveLetSameChar(wordList.front().top(), end);
                        
                        //if closer to end, set 
                        if( letcomp > count) {
                            count = letcomp;
                            
                             // Make a copy of the front stack.
                            stack<string> copy = wordList.front();
                            
                            
                            // Push the found word onto the copy.
                            copy.push(*it);
                            
                            // Enqueue the copy.
                            wordList.push(copy);
                            
                            //erase word
                            it = dict.erase(it);
                            
                            //go back to beginning
                            it = dict.begin();
                            more = false;
                            
                            
                        }
                        else if(letcomp == count) {
                            more = true;
                        }
                    }   
                    
                    
                }
                if(more == true) {
                    for(auto it = dict.begin(); it != dict.end(); it++) {
                    
                    //check if valid word ladder
                    samelet = fiveLetSameChar(*it, wordList.front().top());
                    
                   
                    
                    //found a four letter different word
                    if(samelet == 4) {
                    
                        //compares how many letters are shared with the end
                        letcomp = fiveLetSameChar(*it, end);
                    
                        //check how many words are different
                        count = fiveLetSameChar(wordList.front().top(), end);
                        
                        //if closer to end, set 
                        if( letcomp == count) {
                            count = letcomp;
                            
                             // Make a copy of the front stack.
                            stack<string> copy = wordList.front();
                            
                            
                            // Push the found word onto the copy.
                            copy.push(*it);
                            
                            // Enqueue the copy.
                            wordList.push(copy);
                            
                            //erase word
                            it = dict.erase(it);
                            
                            //go back to beginning
                            it = dict.begin();
                            
                            
                        }
                        more = false;
                    }   
                    
                    
                }
                }
                wordList.pop();
                
                
            }
            cout << "not found" << endl;
            return;
        }
        
        int fiveLetSameChar(string one, string two) {
            int shared = 0; 
            for(int i = 0; i < 5; i++) {
                if(one.at(i) == two.at(i)) {
                    shared++;
                }
            }
            return shared;
        }
        
        stack<string> reverse(stack<string> fin) {
            stack<string> one;
            while(!fin.empty()) {
                one.push(fin.top());
                fin.pop();
            }
            return one;
        }
        
    private:
        list<string> dict;
        
        
};