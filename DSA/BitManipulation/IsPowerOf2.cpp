#include <iostream>
using namespace std;

int IsPowerOf2(int num) {
    if (num & (num-1) ){
        return false;
    }
    return true;
}

int main() {
    cout<<IsPowerOf2(-2)<<endl;
    cout<<IsPowerOf2(-1)<<endl;
    cout<<IsPowerOf2(0)<<endl;
    cout<<IsPowerOf2(1)<<endl;
    cout<<IsPowerOf2(2)<<endl;
    cout<<IsPowerOf2(3)<<endl;
    cout<<IsPowerOf2(4)<<endl;
    cout<<IsPowerOf2(5)<<endl;
    cout<<IsPowerOf2(6)<<endl;
    cout<<IsPowerOf2(8)<<endl;

    return 0;
}