#include <iostream>
#include <iterator>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node* prev;

        //constructor
        Node(int val){
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
};

class doublyLL{
    public:
        Node* head;
        Node* tail;

        //constructor
        doublyLL(){
            head = NULL;
            tail = NULL;
        }

        void push_front(int val){
            Node* newNode = new Node(val);

            if(head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }

            //right connection
            newNode->next = head;

            //left connection
            head->prev = newNode;

            //shift head to newNode at front
            head = newNode;
        }

        void push_back(int val){
            if(head == NULL){
                push_front(val);
                return;
            }

            Node* newNode = new Node(val);

            //left connection
            newNode->prev = tail;

            //right connection
            tail->next = newNode;

            //shift tail to last node
            tail = newNode;
        }

        void pop_front(){
            if(head == NULL){
                return;
            }

            Node* temp = head;
            
            //shift head to next node
            head = head->next;

            //break left connection
            if(head != NULL){
                head->prev = NULL;
            }

            //break right connection
            temp->next = NULL;

            delete temp;
        }

        void pop_back(){
            if(head == NULL){
                return;
            }

            Node* temp = tail;
            //shift tail to prev node
            tail = tail->prev;
            //break right connection
            tail->next = NULL;
            //break left connection
            temp->prev = NULL;

            delete temp;
        }

        void print(){
            Node* temp = head;
            
            while(temp != tail){
                cout<<temp->val<<"<=>";
                temp = temp->next;
            }
            cout<<temp->val<<endl;
        }
};


int main(){
    doublyLL dbll;
    dbll.push_front(1);
    dbll.push_back(2);
    dbll.push_back(3);
    dbll.push_back(4);
    dbll.push_back(5);
    dbll.print();

    dbll.pop_front();
    dbll.pop_back();
    dbll.print();

    return 0;
}

