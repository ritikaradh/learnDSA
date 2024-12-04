#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node{
    public:

    string key;
    int val;
    Node* next;

    //contructor
    Node(string key, int val){
        this->key = key;
        this->val = val;
        this->next = NULL;
    }

    //destructor
    ~Node(){
        if(next) delete next;
    }
};

class HashTable{
    int totSize;
    int currSize;
    Node** table;

    //hash-function
    int hashFunction(string key) {
        int idx = 0;

        for(int i=0; i<key.size(); i++){
            idx = idx + (key[i] * key[i]) % totSize;
        }


        return idx%totSize;
    }

    //rehash-function
    void rehash() { //O(n)
        Node** oldTable = table;
        int oldSize = totSize;

        totSize = 2*totSize;
        currSize = 0;

        table = new Node*[totSize];

        //initialize new table with null value
        for(int i=0; i<totSize; i++){
            table[i] = NULL;
        }

        //copy old table to new table
        for(int i = 0; i < oldSize; i++) {
            Node* temp = oldTable[i];

            while(temp) {
                insert(temp->key, temp->val);
                temp = temp->next;
            }

            if(oldTable[i]) delete oldTable[i];
        }

        delete[] oldTable;
    }

    public:
    
    //constructor
    HashTable(int size = 5) {
        totSize = size;
        currSize = 0;

        //right now the table has some garbage at every indice
        table = new Node*[totSize];

        //initializing the table with NULL at every indice
        for(int i=0; i<totSize; i++){
            table[i] = NULL;
        }
    }
    
    //insertion in hash-table
    void insert(string key, int val) {  //O(1) avg
        int idx = hashFunction(key);

        Node* newNode = new Node(key, val);

        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;

        double lambda = currSize / (double)totSize;

        if(lambda > 1) rehash(); //O(n) - worst t.c
    }

    //check existence of a key in the hash-table
    bool exists(string key) {
        int idx = hashFunction(key);

        Node* temp = table[idx];

        while(temp){
            if(temp->key == key) return true;
            temp = temp->next;
        }

        return false;
    }

    //deletion in hash-table
    void remove(string key) {
        int idx = hashFunction(key);

        Node* temp = table[idx];

        Node* prev = temp;

        while(temp != NULL){
            if(temp->key == key){
                if(prev == temp) {
                    table[idx] = temp->next;
                }else{
                    prev->next = temp->next;
                }

                break;
            }

            prev = temp;
            temp = temp->next;
        }
    }

    //print hash-table
    void print(){
        for(int i=0; i<totSize; i++){
            cout<<"idx"<<i<<"->";

            Node* temp = table[i];

            while(temp) {
                cout<<temp->key<<":"<<temp->val<<"->";
                temp = temp->next;
            }

            cout<<endl;
        }
    }

    //search in hash-table
    int search(string key) {
        int idx = hashFunction(key);

        Node* temp = table[idx];

        while(temp) {
            if(temp->key == key) return temp->val;
            temp = temp->next;
        }


        return -1;
    }
};

int main(){
    HashTable ht;

    ht.insert("India", 150);
    ht.insert("China", 150);
    ht.insert("US", 50);
    ht.insert("Nepal", 10);
    ht.insert("UK", 20);

    ht.print();

    cout<<endl;

    ht.remove("China");

    ht.print();

    cout<<endl;

    if(ht.exists("India")) {
        cout<<"India Population: "<<ht.search("India")<<endl;
    }


    return 0;
}