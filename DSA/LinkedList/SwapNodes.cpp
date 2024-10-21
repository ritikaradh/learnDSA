#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;

    Node(int val){
        this->val = val;
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

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void swapNode(int keyA, int keyB) {
        if (head == NULL || keyA == keyB) {
            return;  // Edge case: Empty list or same keys
        }

        Node *prevA = NULL, *prevB = NULL;
        Node *tempA = NULL, *tempB = NULL;
        Node *current = head;
        Node *prev = NULL;

        // Single traversal to find both keyA and keyB
        while (current != NULL) {
            if (current->val == keyA) {
                prevA = prev;
                tempA = current;
            }
            if (current->val == keyB) {
                prevB = prev;
                tempB = current;
            }
            prev = current;
            current = current->next;

            if (tempA && tempB) {
                break;  // Found both nodes, no need to continue traversing
            }
        }

        if (tempA == NULL || tempB == NULL) {
            cout << "One or both keys not found" << endl;
            return;
        }

        // If tempA or tempB are adjacent nodes
        if (prevA == tempB || prevB == tempA) {
            // Adjust if keyA and keyB are adjacent
            if (prevA != NULL) {
                prevA->next = tempB;
            } else {
                head = tempB;  // If keyA is the head node
            }
            if (prevB != NULL) {
                prevB->next = tempA;
            } else {
                head = tempA;  // If keyB is the head node
            }
            Node* temp = tempA->next;
            tempA->next = tempB->next;
            tempB->next = temp;
        } else {
            // Non-adjacent nodes
            if (prevA != NULL) {
                prevA->next = tempB;
            } else {
                head = tempB;  // keyA was the head
            }

            if (prevB != NULL) {
                prevB->next = tempA;
            } else {
                head = tempA;  // keyB was the head
            }

            // Swap their next pointers
            Node* temp = tempA->next;
            tempA->next = tempB->next;
            tempB->next = temp;
        }
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
    List ll;
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    Node* temp = ll.head;
    while(temp != NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;

    ll.swapNode(1,2);

    temp = ll.head;
    while(temp != NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;

    return 0;
}