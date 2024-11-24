#include <iostream>
#include <vector>
#include <queue>
#include <utility>
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

void inOrder(Node* root, vector<int> &vec){
    if(!root) return;

    inOrder(root->left,vec);
    vec.push_back(root->data);
    inOrder(root->right,vec);
}

bool twoSumTarget(Node* root1, Node* root2, int target){
    if(!root1 || !root2) return false;

    vector<int> tree1;
    vector<int> tree2;

    inOrder(root1, tree1);
    inOrder(root2, tree2);

    vector<pair<int,int>> ans;

    bool isFound = false;
    int i = 0; //pointer for tree 1
    int j = tree2.size()-1; //pointer for tree 2

    while(i < tree1.size() && j >= 0){
        int currSum = tree1[i] + tree2[j];

        if(currSum == target){
            ans.push_back(make_pair(tree1[i],tree2[j]));
            isFound = true;
            i++, j--;
        }

        else if(currSum < target){
            i++;
        }
        
        else{
            j--;
        }
    }

    for(auto p: ans){
        cout<<p.first<<","<<p.second<<endl;
    }

    return isFound;
}

int main() {
    // First BST
    Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(7);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);
    root1->right->left = new Node(6);
    root1->right->right = new Node(8);

    // Second BST
    Node* root2 = new Node(10);
    root2->left = new Node(6);
    root2->right = new Node(15);
    root2->left->left = new Node(3);
    root2->left->right = new Node(8);
    root2->right->left = new Node(11);
    root2->right->right = new Node(18);

    //return pairs that sums to target
    cout<<twoSumTarget(root1, root2, 17)<<endl;


    //return
    return 0;
}