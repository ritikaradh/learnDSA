#include <iostream>
using namespace std;

void printSubarray(int *arr, int n){
    for (int i = 0; i < n ; i++){       //Time complexity: n
        for (int j = i ; j < n ; j++){          //Time complexity: n
            for (int start = i; start <= j ; start++){      //Time complexity:  n
                cout<<arr[start]<<" ";
            }
            cout<<"     ";
        }
        cout<<endl;
    }
}

int main(){
    int n = 5;
    int arr[n] = {1,2,3,4,5};

    printSubarray(arr, n);

    return 0;
}


//The time complexity of the above code is O(n^3).