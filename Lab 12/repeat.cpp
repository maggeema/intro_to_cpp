//Name: Maggie Ma
//Email: maggie.ma94@bcmail.cuny.edu
//Date: December 1, 2022
//This program repeats 10 6 times, for 10 rows


#include <iostream> 

using namespace std;

int main(){
    int row = 10;
    int col = 6;
    int array[row][col];

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            array[i][j] = 10;
            cout << array[i][j];
        }
        cout << "\n";
    }
return 0;
}
