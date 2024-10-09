#include <iostream>
#include <vector>
using namespace std;

int gridWays(int row, int col, int n, int m, string ans) {
    //base case for destination
    if(row == n-1 && col == m-1) { cout<<ans<<endl; return 1; }

    //base case for end col or end row
    if(row == n || col == m) return 0;

    //right turn
    int val1 = gridWays(row, col+1, n, m, ans+'R');

    //left turn
    int val2 = gridWays(row+1, col, n, m, ans+'D');

    //ans
    return val1+val2;
}

int main() {
    int n = 3;
    int m = 3;

    string ans;
    cout<<gridWays(0, 0, n, m, ans)<<endl;

    return 0;
}