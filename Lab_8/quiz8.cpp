// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Quiz 8

// This program takes in a string and returns the number of unbalanced brackets.
// In other words, returns the difference of open and closed curly brackets.
#include <iostream>
using namespace std;

// int unbalanced_brackets(string input){
//     int open = 0;
//     int closed = 0;
//     string checked = "";
//     for (int i = 0; i < input.length(); i++){
//         checked = checked + input[i];
//         if (checked.find('{')){
//             open++;
//             checked = checked + input[i+1];
//         } else {
//             closed++;
//             checked = checked + input[i+1];
//         }
//     }
//     return open - closed;
// }

// int main(){
//     int input;
//     cout << "Enter a string: ";
//     cin >> input;
//     cout << unbalanced_brackets(input);
// }


int unbalanced_brackets(string input){
    int open = 0;
    int closed = 0;
  int result;
    for (int i = 0; i < input.length(); i++){
        if (input[i] == '{'){
            open++;
        } else {
            closed++;
        }
    }
    result = open - closed;
    return result;
}

int main(){
    string input;
    cout << "Enter a string: ";
    cin >> input;
    cout << unbalanced_brackets(input);
}