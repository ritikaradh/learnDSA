#include <iostream>
using namespace std;

int main(){
    int rows, cols;
    cin>>rows;
    cin>>cols;

    //declaring 2D dynamic array
    int **matrix = new int *[rows];

    //declaring 1D dynamic array for each row
    for(int i=0; i<rows; i++){
        matrix[i] = new int[cols];
    }

    int var=1;

    //defining matrix
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            matrix[i][j] = var++;
            cout<<matrix[i][j]<<", ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
    
}