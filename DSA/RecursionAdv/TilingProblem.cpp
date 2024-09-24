#include <iostream>
using namespace std;

int tiling(int n) {
    //(height * width) format
    //size of floor = 2 * n
    //size of tile = 2 * 1
    //after vertical placement, remaining space= 2*(n-1)
    //after horizonatal placement, remaining space = 2*(n-2)

    //base case
    if(n == 0 || n == 1) return 1;

    //total no. of ways
    return tiling(n-1) + tiling(n-2);
}

int main() {
    cout<<tiling(2)<<endl;
    cout<<tiling(3)<<endl;
    cout<<tiling(4)<<endl;
    cout<<tiling(5)<<endl;
    cout<<tiling(6)<<endl;

    return 0;
}