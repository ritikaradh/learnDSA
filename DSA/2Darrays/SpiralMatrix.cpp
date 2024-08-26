#include <iostream>
using namespace std;

void spiralMatrix(int matrix[][4], int n, int m){
    int srow=0; int scol=0;
    int erow=n-1; int ecol=m-1;

    while(srow <= erow && scol <= ecol){
        //top
        for(int j=scol; j <= ecol; j++){
            cout<<matrix[srow][j]<<" ";
        }

        //right
        for(int i=srow+1; i <= erow; i++){
            cout<<matrix[i][ecol]<<" ";
        }

        //bottom
        for(int j=ecol-1; j >=  scol; j--){
            if (srow == erow){
                break;
            }
            cout<<matrix[erow][j]<<" ";
        }

        //left
        for(int i=erow-1; i >= srow+1; i--){
            if(scol == ecol){
                break;
            }
            cout<<matrix[i][scol]<<" ";
        }

        srow++, scol++;
        erow--; ecol--;
    }
}

int main(){
    int n=3, m=4;

    int matrix[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},

    };

    spiralMatrix(matrix, n, m);

    return 0;
}