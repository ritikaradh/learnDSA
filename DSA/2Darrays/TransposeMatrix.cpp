#include <iostream>
#include <utility>
using namespace std;

void transpose(int matrix[][3], int n, int m){
    int matrixT[m][n] = {{0}};
    int col = 0;
    
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            matrixT[j][i] = matrix[i][j];
        }
        col++;
    }

    for(int i=0; i < m; i++){
        for(int j=0; j < n; j++){
            cout<<matrixT[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int matrix[2][3] = {
        {1,2,3},
        {4,5,6},
    };

    int n = 2, m = 3;

    transpose(matrix, n, m);

    return 0;
}
