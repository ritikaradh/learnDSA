#include <iostream>
#include <utility>
using namespace std;

int allSevens(int matrix[][3], int n, int m){
    int sevens = 0;
    for(int i=0; i <n ; i++){
        for(int j=0; j < m; j++){
            if(matrix[i][j] == 7){
                sevens += 1;
            }
        }
    }
    return sevens;
}

int main(){
    int matrix[2][3] = {
        {4,7,8},
        {8,8,7},
    };
    int n = 2, m = 3;

    cout<<allSevens(matrix, n, m)<<"\n";

    return 0;
}