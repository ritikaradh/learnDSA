#include <iostream>
#include <vector>
using namespace std;

void escape(vector<vector<bool>> &maze, vector<vector<bool>> &visited, int row, int col, string ans){
    int n = maze.size();

    if(row == n-1 && col == n-1 && maze[row][col] == 1){
        cout<<ans<<endl;
        return;
    }

    if(row >= n || col >= n || row < 0 || col < 0 || maze[row][col] == 0 || !visited[row][col]){
        return;
    }

    visited[row][col] = false;

    //up
    escape(maze, visited, row-1, col, ans+'U');

    //down
    escape(maze, visited, row+1, col, ans+'D');

    //right
    escape(maze, visited, row, col+1, ans+'R');

    //left 
    escape(maze, visited, row, col-1, ans+'L');

    visited[row][col] = true;
}

int main () {
    vector<vector<bool>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1},
    };
    
    vector<vector<bool>> visited(4, vector<bool>(4, true));

    escape(maze, visited, 0, 0, "");

    return 0;
}