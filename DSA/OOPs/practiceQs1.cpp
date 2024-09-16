#include <iostream>
using namespace std;

class User {
    int id;
    string pswd;
    
    public:
        string username;

        //parameterized constructor
        User (int id){
            this -> id = id;
            cout<<"Parameterized Constructor has been called!"<<endl;
        }

        //getter and setter for pswd
        string getPswd() {
            return pswd;
        }
        void setPswd (string pswd) {
            this -> pswd = pswd;
            cout<<"Pswd set successfully!"<<endl;
        }
};

int main () {
    User u1(52);
    u1.username = "@tisha";
    u1.setPswd("123fg");

    cout<<"Username: "<<u1.username<<endl;
    cout<<"Password: "<<u1.getPswd()<<endl;
    
    return 0;
}