#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
       int data;
       Node* left;
       Node* right;
       Node(int val)
       {
          data = val;
          left = NULL;
          right = NULL;
       }
};
Node* buildBST(int val,Node* root)
{
    if(root == nullptr)
    {
        root = new Node(val);
        return root;
    }
    else{
        if(val < root->data)
           root->left = buildBST(val,root->left);
        else
           root->right = buildBST(val,root->right);   
    }
    return root;
}
Node* searchBST(int val,Node* root){
    if(root == nullptr || root->data == val)
       return root;
    if(val <root->data)
       return searchBST(val,root->left);
    else if(val > root->data)
       return searchBST(val,root->right); 
    else
       return nullptr;        
}
int main(){
     Node* root = nullptr;
     cout << "Enter the vlaue of Node : " << endl;
     int val;
     cin >> val;
     while(val != -1){
        root = buildBST(val,root);
        cout << "Enter the value of Node : " << endl;
        cin >> val;
     }
     Node* ans = searchBST(5,root);
     if(ans != nullptr)
        cout << "Node Found : " << ans->data << endl;
     else
       cout << "Node not Found" << endl;
          
    return 0;
}