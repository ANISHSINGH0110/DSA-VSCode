#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
       int data;
       Node* left;
       Node* right;
       Node(int val){
           data = val;
           left = nullptr;
           right = nullptr;
       }
};
int maxDepth(Node* root) {
    if(root == nullptr)
      return 0;
    return 1+max(maxDepth(root->left),maxDepth(root->right));  
}
int main(){
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(21);
    root->left->left = new Node(23);
    root->left->right = new Node(39);
    cout << "Maximum Depth of B.t " << maxDepth(root) << endl;
    return 0;
}