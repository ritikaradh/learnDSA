#include <iostream>
#include <cstring>
using namespace std;

bool validPalindrome(char str[], int n){
    //two pointer approach
    for(int i=0, j=n-i-1; i<=j; i++, j--){
        if(str[i] != str[j]){
            return false;
        }
    }
    return true;
}

int main(){
    char str[] = "race";
    int n = strlen(str);

    bool result = validPalindrome(str, n);
    
    if(result == 1){
        cout<<"Valid Palindrome"<<"\n";
    }else{
        cout<<"Invalid Palindrome"<<"\n";
    }

    return 0;
}