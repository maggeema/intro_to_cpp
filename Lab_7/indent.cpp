// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Counting blocks opened and closed by { and } and adding real indentation

// This program enhances the program from the previous task. As it reads the input line by 
// line, it should also count the number of open and closed { } in it, and keep track of how 
// many blocks is currently open at the beginning of each line.

#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

string removeLeadingSpaces(string line){
    string result = "";
    for (int i = 0; i < line.length(); i++){
        if (i == 0 && isspace(line[i])){
            continue;
        } else if ((isspace(line[i])) && (!isspace(line[i-1]) && !isspace(line[i+1]))){
                result = result + line[i];
        } else if (!isspace(line[i])){
            result = result + line[i];
        } 

    }
    return result;
}

int countChar(string line, char c){
    int count = 0; 
    for (int i = 0; i < line.length(); i++){
        if (line[i] == c){
            count++;
        }
    }
    return count;
}

string addIndent(string line){
    line = '\t' + line;
    return line;
}

int main(){

    string line;
    int tab = 0;

    while(getline(cin, line)){
        line = removeLeadingSpaces(line);

        if (countChar(line, '}') > 0){
            if (countChar(line, '{') > 0){
                tab;
                if (line.find('{') > line.find('}')){
                    tab--;
                }
            } else {
                tab--;
            }
        } 

        // if ((countChar(line, '{') > 0) && (line.find('}') > line.find('{'))){
        //     cout << line << endl;
        //     continue;
        // }
        // if (countChar(line, '}') > 0){
        //     tab--;
        // }
        
        for (int i = 0; i < tab; i++){
            line = addIndent(line);
        }

        cout << line << endl;

        

        if (countChar(line, '{') > 0){
            if (countChar(line, '}') > 0){
                if (countChar(line, '}') < countChar(line, '{')){
                    for (int k = 0; k < countChar(line, '{'); k++){
                        tab++;
                    }
                    tab = tab - (countChar(line, '}'));
                } else if (line.find('{') > line.find('}')){
                    tab++;
                } else {
                    tab;
                }
            } else {
                for (int k = 0; k < countChar(line, '{'); k++){
                    tab++;
                }
            }
        } 
    }

    return 0;
}