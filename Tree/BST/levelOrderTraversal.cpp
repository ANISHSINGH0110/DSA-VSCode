#include <bits/stdc++.h>
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
           root->right = buildBST(val,root->right);

    }
    return root;
 }
Node* createBST()
{
    cout << "Enter the value of node : " << endl;
    int val;
    cin >> val;
    Node* root = nullptr;
    while(val != -1)
    {
        root = buildBST(val,root);
        cout << "Enter the value of node : " << endl;
        cin >> val;
    }
    return root;
}
 void levelOrderTraversal(Node* root)
 {
    if(root == nullptr)
       return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node* curr = q.front();
        cout << curr->data << " ";
        q.pop();
        if(curr->left != nullptr)
           q.push(curr->left);
        if(curr->right != nullptr)
          q.push(curr->right);   
    }   
 }
 int getMin(Node* root)
 {
    if(root == nullptr)
      return -1;
    while(root->left != nullptr)
        root = root->left;
    return root->data;      
 }
 int getMax(Node* root)
 {
    if(root == nullptr)
      return -1;
    while(root->right != nullptr)
        root = root->right;
    return root->data;      
 }
 int main(){
    Node* root = createBST();
    cout << "Level Order Traversal of BST is  : " << endl;
    levelOrderTraversal(root);
    cout << endl;

    cout << "Minimum value in BST is : " << getMin(root) << endl;
    cout << "Maximum value in BST is : " << getMax(root) << endl;
    

    return 0;
 }
