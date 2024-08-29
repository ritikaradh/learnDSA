#include <iostream>
#include <string>
using namespace std;


//leetcode qn: 2022- Convert 1d array to 2d array
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(int);
    int n = 3, m = 2;

    //code for 1d to 2d array
    if(n*m != size){
        cout<<"Assume this is an empty 2d array"<<"\n";
    }else{
        int matrix[n][m] = {{0}};
    
        for(int i=0; i < n; i++){
            int j = i*m;
            int k = (i+1)*m - 1;
            int col = 0; 
            while(j <= k){
                matrix[i][col] = arr[j++];
                col++;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}