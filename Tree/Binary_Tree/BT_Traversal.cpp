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
Node* createTree()
{
    cout << "Enter the value for Node : " << endl;
    int val;
    cin >> val;
    if(val == -1)
      return nullptr;
    else
    {
        Node* root = new Node(val);
        cout << "Adding left child for " << val << endl;
        root->left = createTree();
        cout << "Adding right child for " << val << endl;
        root->right = createTree();

        return root;
    }  
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
    root = createTree();
    cout << "Printing root " << root->data << endl;
    
    cout << "Preorder of binary tree " << endl;
    preorder(root);

    cout << "Inorder of binary tree " << endl;
    inorder(root);

    cout << "Postorder of binary tree " << endl;
    postOrder(root);

    return 0;
}