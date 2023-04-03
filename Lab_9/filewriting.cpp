// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: E8.1

// Write a program that carries the following tasks: Open a file with the name hello.txt.
// Store the message "Hello, World!" in the file. Close the file. Open the same file
// again. Read the message into a string variable and print it. 

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    fstream f;
    ofstream fout;
    ifstream fin;

    fin.open("hello.txt");
    if (fin.is_open()){
        fout << "Hello, World!";
    }
    fout.close();
    string hello;
    f.open("hello.txt");
    while (f >> hello){
        cout << hello;
    }
    return 0;
}