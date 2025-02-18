#include <iostream>
using namespace std;

class Node{
    public:
       int data;
       Node* left;
       Node* right;
       Node(int val)
       {
          this->data = val;
          this->left = nullptr;
          this->right = nullptr;
       }
};
Node* buildBST(int val,Node* root)
{
    if(root == nullptr)
    {
        root = new Node(val);
        return root;
    }
    else
    {
        if(val < root->data)
          root->left = buildBST(val,root->left);
        else
        {
            root->right = buildBST(val,root->right);
        }  
    }
    return root;
}
Node* createBST()
{
    cout << " Enter the value for node " << endl;
    int val;
    cin >> val;
    Node* root = nullptr;
    while(val != -1)
    {
        root = buildBST(val,root);
        cout << "Enter the value for Node: " << endl;
        cin >> val;
    }
    return root;
}
void preorder(Node* root)
{
    if(root == nullptr)
      return;
    
    cout << root->data << " " << endl;
    preorder(root->left);
    preorder(root->right);  
}
void inorder(Node* root)
{
    if(root == nullptr)
      return;
    
    inorder(root->left);
    cout << root->data << " " << endl;
    inorder(root->right);  
}
void postOrder(Node* root)
{
    if(root == nullptr)
      return;
    
    postOrder(root->left);
    postOrder(root->right);  
    cout << root->data << " " << endl;
}

int main()
{
    Node* root;
    root = createBST();
    cout << "Printing root " << root->data << endl;
    
    cout << "Preorder of binary tree " << endl;
    preorder(root);

    cout << "Inorder of binary tree " << endl;
    inorder(root);

    cout << "Postorder of binary tree " << endl;
    postOrder(root);

    return 0;
}