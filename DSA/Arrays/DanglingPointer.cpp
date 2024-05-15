#include <iostream>
using namespace std;

int main() {
    char * ptr;
    char Str[] = "Ritika";
    ptr = Str;
    ptr += 2;
    cout<<Str<<endl;
    cout<<Str[0]<<" "<<&Str<<endl;
    cout << ptr;
    return 0;
}