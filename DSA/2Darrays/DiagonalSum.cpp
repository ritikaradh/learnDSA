#include <iostream>
#include <climits>
using namespace std;

int matrixDiagonalSum(int matrix[][4], int n){
    int sum;
    int pdSum = matrix[0][0];
    int sdSum = matrix[n-1][n-1]; //given n=m

    //primary diagonal sum
    for(int i=1; i<n; i++){
        pdSum += matrix[i][i];
    }

    //secondary diagonal sum
    for(int i=n-2; i >= 0; i--){
        sdSum += matrix[i][i];
    }

    //common element
    if(n % 2 != 0){
        return sum = (pdSum + sdSum) - matrix[n/2][n/2];
    }
    return sum = pdSum + sdSum;
    
}

int main(){
    int n=4;

    int matrix[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16},
    };
    
    //time complexity: O(2n)
    cout<<matrixDiagonalSum(matrix, n)<<"\n";

    return 0;
}