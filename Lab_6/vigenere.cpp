// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Implementing Vigenere cipher encryption

// This program ask the user enters the plaintext and the keyword, and the program reports 
// the ciphertext.


#include <iostream>
#include <cstdlib>
using namespace std;

bool isLetter (char c){
    if (((int)c >= 97 && (int)c <= 122) || (int)c >= 65 && (int)c <= 90){
        return true;
    } else {
        return false;
    }
} 

char shiftChar(char c, int rshift){
    if (isLetter(c) == true){
        int dec = (int)c + rshift;
        if (dec > 90 && (int)c < 97){
            dec = rshift - (90 - (int)c) + 64;
        } else if (dec > 122){
            dec = rshift - (122 - (int)c) + 96;
        } 
        return (char)dec;
    } else {
        return c;
    }
}

string encryptVigenere(string plaintext, string keyword){
    string encryption = "";
    int index = 0;
    int hex, shift;
    char c;
    for (int i = 0; i < plaintext.length(); i++){
        c = keyword[index];
        hex = (int)c;
        if (isLetter(plaintext[i]) == true){
            shift = abs(hex - 97);
            encryption = encryption + shiftChar(plaintext[i], shift);
            index++;
            if (index == 4){
                index = 0;
            }
        } else {
            c = keyword[index];
            encryption = encryption + plaintext[i];
        }
    }
    return encryption;
}

int main() {
  string text = "";
  string keyword = "";
  cout << "Enter plaintext: ";
  getline(cin, text);
  cout << "Enter keyword  : ";
  getline(cin, keyword);
  cout << "Ciphertext     : " << encryptVigenere(text, keyword);
}