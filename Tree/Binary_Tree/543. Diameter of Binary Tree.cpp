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
int maxDepth(Node* root)
    {
        if(root == NULL)
          return 0;
        return 1+ max(maxDepth(root->left),maxDepth(root->right));  
    }
    int diameterOfBinaryTree(Node* root) {
        if(root == NULL)
          return 0;
        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);
        int height = maxDepth(root->right)+maxDepth(root->left);  
        return max(left,max(right,height));
    }
    int main(){
        Node* root = new Node(3);
        root->left = new Node(9);
        root->right = new Node(21);
        root->left->left = new Node(23);
        root->left->right = new Node(39);
        cout << "Maximum Diameter of B.t " << diameterOfBinaryTree(root) << endl;
        return 0;
    }