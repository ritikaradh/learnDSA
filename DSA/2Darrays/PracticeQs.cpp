#include <iostream>
#include <utility>
using namespace std;

// Practice Qs: 1
// int allSevens(int matrix[][3], int n, int m){
//     int sevens = 0;
//     for(int i=0; i <n ; i++){
//         for(int j=0; j < m; j++){
//             if(matrix[i][j] == 7){
//                 sevens += 1;
//             }
//         }
//     }
//     return sevens;
// }

// int main(){
//     int matrix[2][3] = {
//         {4,7,8},
//         {8,8,7},
//     };
//     int n = 2, m = 3;

//     cout<<allSevens(matrix, n, m)<<"\n";

//     return 0;
// }


// Practice Qs: 2
int sum(int nums[][3], int n, int m, int row){
    int sum=0, rowIdx = row - 1;
    for(int j=0; j<n; j++){
        sum += nums[rowIdx][j];
    }
    return sum;
}

int main(){
    int nums[3][3] = {
        {1,4,9},
        {11,4,3},
        {2,2,3},
    };
    int n=3, m=3;

    cout<<sum(nums, n, m, 3)<<"\n";

    return 0;
}