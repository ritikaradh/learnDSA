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

void levelOrder(Node* root){
    //step0: initialize data structure
    queue<Node*> q;

    //step1: push root and NULL into queue
    q.push(root);
    q.push(NULL);

    //step2: start while loop until the queue is not empty
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

        //step4: print its own data
        cout<<currNode->data<<" ";

        //step5: insert left and right children iff they're not empty
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

Node* buildBalancedBST(vector<int> &vec, int start, int end){
    //base case
    if(start > end) return NULL;

    //find mid
    int mid = start + (end - start) / 2;

    //create root node
    Node* root = new Node(vec[mid]);

    //create left and right subtrees for root
    root->left = buildBalancedBST(vec, start, mid-1);
    root->right = buildBalancedBST(vec, mid+1, end);


    //return
    return root;
}

Node* mergedBST(Node* root1, Node* root2){
    vector<int> vec1;
    vector<int> vec2;
    vector<int> merged;

    inOrder(root1, vec1);
    inOrder(root2, vec2);

    //merge two sorted vectors
    int i = 0, j = 0;
    while(i < vec1.size() && j < vec2.size()){
        if(vec1[i] < vec2[j]){
            merged.push_back(vec1[i++]);
        }else{
            merged.push_back(vec2[j++]);
        }
    }
    while(i < vec1.size()){
        merged.push_back(vec1[i++]);
    }
    while(j < vec2.size()){
        merged.push_back(vec2[j++]);
    }

    //create balanced bst out of merged sorted vector
    return buildBalancedBST(merged, 0, merged.size()-1);
}

int main(){
    //first bst
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    //second bst
    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

    //get merged bst root
    Node* root = mergedBST(root1, root2);

    //print level order sequence of merged bst
    levelOrder(root);


    //return
    return 0;
}