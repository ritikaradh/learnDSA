#include <iostream>
using namespace std;

//Question 2:   There is an integer array nums sorted in ascending order (with distinct values.)
    //Prior to being passed to your function, nums is possibily rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is
    //[nums[k], nums[k+1],..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0 indexed.)
    
    //For e.g.,.
        //[0, 1, 2, 4, 5, 6, 7] might be rotated at pivot index 3 and become [4, 5, 6, 7, 0, 1, 2].
    
//Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

//You must write an an algorithm with O(log n) runtime complexity.

//Examples:
    //Input: nums=[4, 5, 6, 7, 0, 1, 2], target=0
    //Output: 4

    //Input: nums=[4, 5, 6, 7, 0, 1, 2], target=3
    //Output: -1

void rotateArray1(int *arr, int len, int pivotIndex){
    int temp[len];
    int j=0;
    for (int i = pivotIndex; i < len; i++){
        temp[j++] = arr[i];
    }
    for(int i=0; i < pivotIndex; i++){
        temp[j++] = arr[i];
    }
    j=0;
    for(int i=0; i < len; i++){
        arr[i] = temp[j++];
    }
    free(temp);

    //space complexity O(n^2);
    //time complexity O(n).
}

void rotateArray2(int *arr, int n, int pivotIndex){

}

int main(){
    int len = 7;
    int num[len] = {0, 1, 2, 4, 5, 6, 7};

    //rotating the array before passing it through the search function
    int pivotIndex = 4;
    rotateArray1(num, len, 4);

    for(int i=0; i<len; i++){
        cout<<num[i]<<" ";
    }

    return 0;
} 