#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <vector<int>> vec = {
        {1,2,3,4},
        {5,6,7},
        {8,9},
        {0}
    };
    
    int n = vec.size(); //gives the size of matrix i.e., the no. of rows

    //traversing the whole 2d vector
    for(int i=0; i < n; i++){
        for(int j=0; j < vec[i].size(); j++){ //gives the size of each row of the matrix
            cout<<vec[i][j]<<", ";
        }
        cout<<"\n";
    }

    return 0;
}