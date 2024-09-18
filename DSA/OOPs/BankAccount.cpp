#include <iostream>
using namespace std;

class BankAccount {
    string accountNumber;
    int balance;

    public:
        BankAccount(string accountNumber, int balance) {
            this -> accountNumber = accountNumber;
            this -> balance = balance;
            cout<<"Bank Account Created Successfully!"<<endl;
        }

        void deposit(int money) {
            balance += money;
            cout<<"Money depositied successfully"<<endl;
        }

        void withdraw(int money) {
            if (money > balance) {
                cout<<"Not sufficient balance"<<endl;
            }else{
                cout<<money<<endl;
                balance -= money;
                cout<<"Withdrawl successfull"<<endl;
            }
            
        }

        void getBalance() {
            if (balance)
            cout<<balance<<endl;
        }
};

int main() {
    BankAccount ritika("18730621003ABC", 25000);

    ritika.deposit(5000);
    ritika.getBalance();

    ritika.withdraw(10000);
    ritika.getBalance();

    ritika.withdraw(50000);
    ritika.getBalance();
    
    return 0;
}