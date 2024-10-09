#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector<vector<char>> &board){
    int n = board.size();
    
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"---------------------------"<<endl;
}

bool isSafe(vector<vector<char>> &board, int row, int col) {
    int n = board.size();

    //horizontal check
    for(int j=0; j < col; j++) {
        if(board[row][j] == 'Q') return false;
    }

    //vertical check
    for(int i=0; i < row; i++){
        if(board[i][col] == 'Q') return false;
    }

    //left diagonal check
    for(int i=row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 'Q') return false;
    }

    //right diagonal check
    for(int i=row, j=col; i >= 0 && j < n; i--, j++){
        if(board[i][j] == 'Q') return false;
    }

    return true;
}

void NQueen(vector<vector<char>> &board, int row){
    int n = board.size();
    
    if(row == n){
        printBoard(board); return;
    }

    for(int j=0; j < n; j++){
        if( isSafe(board, row, j) ){
            board[row][j] = 'Q';
            NQueen(board, row+1);
            board[row][j] = '.';
        }  
    }
}

int main(){
    int n = 5;
    vector<vector<char>> board(n, vector<char>(n, '.'));

    NQueen(board, 0);

    return 0;
}