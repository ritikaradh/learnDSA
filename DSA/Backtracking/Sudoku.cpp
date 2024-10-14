#include <iostream>
#include <vector>
using namespace std;

void printSudoku(vector<vector<int>> &sudoku) {
    for(int i=0; i < 9; i++){
        for(int j=0; j < 9; j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(vector<vector<int>> &sudoku, int row, int col, int digit){
    //vertical check
    for(int i=0; i < 9; i++){
        if(sudoku[i][col] == digit){
            return false;
        }
    }

    //horizontal check
    for(int j = 0; j < 9; j++) {
        if(sudoku[row][j] == digit){
            return false;
        }
    }

    //3*3 grid
    //finding row and col val of starting cell of the grid
    int startRow = (row/3)*3; 
    int startCol = (col/3)*3;

    for(int i=startRow; i < startRow+3; i++){
        for(int j=startCol; j < startCol+3; j++){
            if(sudoku[i][j] == digit){
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(vector<vector<int>> &sudoku, int row=0, int col=0) {
    //base case
    if(row >= 9){
        printSudoku(sudoku);
        return true;
    }

    int nextRow = row;
    int nextCol = col+1;

    if(col + 1 == 9) {
        nextRow = row+1;
        nextCol = 0;
    }

    if(sudoku[row][col] != 0) {
        return solveSudoku(sudoku, nextRow, nextCol);
    }

    for(int digit = 1; digit <= 9; digit++) {
        if(isSafe(sudoku, row, col, digit)) {
            sudoku[row][col] = digit;
            if(solveSudoku(sudoku, nextRow, nextCol)){
                return true;
            }
            sudoku[row][col] = 0;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> sudoku = {
        {0, 0, 8, 0, 0, 0, 0, 0, 0},
        {4, 9, 0, 1, 5, 7, 0, 0, 2},
        {0, 0, 3, 0, 0, 4, 1, 9, 0},
        {1, 8, 5, 0, 6, 0, 0, 2, 0},
        {0, 0, 0, 0, 2, 0, 0, 6, 0},
        {9, 6, 0, 4, 0, 5, 3, 0, 0},
        {0, 3, 0, 0, 7, 2, 0, 0, 4},
        {0, 4, 9, 0, 3, 0, 0, 5, 7},
        {8, 2, 7, 0, 0, 9, 0, 1, 3},
    };

    printSudoku(sudoku);
    cout<<"-------------------------"<<endl;
    solveSudoku(sudoku);

    return 0;
}