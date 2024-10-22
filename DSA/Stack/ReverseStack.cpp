#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node{
    public:
    T data;
    Node* next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

template <class T>
class Stack{
    public:
    Node<T>* head;

    //construtor
    Stack(){
        head = NULL;
    }

    //stack operation: push
    void push(T data){
        Node<T>* newNode = new Node<T>(data);
        if(head != NULL){
            newNode->next = head;
        }
        head = newNode;
    }

    //stack operation: pop
    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        Node<T>* temp = head;
        //shift head to next node
        head = temp->next;
        //break connection
        temp->next = NULL;
        //free pointer
        delete temp;
    }

    //stack operation: top
    T top(){
        return head->data;
    }

    //stack operation: underflow
    bool isEmpty(){
        return head==NULL;
    }

    //stack operation: pushAtBack
    void pushAtBack(T data){
        if(head == NULL){
            push(data);
            return;
        }
        T temp = top();
        pop();
        pushAtBack(data);
        push(temp);
    }

};

void reverseStack(Stack<int> &s){
    if(s.isEmpty()){
        return;
    }
    int temp = s.top();
    s.pop();
    reverseStack(s);
    s.pushAtBack(temp);
}

int main(){
    Stack<int> s;
    s.push(5); //stack = 5
    s.push(4);  //stack = 4,5
    s.push(3);  //stack = 3,4,5
    s.push(2);  //stack = 2,3,4,5
    s.push(1);  //stack = 1,2,3,4,5

    reverseStack(s);

    while(!s.isEmpty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}