// lab 1: intro to c++, review
// this program asks user for an age, and prints out the input

#include <iostream>
using namespace std;

int main() {
  cout << "Enter your age: " << endl;
  int age = 0;
  cin >> age;

  cout << "Your age is " << age << "." endl;
}

// to compile code, do "g++ -o myprog code.cpp"
// to run the produced program, ./myprogram
// to compile the program without giving the output file name...
// you can just do ./a.out