#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int capacity = 0;

    while(left < right){
        capacity = max( capacity, min( height[left], height[right] ) * (right-left) );

        if(height[left] < height[right]){
            left++;
        }
        else{
            right--;
        }
    }

    return capacity;
}

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int ans = maxArea(height);

    cout<<ans<<"\n";

    return 0;
}