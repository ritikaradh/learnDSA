#include <iostream>
using namespace std;

class Node {
    //data member
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        ~Node(){
            if(next != NULL){
                // cout<<"~Node"<<data<<endl;
                delete next;
                next = NULL;
            }
        }
};

class List{
    public:
        Node* head;
        Node* tail;

        List(){
            head = NULL;
            tail = NULL;
        }

        //insert element at the front of the linked list
        void push_front(int data){
            Node* newNode = new Node(data);
            if(head == NULL){
                head = tail = newNode;
            }else{
                newNode->next =  head;
                head = newNode;
            }
            // cout<<"Node inserted at the front successfully!"<<endl;
        }

        //inserting element at the end of the linked list
        void push_back(int data) {
            Node* newNode = new Node(data);
            if(head == NULL){
                head = tail = newNode;
            }else{
                tail->next = newNode;
                tail = newNode; 
            }
            // cout<<"Node inserted at the back successfully"<<endl;
        }

        //printing linked list
        void print(){
            Node* temp = head;
            while(temp != NULL){
                cout<<temp->data<<" -> ";
                temp = temp->next;
            }
            cout<<"NULL"<<endl;
        }

        //insert in middle
        void insert(int data, int pos){
            Node* newNode = new Node(data);

            if(!pos){
                push_front(data);
                return;
            }

            Node* temp = head;
            for(int i=1; i < pos; i++){
                if(temp->next == NULL){
                    cout<<"Invalid Index"<<endl;
                    return;
                }
                temp = temp->next; 
            }
            //temp is at pos-1
            newNode->next = temp->next;
            temp->next = newNode;
        }

        //removing front-most element of the linked list
        void pop_front(){
            if(head == NULL){
                cout<<"Linked list is empty"<<endl;
                return;
            }
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }

        //removing back-most element of the linked list
        void pop_back(){
            if(head == NULL){
                cout<<"Linked list is already empty"<<endl;
                return;
            }
            
            Node* temp = head;
            while(temp->next->next != NULL){
                temp = temp->next;
            }
            Node* last = temp->next;
            temp->next = NULL;
            delete last;
        } 

        int searchItr(int key){
            int idx = 0;

            Node* temp = head;

            while(temp != NULL){
                if(temp->data == key){
                    return idx;
                }
                idx++;
                temp =  temp->next;
            }

            return -1;
        }

        int searchRec(int key, Node* head){
            if(head->data == key){
                return 0;
            }

            if(head->next == NULL){
                return -1;
            }

            int idx = searchRec(key, head->next);

            if(idx != -1){
                return idx+1;
            }

            return -1;
        }

        //delete whole linked list
        ~List(){
            if(head != NULL){
                // cout<<"~List"<<endl;
                delete head;
                head = NULL;
            }
        }
};

int main(){
    List ll; //static memory location of linked list, 
    //therefore will get removed automatically after the execution of linked list

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.print();
    ll.push_back(5);
    ll.print();
    ll.insert(4, 3);
    ll.print();
    ll.pop_front();
    ll.print();
    ll.pop_back();
    ll.print();

    cout<<"Searching Iteratively in Linked List"<<endl;
    cout<<ll.searchItr(2)<<endl;
    cout<<ll.searchItr(3)<<endl;
    cout<<ll.searchItr(4)<<endl;
    cout<<ll.searchItr(6)<<endl;

    cout<<"Searching Recursively in Linked List"<<endl;
    cout<<ll.searchRec(3, ll.head)<<endl;
    cout<<ll.searchRec(9, ll.head)<<endl;

    return 0;
}