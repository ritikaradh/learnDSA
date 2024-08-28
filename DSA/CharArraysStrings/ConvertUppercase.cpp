#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char word[] = "ApPle";
    int size = strlen(word);

    for(int i=0; i<size; i++){
        if(word[i] >='a' && word[i] <= 'z'){
            int pos = word[i] - 'a';
            word[i] = 'A' + pos;
            cout<<word<<"\n";
        }
    }
}