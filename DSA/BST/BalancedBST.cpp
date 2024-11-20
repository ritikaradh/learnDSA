#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    //constructor
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* balancedBST(vector<int> &vec, int start, int end){
    //base case
    if(start > end) return NULL;

    //find mid
    int mid = start + (end - start)/2;

    //create mid node
    Node* root = new Node(vec[mid]);

    //call left and right childs
    root->left = balancedBST(vec, start, mid-1);
    root->right = balancedBST(vec, mid+1, end);


    //return root
    return root;
}

void levelOrder(Node* root){
    //step0: initialize data structures
    queue<Node*> q;

    //step1: insert root and NULL
    q.push(root); q.push(NULL);

    //step2: start while loop until queue not empty
    while(!q.empty()){
        //step3: store front in currNode and pop queue
        Node* currNode = q.front();
        q.pop();

        //step6: track next level
        if(!currNode){
            cout<<endl;
            if(q.empty()) break;
            q.push(NULL);
            continue;
        }

        //step4: print its own data
        cout<<currNode->data<<" ";

        //step5: insert children into queue iff they're not null
        if(currNode->left) q.push(currNode->left);
        if(currNode->right) q.push(currNode->right);
    }
}


int main(){
    vector<int> vec = {3,4,5,6,7,8,9};
    Node* root = balancedBST(vec,0,vec.size()-1);
    levelOrder(root);
    return 0;
}