//Name: Maggie Ma
//Email: maggie.ma94@bcmail.cuny.edu
//Date: December 13, 2022
//This program asks the user for a whole number / positive integer between 0 and 255 ...
//... and prints out the number in "two's complement" notation

#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main(){
  int num;

  cout <<  "I can convert positive and integers into\nan 8-bit binary! Enter an integer in [0, 255]: ";
  cin >> num;

  string backwards = "";
  string binary = "";
  
  for (int i = 7; i > -1; i--){
    if (num >= pow(2, i)){
      if (num % 2 == 1){
        backwards.append("1");
      } else if (num == pow(2, i)){
        binary.append("1");
        num = 0;
      } else {
        backwards.append("0");
      }
      num = num/2;
    } else {
      binary.append("0");
    }
  }
  
  //print the current binary string backwards to be correct if it is not exactly a power of 2
  for (int j = 7; j > -1; j--){
    binary = binary + backwards[j];
  }
  cout << binary;
}
