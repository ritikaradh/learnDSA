#include <iostream>
#include <vector>
using namespace std;

//create stack using vector
template <class T>
class Stack{
    vector<T> stack;

    public:
        Stack(){
            vector<T> stack;
        }

        //time complexity: O(1)
        void push(int val){
            stack.push_back(val);
        }

        //time complexity: O(1)
        void pop(){
            if(isEmpty()){
                cout<<"Underflow"<<endl;
                return;
            }
            stack.pop_back();
        }

        //time complexity: O(1)
        T top(){
            if(isEmpty()){
                cout<<"Underflow"<<endl;
                return -1;
            }
            return stack[stack.size()-1];
        }

        //time complexity: O(1)
        bool isEmpty(){
            return stack.size() == 0;
        }
};

int main(){
    Stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    while(!s.isEmpty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}