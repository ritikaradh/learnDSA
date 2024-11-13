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

static int idx = -1;

Node* buildTree(vector<int> &lis){
    idx++;

    if(lis[idx] == -1) return NULL;

    Node* root = new Node(lis[idx]);

    root->left = buildTree(lis);
    root->right = buildTree(lis);


    return root;
}

void levelOrder(Node* root){
    //step0: initialize data structure
    queue<Node*> q;

    //step1: push root and NULL into the queue
    q.push(root);   
    q.push(NULL);

    //step2: start while loop (until q is not empty)
    while(!q.empty()){
        //step3: store front in currNode and pop front the queue
        Node* currNode = q.front(); 
        q.pop();

        //step6: base case ie., track next level
        if(!currNode){
            cout<<endl;
            if(q.empty()) break;
            q.push(NULL);
            continue;
        }

        //step4: print self data
        cout<<currNode->data<<" ";

        //step5: call children iff they're not null
        if(currNode->left) q.push(currNode->left);
        if(currNode->right) q.push(currNode->right);
    }
}

bool searchBST(Node* root, int key){
    if(root == NULL) return false;

    if(root->data == key) return true;

    else if(root->data > key){
        return searchBST(root->left, key);
    }

    else{
        return searchBST(root->right, key);
    }
}

int main(){
    vector<int> lis = {5, 2, 1, -1, -1, 4, 3, -1, -1, -1, 6, -1, 7, -1, -1};
    Node* root = buildTree(lis);

    cout<<searchBST(root, 3)<<endl;
    cout<<searchBST(root, 10)<<endl;

    cout<<"------------------------------"<<endl;

    levelOrder(root);

    return 0;
}