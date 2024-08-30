#include <iostream>
using namespace std;

void rotateMatrix(int matrix[][3], int n, int m){
    //transpose of a matrix
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<m; j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    
    //reversing each row
    for(int i=0; i < n; i++){
        for(int start=0, end=n-1; start < end; start++, end--){
            swap(matrix[i][start], matrix[i][end]);
        }
    }
}

int main(){
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    int n=3, m=3;

    rotateMatrix(matrix, n, m);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}