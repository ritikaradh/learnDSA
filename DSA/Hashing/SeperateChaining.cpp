#include <iostream>
using namespace std;

class Node{
    public:
    int key;
    int val;
    Node* next;
    
    //constructor
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->next = NULL;
    }
    
    ~Node(){
        if(this->next) delete(this->next);
    }
};

class HashTable{
    int totSize;
    int currSize;
    Node** hashTable;
    
    int hash(int key){
        //seperate chaining
        int idx = key % totSize;
        
        return idx;
    }
    
    void rehash() {
        //step0: store totSize and table in some variables
        Node** oldTable = hashTable;
        int oldSize = totSize;
        
        //step1: increase totSize and reinitialize currSize to zero
        totSize = totSize * 2;
        currSize = 0;
        
        //step2: initialize new Table with NULL value
        hashTable = new Node*[totSize];
        for(int i=0; i<totSize; i++){
            hashTable[i] = NULL;
        }
        
        //step3: copy elements from old table to new table
        for(int i=0; i < oldSize; i++){
            Node* temp = oldTable[i];
            
            while(temp){
                insert(temp->key, temp->val);
                temp = temp->next;
            }
            
            if(oldTable[i]) delete oldTable[i];
        }
        
        
        delete[] oldTable;
    }
    
    public:
    
    //constructor
    HashTable(int totSize){
        this->totSize = totSize;
        this->currSize = 0;
        hashTable = new Node*[totSize];
        
        for(int i = 0; i < totSize; i++){
            hashTable[i] = NULL;
        }
    }
    
    void insert(int key, int val){
        int idx = hash(key);
        
        Node* newNode = new Node(key, val);
        
        newNode->next = hashTable[idx];
        hashTable[idx] = newNode;
        
        currSize++;
        
        //rehashing
        double lambda = currSize / (double)totSize;
        if(lambda > 1){
            rehash();
        }
    }
    
    void remove(int key) {
        int idx = hash(key);
        
        Node* temp = hashTable[idx];
        
        //case1: when head node
        if(temp->key == key){
            temp = temp->next;
            hashTable[idx] = temp;
            return;
        }
        
        //case2: when mid node or leaf node
        Node* prev = NULL;
        
        while(temp != NULL && temp->key != key){
            prev = temp;
            temp = temp->next;
        }
        
        prev->next = temp->next;
        temp->next = NULL;
    }
    
    bool isPresent(int key){
        int idx = hash(key);
        
        Node* temp = hashTable[idx];
        
        while(temp != NULL){
            if(temp->key == key){
                return true;
            }
            temp = temp->next;
        }
        
        
        return false;
    }
    
    int search(int key){
        int idx = hash(key);
        
        Node* temp = hashTable[idx];
        
        while(temp){
            if(temp->key == key){
                return temp->val;
            }
            temp = temp->next;
        }
        
        
        return -1;
    }
    
    void print(){
        for(int i=0; i<totSize; i++){
            Node* temp = hashTable[i];
            cout<<"idx="<<i<<" -> ";
            while(temp){
                cout<<temp->key<<":"<<temp->val<<"->";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
};

int main() {
    HashTable ht(5);
    ht.insert(15, 100);
    ht.insert(16, 101);
    ht.insert(17, 102);
    ht.insert(18, 103);
    ht.insert(19, 104);
    ht.insert(20, 105);
    
    // cout<<"key 15: val "<<ht.search(15)<<endl;
    // cout<<"key 16: val "<<ht.search(16)<<endl;
    // cout<<"key 17: val "<<ht.search(17)<<endl;
    // cout<<"key 18: val "<<ht.search(18)<<endl;
    // cout<<"key 19: val "<<ht.search(19)<<endl;
    // cout<<"key 20: val "<<ht.search(20)<<endl;
    
    ht.print();
    

    return 0;
}