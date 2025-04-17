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
int getHeight(Node* root)
    {
        if(root == NULL)
          return 0;
        return 1+max(getHeight(root->left),getHeight(root->right));  
    }
    bool isBalanced(Node* root) {
        if(root == nullptr)
          return true;
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        int absDiff = abs(lh-rh);
        bool status = (absDiff <= 1);
        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);
        if(status && leftAns && rightAns)
          return true;
        else
          return false;    
    }
int main(){
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(21);
    root->left->left = new Node(23);
    root->left->right = new Node(39);
    cout << "B.T is balanced or not :  " << isBalanced(root) << endl;
    return 0;
}