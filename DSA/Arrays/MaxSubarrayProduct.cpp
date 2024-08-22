#include <iostream>
using namespace std;

void maxSubarrayProduct(int *nums, int n){
    for(int i=0; i<n; i++){
        for(int j=i; j < n; j++){
            calculateProduct(nums[i:j])
        }
    }
}

int main(){
    int arr[] = {2, 3, -2, 4};
    int n = sizeof(arr)/sizeof(int);

    maxSubarrayProduct(arr, n);

    return 0;
}