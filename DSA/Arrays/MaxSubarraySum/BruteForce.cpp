#include <iostream>
using namespace std;

int maxSubarraySum(int *arr, int n){
    int max = INT32_MIN;

    for (int i = 0; i < n ; i++){

        for (int j = i; j < n ; j++){

            int sum =0;

            for (int start = i ; start <= j ; start ++){
                sum += arr[start];
            }

            if (sum > max){
                max = sum;
            }  
        }
    }
    return max;
}

int main(){
    int n = 6;

    int arr[n] = {2, -3, 6, -5, 4, 2};

    std::cout<<maxSubarraySum(arr, n)<<endl;

    return 0;
}

//The time complexity of the code is O(n^3);