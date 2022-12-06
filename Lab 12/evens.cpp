//Name: Maggie Ma
//Email: maggie.ma94@bcmail.cuny.edu
//Date: December 1, 2022
//This program asks the user for two integers and prints out all the even numbers between them

#include <iostream>
using namespace std;

int main(){
    int start;
    int end;
    int range;

  
    cout << "Enter start: ";
    cin >> start;
    cout << "Enter end: ";
    cin >> end;
 
    if (start%2 == 1){
      start = start+1;
    }
  
    if (end-start%2 == 0){
        range = (end - start) / 2;
    } else {
        range = ((end - start) / 2) + 1;
    }

    for (int i = 0; i < range ; i++){
      cout << start << "\n";
      start = start + 2;
    }
  
    return 0;
}