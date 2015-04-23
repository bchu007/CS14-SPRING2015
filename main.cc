//Name: Chu, Brian
//Assignment 2: Word Ladders
//student ID: 861174197
//Date: 4/21/15


// main.cc
#include "wordladder.H"
#include <cstdlib>
int main( int argc, char* argv[] ) {
    if ( argc != 4 ) {
        cout << "Usage: wordladder <dictionary_file> <start_word> <end_word>\n";
        exit(-1);
    }

    WordLadder wl(argv[1]);
    
    wl.outputLadder(argv[2], argv[3]);

    return 0;
}