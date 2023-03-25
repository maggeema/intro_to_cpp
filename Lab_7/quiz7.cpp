/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Quiz 7

Define a function remove_e that takes a string and removes all 'e' characters from the original string.
Your function should not return a new string. 
*/

#include <iostream>
using namespace std;

void remove_e(string s){
    int index = s.find('e');
    for (int i = index; i < s.length(); i++){
        if (s[i] == 'e'){
            i = i+1;
            // for (int k = i; k < s.length(); k++){
            //     s[i] = s[i+1];
            //     if (s[i+1] == 'e'){
            //         k = i + 1;
            //     }
            // }
            // s[i] = '';
        }
    }
    cout << s;
}

int main(){
    string s = "elephant";
    remove_e(s);
}