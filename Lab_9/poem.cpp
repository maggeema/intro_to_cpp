// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Fix the program so that it does not crash our computer

// You are provided with the following program poem.cpp. All is good, and the memory is allocated 
// dynamically, but it crashes your computer, because it runs out of memory really quickly:

// #include <iostream>
// using namespace std;

// string * createAPoemDynamically() {
//     string *p = new string;
//     *p = "Roses are red, violets are blue";
//     return p;
// }

// int main() {
//     while(true) {
//         string *p;
//         p = createAPoemDynamically();

//         // assume that the poem p is not needed at this point

//     }
// }
// Fix this program poem.cpp. It should still keep creating poems, but all dynamically allocated 
// memory should get deleted when it is not needed. (The program can be stopped with Ctrl+C in 
// the terminal.)

#include <iostream>
using namespace std;

string * createAPoemDynamically() {
    string *p = new string;
    *p = "Roses are red, violets are blue";
    return p;
}

int main() {
    while(true) {
        string *p;
        p = createAPoemDynamically();

        // assume that the poem p is not needed at this point
        delete p;
    }
    return 0;
}