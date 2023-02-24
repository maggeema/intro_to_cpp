/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Checkerboard (3x3)

This program asks the user to input width and height and prints a checkerboard of 3-by-3 
squares. (It should work even if the input dimensions are not a multiple of three.)
*/

#include <iostream>
using namespace std;

int main() {
  int width, height;
  char ch = '*';
  int w_ch = 0;
  int w_space = 0;
  int h_count = 0;
  bool wch3 = true;
  bool hch3 = true;

  cout << "Input width: ";
  cin >> width;
  cout << "Input height: ";
  cin >> height;
  cout << "\nShape:\n";

  for (int i = 0; i < height; i++){
    for (int k = 0; k < width; k++){

        if (wch3 == true){
          cout << ch;
          w_ch++;
          if (w_ch == 3){
            wch3 = false;
            w_ch = 0;
          }
        } else {
          cout << " ";
          w_space++;
          if (w_space == 3){
            wch3 = true;
            w_space = 0;
          }
        }
      
    }
    
    cout << "\n";
    h_count++;
    
    w_ch = 0;
    w_space = 0;
    if (hch3 == true){
      wch3 = true;
    } else {
      wch3 = false;
    }

    if (h_count == 3){
      if (hch3 == true){
        hch3 = false;
        wch3 = false;
        h_count = 0;
      } else {
        hch3 = true;
        wch3 = true;
        h_count = 0;
      }
    }

    
  }
  
}

// ---------------- FIRST ATTEMPT: FAILED -------------------- 

// #include <iostream>
// using namespace std;

// int main(){
//     int width, height;
//     int col_multiple = 0;
//     int row_multiple = 0;
//     char ch = '*';

//     cout << "Input width: ";
//     cin >> width;
//     cout << "Input height: ";
//     cin >> height;
//     cout << "\nShape:\n";

//     for (int i = 0; i < height; i++){
//         for (int k = 0; k < width; k++){
//             // if width is 16 and height is 11:
//             // when i = 0, and k = 0, 1 or 2 print char
//             // when i = 0, and k = 3, 4 or 5, print space
//             // when i = 3, and k = 0, 1 or 2 print space
//             // when i = 3, and k = 3, 4 or 5 print char

//             if (row_multiple % 2 == 1){
//                 if ((3*row_multiple <= i) && (i < 3*row_multiple+1)){
//                     if (col_multiple % 2 == 1){
//                         if ((3*col_multiple <= k) && ( k < 3*col_multiple+1)){
//                             cout << ch;
//                         }
//                     } else {
//                         if ((3*col_multiple <= k) && (k < 3*col_multiple+1)){
//                             cout << " ";
//                         }             
//                     }
//                 }
//             } else {
//                     if ((3*row_multiple <= i) && (i < 3*row_multiple+1)){
//                         if (col_multiple % 2 == 1){
//                             if (3*col_multiple <= k < 3*col_multiple+1){
//                                 cout << " ";
//                             }
//                         } else {
//                             if ((3*col_multiple <= k) && (k < 3*col_multiple+1)){
//                                 cout << ch;
//                             }             
//                         }
//                 }             
//             }
//         }
        
//         cout << "\n";

//     }
// }





// --------------------- SECOND ATTEMPT: FAILED ---------------------
// #include <iostream>
// using namespace std;

// int main(){
//     int width, height;
//     int col_multiple = 0;
//     int row_multiple = 0;
//     char ch = '*';

//     cout << "Input width: ";
//     cin >> width;
//     cout << "Input height: ";
//     cin >> height;
//     cout << "\nShape:\n";

//     for (int i = 0; i < height; i++){
//         for (int k = 0; k < width; k++){
//             // if width is 16 and height is 11:
//             // when i = 0, and k = 0, 1 or 2 print char
//             // when i = 0, and k = 3, 4 or 5, print space
//             // when i = 3, and k = 0, 1 or 2 print space
//             // when i = 3, and k = 3, 4 or 5 print char

//             if (row_multiple % 2 == 1){
//                 if ((3*row_multiple <= i) && (i < 3*(row_multiple+1))){
//                     if (col_multiple % 2 == 1){
//                         if ((3*col_multiple <= k) && ( k < 3*(col_multiple+1))){
//                             cout << ch;
//                         }
//                     } else {
//                         if ((3*col_multiple <= k) && (k < 3*(col_multiple+1))){
//                             cout << " ";
//                         }             
//                     }
//                 }
//             } else {
//                     if ((3*row_multiple <= i) && (i < 3*(row_multiple+1))){
//                         if (col_multiple % 2 == 1){
//                             if ((3*col_multiple <= k) && (k < 3*(col_multiple+1))){
//                                 cout << " ";
//                             }
//                         } else {
//                             if ((3*col_multiple <= k) && (k < 3*(col_multiple+1))){
//                                 cout << ch;
//                             }             
//                         }
//                 }             
//             }
          
//         }
        
//         cout << "\n";
      
      
//     }
// }