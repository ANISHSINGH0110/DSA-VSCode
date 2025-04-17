#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val){
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
    else{
        Node* root = new Node(val);
        cout << "Adding left child for " << val << endl;
        root->left = createTree();
        cout << "Adding right child for " << val << endl;
        root->right = createTree();
        return root;
    }  
}
void levelOrder(Node* root){
    if(root == nullptr)
      return;
    queue<Node*>q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
      Node* frontNode = q.front();
      q.pop();
      if(frontNode == nullptr){
        cout << endl;
        if(!q.empty()){
          q.push(nullptr);
        }
      
      }
      else{
        cout << frontNode->data << " ";
        if(frontNode->left){
          q.push(frontNode->left);
        }
        if(frontNode->right){
          q.push(frontNode->right);
        }
      }
    }  
}
int main(){
    Node* root = createTree();
    cout << "Printing root of b.t " << root->data << endl;
    
    cout << "Level order Traversal of B.T is : " << endl;
    levelOrder(root);
    

    return 0;
}