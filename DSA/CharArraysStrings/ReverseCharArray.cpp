#include <iostream>
#include <cstring>
using namespace std;

void reverseCharArray(char str[], int n){
    //using two pointer approach
    for(int i=0, j=n-i-1; i < n/2; i++, j--){
        swap(str[i], str[j]);
    }
}

int main(){
    char str[] = "Ritika";
    int size = strlen(str);

    reverseCharArray(str, size);

    cout<<str<<"\n";

    return 0;
}