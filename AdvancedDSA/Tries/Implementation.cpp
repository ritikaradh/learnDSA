#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class TrieNode{
    public:
    
    unordered_map<char, TrieNode*> children;
    bool isEnd;

    //constructor
    TrieNode(){
        isEnd = false;
    }

    //destructor
    ~TrieNode(){
        cout<<"trie node destructor called"<<endl;
    }
};

class Trie{
    TrieNode* root;

    void deleteTrie(TrieNode* node){
        if(!node) return;

        for(pair<char, TrieNode*> child: node->children){
            deleteTrie(child.second);
        }

        delete node;
    }


    public:

    //constructor
    Trie(){
        //initialize the topmost node
        root = new TrieNode();
    }

    //insert
    void insert(string key){
        TrieNode* temp = root;

        for(char ch: key){
            if(temp->children.count(ch) > 0){
                temp = temp->children[ch];
            }
            else{
                temp->children[ch] = new TrieNode();
                temp = temp->children[ch];
            }
        }

        temp->isEnd = true;

        cout<<"Node inserted successfully"<<endl;
    }

    //search
    bool exists(string key){
        TrieNode* temp = root;

        for(char ch: key){
            if(temp->children.count(ch) > 0){
                temp = temp->children[ch];
            }else{
                return false;
            }
        }

        return temp->isEnd == true;
    }


    //destructor
    ~Trie(){
        deleteTrie(root);
        cout<<"Trie deleted successfully"<<endl;
    }
};

int main(){
    vector<string> vec = {"i", "love", "sam", "sung", "and", "samsung"};

    Trie* trie = new Trie();

    for(int i=0; i<vec.size(); i++){
        trie->insert(vec[i]);

    }

    cout<<trie->exists("sam")<<endl;
    cout<<trie->exists("song")<<endl;


    delete trie;

    return 0;
}