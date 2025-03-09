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
        unordered_map<char, TrieNode*> children(26);
        isEnd = false;
    }

    //destructor
    ~TrieNode(){
        cout<<"destructor called"<<endl;
    }
};

class Trie{
    TrieNode* root;


    public:

    //constructor
    Trie(){
        //initialize the topmost node
        TrieNode* root = new TrieNode();
    }

    //insert
    void insert(string key){
        int n = key.size();
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

        cout<<"destructor called"<<endl;
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

    return 0;
}