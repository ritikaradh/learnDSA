#include <iostream>
using namespace std;

class Complex {
    int real;
    int img;

    public: 
        //parameterized constructor
        Complex(int real, int img){
            this -> real = real;
            this -> img = img;
        }

        //show complex number
        void showNum(){
            cout<<real<<" + "<<img<<"i"<<endl;
        }

        //operator overloading
        Complex operator - (Complex &c2) {
            int real = this->real - c2.real;
            int img = this->img - c2.img;
            Complex ans(real, img);
            return ans; 
        }  
};

int main() {
    Complex c1(5, 3);
    Complex c2(3, 2);
    Complex ans = c1 - c2;
    c1.showNum();
    c2.showNum();
    ans.showNum();
    return 0;
}