#include <iostream>
using namespace std;

int maxSubarraySum(int *arr, int n){
    int maxSum = INT32_MIN;

    for (int i = 0; i < n ; i++){
        int sum = 0;

        for (int j = i; j < n ; j++){
            sum += arr[j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

int main(){
    int n = 6;

    int arr[n] = {2, -3, 6, -5, 4, 2};

    std::cout<<maxSubarraySum(arr, n)<<endl;

    return 0;
}

//The time complexity of the code is O(n^3);