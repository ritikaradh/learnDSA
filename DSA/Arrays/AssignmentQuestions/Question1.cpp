#include <iostream>
using namespace std;

//Easy Level Question

//Question: Given an integer array nums, returns true if any value appears atleast twice in the array, 
//and return false if every element is distinct.
    //Examples:
        //Input nums = [1, 2, 3, 4]
        //Output: false

        //Input nums = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
        //Output: true

bool twiceInTheArray(int *num, int n){
    int arr[n];
    for (int i = 0 ; i < n ; i++){
       for (int i = 0 ; i < n; i++){
        if(num[i] > num [i+1]){
            swap(num[i], num[i+1]);
        }
       }
    }
    for (int i=0; i<n; i++){
        if (num[i] == num[i+1]){
            return true;
        }
    } 
    return false;  
}
       
int main(){
    int arr[] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    // int arr[] = {1,2,3,4};
    int len = sizeof(arr) / sizeof(int);

    if (bool i = twiceInTheArray(arr,len) == 1 ){
        cout<<"true";
    }else{
        cout<<"false";
    }

    return 0;
}

//The above question solved using sorting.
//The time complexity of the above code is O(n^2)