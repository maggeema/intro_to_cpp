/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Dictionary Operations

This program returns:
    Integer index of the word in `g_words` global-array. Returns -1 if the word is not found.
    The string definition of the word from  `g_definitions` global-array; Return 
    "NOT_FOUND" if word doesn't exist in the dictionary.  
    Return the string part-of-speech(pos) from the `g_pos` global-array; Return "NOT_FOUND" 
    if the word doesn't exist in the dictionary.
    Integer number of words found that starts with the given `prefix`
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
using namespace std;


const int g_MAX_WORDS = 1000;
int g_word_count = 0;
string filename;

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
        colon = line.substr(0, line.find(" :"));
        word = colon.substr(0, line.find(" "));
        pos = colon.substr(line.find(" ")+1, line.find("\n"));
        def = line.substr(line.find(":")+2, line.find("\n"));

        g_words[g_word_count] = word;
        g_pos[g_word_count] = pos;
        g_definitions[g_word_count] = def;

        g_word_count++;
  }
  fin.close();
}

int getIndex(string word){
    int index;
    // loop through the list of words to find the matching word
    for (int i = 0; i < g_word_count; i++){
        if (g_words[i] == word){
            // if the word matches, assign it to the variable index
            index = i;
            break;
        } else {
            // if it doesnt match, assign it as -1
            index = -1;
        }
    }
    // if the index had not matched any of the words, the int index would have been assigned
    // ... -1, which means it was not part of the array of words
    return index;
}

string getDefinition(string word){
    string def = "";
    // loop through the list of words to find the matching word
    for (int i = 0; i < g_word_count; i++){
        if (g_words[i] == word){
            // if the word matches, find the definition with the same index in def array
            def = g_definitions[i];
            break;
        } else {
            // if the word doesnt or never matches, it'll be automatically be set to an error
            // ... message
            def = "NOT_FOUND";
        }
    }
    // if the word was never found, the def would've been automatically set to "NOT_FOUND",
    // ... which means there is no definition to the word provided
    return def;
}

string getPOS(string word){
    string pos = "";
    // loop through the list of words to find the matching word
    for (int i = 0; i < g_word_count; i++){
        if (g_words[i] == word){
            // if the word matches, assign pos to the matching index within the pos array
            pos = g_pos[i];
            break;
        } else {
            // otherwise, automatically set the pos string to the error message
            pos = "NOT_FOUND";
        }
    }
    // if the pos was never found for the word, it would've automatically been set to the 
    // ... message "NOT_FOUND"
    return pos;
}

int countPrefix(string prefix){
    int count = 0;
    bool matching;
    // loop through the array of words
    for (int i = 0; i < g_word_count; i++){
        // loop through the letters of the word at index i
        for (int k = 0; k < prefix.length(); k++){
            // if a letter matches, for now, indicate that the word matches with the letters
            // ... so far, then it is true that the prefix matches the word
            if (g_words[i][k] == prefix[k]){
                matching = true;
            } else {
                // if the letters start to not match, automatically break out of the loop
                // ... because they do not have the same prefix then
                matching = false;
                break;
            }
        }
        // if loop had been broken because the letters dont match up, it would've not been 
        // the same prefix, and so we don't need to keep count. otherwise, keep count 
        // of all the words that DID have matching prefixes (must be the ones that did NOT
        // break the loop then)
        if (matching == true){
            count++;
        } 
    }
    // return the number of words that were tallied along the way with the same prefix
    return count;
}

// int main(){
//     cout << "Enter file name: ";
//     cin >> filename;
//     readWords(filename);

//     int index = getIndex("Professor");
//     string def = getDefinition("Grumpy");
//     string pos = getPOS("Maggie");
//     int prefix = countPrefix("No");

//     cout << index << "\n" << def << "\n" << pos << "\n" << prefix << "\n";
// }