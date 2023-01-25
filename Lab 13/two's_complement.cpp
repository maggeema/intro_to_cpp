//Name: Maggie Ma
//Email: maggie.ma94@bcmail.cuny.edu
//Date: December 13, 2022
//This program asks the user for a whole number between -128 and 127 ...
//... and prints out the number in "two's complement" notation

#include <iostream>
using namespace std;

int main(){
    int num; 

    // Ask the user for an int n in [-128, 127], both ends are included.
    cout << "Enter an int in [-128, 127]: ";
    // Save n in variable num.
    // If num is negative, set num to be -num -1.
    cin >> num; 
    if (num < 0){
        num = -num-1;
    }

    // Declare string variable binary and initialize it to be an empty string "". This variable stores the binary representation of num.
    string binary = ""; 

    // Declare integer variable rem.
    int rem;
    // as long as num > 0:
    if (num > 0){
    // Save the remainder of num divided by 2 to rem.
    rem = num%2;
    }
    // Concatenate to_string(rem) to the left of string binary and save to binary. Expression to_string(rem) converts integer rem to a string in C++.
    to_string(rem);
    // Let num be num/2.
    //num = num/2; 

    // Declare integer variable size and initialize it to be 8. 
    int size = 8;
    //Next, pad zeros to the left of binary to make it a 8-letter string.
    // Put binary.length(), which returns the number of letters in string binary, to integer variable len. 
    //Unlike Python, len is not a function in C++. 
    //For comparison, we use len(binary) to find out the number of letters in binary in Python.
    // Run the following statement to pad (size - len) zeros to the left of binary. 
    //We would like string binary to have eight letters, which are either '0' or '1'.
    // for (int i = 0; i < size - len; i++)
    //     binary = "0" + binary;
    // Warning: cannot replace i < size - len by i < size - binary.length() in the above statemen. 
    //Reason: after binary = "0" + binary, the length of binary is changed. The following is an example.
    // Suppose in the beginning, string binary has 6 characters, then we are supposed to pad 8 - 6 = 2 zeros to its left.
    // In the beginning, variable i is 0, size is 8, and binary.length() is 6, since i < size - binary.length(), we enter the loop and pad one zero to the left of string binary. Then i is increased by 1 by i++ statement.

    // Check condition i < size - binary.length() to see whether we need to enter the loop. After we pad the first zero, the length of binary is changedfrom 6 to 7, thus size - binary.length() returns 1. Now i is 1, so i < size - binary.length() does not hold. Exit the loop.

    // So we only pad one zero, and the length of binary is 7, not 8 as we expect.
    for (int i = 0; i < size - binary.length(); i++){
        binary = "0" + binary;
    }


    // Work with number that is negative. Note that num is modified from original value n by num = n and num = -num-1 in previous steps. 
    //Since num has been modified to be non-negative, we need to check whether the original number is negative or not by checking n.
    if (num < 0) {
    //TODO: write code to invert(or flip) each bit of string binary.
    //That is, if the current bit is '0', change it to '1',
        for (int j = 0; j < size - binary.length(); j++){
            if (binary[j] == 0){
                binary[j] = 1;
            } else {
            //otherwise, change the current bit to '0'. 
            //Note that string binary has 8 characters now.
                binary[j]= 0;
            }
        }
    }
        
    // Print the value of binary. This is the two's complement we seek.
    cout << binary;
    return 0;
}