// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Implementing Caesar sipher encryption

// This program ask the user to input a plaintext sentence, then enter the right shift, and 
// report the ciphertext computed using your encryption function.

#include <iostream>
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

string encryptCaesar(string plaintext, int rshift){
    string encryption = "";
    for (int i = 0; i < plaintext.length(); i++){
        if (isLetter(plaintext[i]) == true){
            encryption = encryption + shiftChar(plaintext[i], rshift);
        } else {
            encryption = encryption + plaintext[i];
        }
    }
    return encryption;
}

int main() {
  string text = "";
  int shift;
  cout << "Enter plaintext: ";
  getline(cin, text);
  cout << "Enter shift    : ";
  cin >> shift;
  cout << "Ciphertext     : " << encryptCaesar(text, shift);
}