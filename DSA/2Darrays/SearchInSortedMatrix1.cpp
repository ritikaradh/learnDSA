#include <iostream>
#include <utility>
using namespace std;

// Approach 1
// Brute force approach: using nested loops 
// Time complexity O(n*m)
pair<int, int> search1(int matrix[][4], int n, int m, int key){
    //traversing each row
    for(int i=0; i<n; i++){
        //traversing each column
        for(int j=0; j<n; j++){
            if(matrix[i][j] == key){
                return {i, j};
            }
        }
    }
    return {-1, -1};
}


// Approach 2
// Row-wise or column-wise binary search
// Time Complexity: O(n*logm) or O(m*logn)



// Approach 3 
// Staircase Approach: Staircase Search for Sorted Matrix (sorted in both row and column)
// Time complexity: O(n+m)  if n>>m then O(n)/ if m >>n then O(m)
pair<int, int> search3(int matrix[][4], int n, int m, int key){
    int row = 0, col = m-1;

    while(row < n && col >= 0){
        int cell = matrix[row][col];

        if(key == cell){
            return {row, col};
        }
        else if(key > cell){
            row++;
        }else{
            col--;
        }
    }
    return {-1, -1};
}



int main(){
    int n=4, m=4;

    int matrix[4][4] = {
        {10,20,30,40},
        {15,25,35,45},
        {27,29,37,48},
        {32,33,39,50},
    };

    pair<int, int> result = search1(matrix, n, m, 89);
    
    if(result.first != -1){
        cout<<"Key found at index "<<result.first<<", "<<result.second<<"\n";
    }else{
        cout<<"Key not found"<<"\n";
    }

    return 0;
}