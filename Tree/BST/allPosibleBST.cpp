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
          left = nullptr;
          right = nullptr;
       }
};
vector<Node*>buildBST(int s,int e)
{
    vector<Node*>allTree;
    if(s > e)
    {
        allTree.push_back(nullptr);
        return allTree;
    }
    for(int i=s;i<=e;i++)
    {
        vector<Node*>leftTree = buildBST(s,i-1);
        vector<Node*>rightTree = buildBST(i+1,e);
        for(auto left:leftTree)
        {
            for(auto right:rightTree)
            {
                Node* root = new Node(i);
                root->left = left;
                root->right = right;
                allTree.push_back(root);

            }
        }
    }
    return allTree;
}
vector<Node*>generateAllPossibleBST(int n)
{
    if(n == 0)
      return {};
    return buildBST(1,n);  
}
void preorder(Node* root)
{
    if(root == nullptr)
      return ;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);  
}
int main()
{
    int n;
    cout << "Enter the value of n : " << endl;
    cin >> n;
    vector<Node*>ans = generateAllPossibleBST(n);
    cout << "Preorder Traversal of BST is : " << endl;
    for(auto i : ans)
    {
        preorder(i);
        cout << endl;

    }
    return 0;


}