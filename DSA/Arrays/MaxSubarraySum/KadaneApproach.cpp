#include <iostream>
using namespace std;

//Using Kadane's Algorithm (Dynamic Programming) 
    //to solve the Max Subarray Sum problem of Arrays.

int maxSubarraySum(int *arr, int n){
    int sum = 0;
    int maxSum = INT32_MIN;

    for (int i = 0; i < n ; i++){
        sum += arr[i];
        maxSum = max( sum, maxSum);

        if(sum < 0) {sum = 0;}
    }

    return maxSum;
}

int main(){
    int n = 6;
    int arr[n] = {2, -3, 6, -5, 4, 2};

    std::cout<<maxSubarraySum(arr, n)<<endl;

    return 0;
}

//The time complexity of the above code is O(n).
//Note: Kadane's Algorithm is important for coding interviews.