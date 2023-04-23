// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Homework E7.1 - Sort2 Pointer Edition

// Write a function void sort2(double *p, double *q) that recieves two pointers and sorts
// the values to which the point. If you call sort2(&x, &y) then x <= y after the call

void sort2(double *p, double *q) {
    if (*p > *q) {
        double temp = *p;
        *p = *q;
        *q = temp;
    }
}