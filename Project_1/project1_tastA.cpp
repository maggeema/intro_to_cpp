/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Dictionary using Arrays

This program read through a dictionary that contains the words and the definitions. In 
addition to the words and the definitions, we will also store the part-of-speech (pos). 
The words, definitions and pos are going to be stored in Arrays. 
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
using namespace std;


const int g_MAX_WORDS = 1000;
int g_word_count = 0;

string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];

void readWords(string filename){
  string line, colon, word, pos, def;

    ifstream fin(filename);
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); 
    }

  while (getline(fin, line)){
        // extract the words before the colon in the line 
        colon = line.substr(0, line.find(" :"));
        // extract the word before the space that is before the colon
        word = colon.substr(0, line.find(" "));
        // extract the word after the first space and the colon
        pos = colon.substr(line.find(" ")+1, line.find("\n"));
        // whatever is after the colon to the last character in the line is the definition
        def = line.substr(line.find(":")+2, line.find("\n"));

        g_words[g_word_count] = word;
        g_pos[g_word_count] = pos;
        g_definitions[g_word_count] = def;

        // every line read means it is a word being defined
        g_word_count++;
  }
  fin.close();
}
         

// int main(){
//     cout << "Enter file name: ";
//     cin >> filename;
//     readWords(filename);

//     cout << g_MAX_WORDS << endl;
//     cout << g_word_count << endl;

//     for (int i = 0; i < g_word_count; i++){
//     cout << g_words[i] << " " << g_pos[i] << g_definitions[i] << endl;
//     }
// }