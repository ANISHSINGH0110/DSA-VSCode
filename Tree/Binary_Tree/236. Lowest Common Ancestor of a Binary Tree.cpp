#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
       int val;
       Node* left;
       Node* right;
       Node(int val){
         val = val;
         left = nullptr;
         right = nullptr;
       }
};
Node* createTree()
{
    cout << "Enter the value of root node: ";
    int val;
    cin >> val;
    if(val == -1)
      return nullptr;
    else{
        Node* root = new Node(val);
        cout << "Enter the left child of " << val << ":";
        root->left = createTree();
        cout << "Enter the right child of " << val << ":";
        root->right = createTree();
        return root;
    }  
}
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if(root == NULL)
      return NULL;
    if(root->val == p->val)
      return p;
    if(root->val == q->val)
      return q;
    Node* leftAns = lowestCommonAncestor(root->left,p,q);
    Node* rightAns = lowestCommonAncestor(root->right,p,q);
    if(leftAns == NULL && rightAns == NULL)
      return NULL;
    if(leftAns == NULL && rightAns != NULL)
      return rightAns;
    else if(leftAns != NULL && rightAns == NULL)
      return leftAns;  
    else 
      return root;          
}

int main(){
    // Node* root = new Node(3);
    // root->left = new Node(9);
    // root->right = new Node(21);
    // root->left->left = new Node(23);
    // root->left->right = new Node(39);

    Node* root = createTree();
    
    cout << "LCA of B.T  :  " << lowestCommonAncestor(root,root->left,root->right)->val << endl;
    return 0;
}