#include <iostream>
#include <climits>
using namespace std;

int getWaterTrapped(int *height, int n){
    int totalWaterTrap = 0;
    
    //auxiliary arrays
    int leftMax[n];
    int rightMax[n];
    
    //initializing
    leftMax[0] = height[0];
    rightMax[n-1] = height[n-1];
    
    //leftMax
    for(int i=1; i < n; i++){
        leftMax[i] = max(leftMax[i-1], height[i-1]); 
    }
    
    //rightMax
    for(int i=n-2; i >= 0; i--){
        rightMax[i] = max(rightMax[i+1], height[i+1]);
    }
    
    //water trapped by each bar
    for(int i=0; i<n; i++){
        int waterTrap = min(leftMax[i], rightMax[i]) - height[i];
        totalWaterTrap += max(0, waterTrap);
        // cout<<waterTrap<<", ";
    }
    
    return totalWaterTrap;
}

int main(){
    int arr[] = {4, 2, 0, 6, 3, 2, 5};
    int n = sizeof(arr)/sizeof(int);
    
    cout<<getWaterTrapped(arr, n)<<"\n";

    return 0;
}

//Time Complexity: O(3n) = O(n);
//Space Complexity: O(n^2) since two auxiliary arrays were taken;