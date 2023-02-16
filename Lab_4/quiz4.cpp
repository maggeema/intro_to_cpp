// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Quiz 4

// This program reads a file called "data.txt", which contains lines of text with names of 
// colors and their hex valules, reads and prints each lines and closes the file after 
// processing it.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main(){
    ifstream fin("data.txt");
    string line;

    if (fin.fail()){
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }

    getline(fin, line);

    while(fin){
        cout << line << endl;
        getline(fin, line);
    }
    fin.close();
}