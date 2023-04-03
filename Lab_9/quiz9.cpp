// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Quiz 9

// This program has a checkboard pattern, alternating between the image and black pixels

#include <iostream>
using namespace std;

int main() {
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(img, h, w);
    int out[MAX_H][MAX_W];
    for (int row = 0; row < h; row++){
        for (int col = 0; col < w; col++){
            if((row+col) % 2 == 0)
            out[row][col] = 0;
            else
            out[row][col] = img[row][col];
        }
    }
    writeImage(out, h, w);
    return 0;
}