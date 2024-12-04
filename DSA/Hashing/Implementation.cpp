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


        return idx;
    }

    //rehash-function
    void rehash() { //O(n)
        Node** oldTable = table;
        int oldSize = totSize;

        totSize = 2*totSize;

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
        Node* head = table[idx];

        newNode->next = head;
        head = newNode;

        currSize++;

        double lambda = currSize / (double)totSize;

        if(lambda > 1) rehash(); //O(n) - worst t.c
    }

    //deletion in hash-table
    void remove(string key) {

    }

    //search in hash-table
    int search(string key) {

    }
};

int main(){
    HashTable ht;
}