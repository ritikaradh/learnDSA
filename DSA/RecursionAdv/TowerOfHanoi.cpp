#include <iostream>
using namespace std;

void towerOfHanoi(int n, char src, char help, char dest){
    if(n == 1){
        cout<<"Moved disk from "<<src<<" to "<<dest<<endl; 
        return;
    }
    towerOfHanoi(n-1, src, dest, help);
    cout<<"Moved disk from "<<src<<" to "<<dest<<endl;
    towerOfHanoi(n-1, help, src, dest);
}

int main(){
    towerOfHanoi(2, 'A', 'B', 'C');
    return 0;
}