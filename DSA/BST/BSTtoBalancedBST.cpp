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

Node* insert(Node* root, int val){
    if(!root){
        return new Node(val);
    }

    else if(val < root->data){
        root->left = insert(root->left, val);
    }

    else{
        root->right = insert(root->right, val);
    }


    return root;
}

Node* buildBST(vector<int> &vec){
    int n = vec.size();

    Node* root = NULL;

    for(int i=0; i<n; i++){
        root = insert(root, vec[i]);
    }


    return root;
}

void levelOrder(Node* root){
    //step0: initialize data structure
    queue<Node*> q;

    //step1: push root and NULL into queue
    q.push(root); q.push(NULL);

    //step2: start while loop (until queue is not empty)
    while(!q.empty()){
        //step3: store front in currNode and pop front queue
        Node* currNode = q.front();
        q.pop();

        //step6: track next level
        if(!currNode){
            cout<<endl;
            if(q.empty()) break;
            q.push(NULL);
            continue;
        }

        //step4: print own data
        cout<<currNode->data<<" ";

        //step5: insert children of currNode into queue iff they're not empty
        if(currNode->left) q.push(currNode->left);
        if(currNode->right) q.push(currNode->right);
    }
}

void inOrder(Node* root, vector<int> &vec){
    if(!root) return;

    inOrder(root->left, vec);
    vec.push_back(root->data);
    inOrder(root->right, vec);
}

Node* buildBalancedBSTHelper(vector<int> &vec, int start, int end){
    if(start > end) return NULL;

    int mid = start + (end - start) / 2;

    Node* root = new Node(vec[mid]);

    root->left = buildBalancedBSTHelper(vec, start, mid-1);
    root->right = buildBalancedBSTHelper(vec, mid+1, end);
}

Node* buildBalancedBST(Node* root){
    vector<int> nodes;

    inOrder(root, nodes);

    return buildBalancedBSTHelper(nodes, 0, nodes.size()-1);
}


int main(){
    vector<int> vec = {6,5,4,3,7,8,9};
    Node* root = buildBST(vec);

    levelOrder(root);

    cout<<"-------------------------"<<endl;

    root = buildBalancedBST(root);

    levelOrder(root);


    return 0;
}

