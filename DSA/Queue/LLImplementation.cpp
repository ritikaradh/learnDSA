#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    //constructor
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

class Queue{
    Node* head;
    Node* tail;

    public:
    //constructor
    Queue(){
        head = tail = NULL;
    }

    //operation1: push() which is same as ll.push_back()
    void push(int val){
        //create newNode
        Node* newNode = new Node(val);

        //insert in queue
        if(head == NULL) head = tail = newNode;
        else{ tail->next = newNode; tail = newNode; }
    }

    //operation2: pop() which is same as ll.pop_front()
    void pop(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    //operation3: front()
    int front(){
        if(isEmpty()) return -1;
        return head->val;
    }

    //operation4: isEmpty()
    bool isEmpty(){
        return head == NULL;
    }

};

int main(){
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    while(!q.isEmpty()){
        cout<<q.front()<<endl;
        q.pop();
    }

    return 0;
}