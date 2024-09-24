#include <iostream>
#include <vector>
using namespace std;

bool checkSort(vector<int> nums, int i) {
    if (i == nums.size() - 1) return true; 
    if (nums[i] > nums[i+1]) return false; 
    return checkSort(nums, i+1);
}

int main(){ 
    vector<int> num1 = {1,2,7,4,5};
    vector<int> num2 = {1,2,3,4,5};

    bool ans1 = checkSort(num1, 0);
    bool ans2 = checkSort(num2, 0);

    if(ans1){
        cout<<"Array is sorted"<<endl;
    }else{
        cout<<"Array not sorted"<<endl;
    }

    
    if(ans2){
        cout<<"Array is sorted"<<endl;
    }else{
        cout<<"Array not sorted"<<endl;
    }

    return 0;
}