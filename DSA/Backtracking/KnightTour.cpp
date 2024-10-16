#include <iostream>
#include <vector>
using namespace std;

void print(const vector<vector<int>> &board) {
    int n = board.size();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}

bool isSafe(const vector<vector<int>> &board, int row, int col) {
    int n = board.size();
    // Check if row and col are within bounds and the cell is unvisited (-1)
    return (row >= 0 && col >= 0 && row < n && col < n && board[row][col] == -1);
}

bool knightTour(vector<vector<int>> &board, int move, int row, int col) {
    int n = board.size();
    
    // Base case: If move equals n*n, the tour is complete
    if (move == n * n) {
        print(board);
        return true;
    }

    // All possible knight moves
    int rowMoves[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int colMoves[] = {1, -1, 2, -2, 2, -2, 1, -1};
    
    // Try all 8 moves
    for (int i = 0; i < 8; i++) {
        int newRow = row + rowMoves[i];
        int newCol = col + colMoves[i];
        
        if (isSafe(board, newRow, newCol)) {
            board[newRow][newCol] = move; // Mark the cell as visited
            
            // Recursively continue the knight's tour
            if (knightTour(board, move + 1, newRow, newCol)) {
                return true; // If tour is completed, return true
            }

            // Backtrack: unmark the cell (if the tour is not successful)
            board[newRow][newCol] = -1;
        }
    }
    
    return false; // Return false if no move is possible
}

int main() {
    int n = 8; // Size of the chessboard
    vector<vector<int>> board(n, vector<int>(n, -1)); // Initialize board with -1

    // Start knight's tour from (0, 0)
    board[0][0] = 0; // Starting position

    // Try to solve the Knight's Tour problem
    if (!knightTour(board, 1, 0, 0)) { // Start move from 1 since (0, 0) is already visited
        cout << "No solution exists" << endl;
    }

    return 0;
}
