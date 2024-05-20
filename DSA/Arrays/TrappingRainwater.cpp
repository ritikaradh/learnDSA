#include <iostream>
using namespace std;

int trapRainwater(int *arr, int n){
    int leftMax[20000];
    int rightMax[20000];

    //initializing the left max for the first element of leftMax array
    leftMax[0] = arr[0];

    //initializing the right max for the last element of the rightMax array
    rightMax[n-1] = arr[n-1];

    //Creating the leftMax array by comparing the maximum of leftMax[i-1] and height[i-1]
    for(int i=1 ; i < n ; i++){
        leftMax[i] = max(leftMax[i-1], arr[i-1]);
    }

    //Creating the rightMax array by comparing the minimum of rightMax[i+1] and height[i+1]
    for(int i=n-2; i >= 0; i--){
        rightMax[i] = max( rightMax[i+1], arr[i+1]);
    }

    int totalWaterTrapped = 0;

    //finding the water trap
    for (int i=0 ; i < n ; i++){
        int trappingBarHeight = min ( leftMax[i], rightMax[i] );
        int trapWaterByBar = trappingBarHeight - arr[i];

        if (trapWaterByBar > 0){
            totalWaterTrapped += trapWaterByBar; 
        }
    }

    return totalWaterTrapped;
}

int main(){
    int height[] = {4, 2, 0, 6, 3, 2, 5};
    int n = sizeof(height) / sizeof(int);
    cout<<trapRainwater(height, n)<<endl;
    return 0;
}


//The time complexity of the above code is O(3n) i.e., O(n).