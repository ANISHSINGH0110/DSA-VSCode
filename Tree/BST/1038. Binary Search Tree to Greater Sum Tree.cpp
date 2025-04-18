/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        void inorder(TreeNode* root,vector<int>&in)
        {
            if(root == NULL)
              return;
            inorder(root->left,in);
            in.push_back(root->val);
            inorder(root->right,in);  
        }
        void buildTree(TreeNode* root,vector<int>&inorder,int &i)
        {
            if(root == NULL)
              return;
            buildTree(root->left,inorder,i);
            root->val = inorder[i];
            i++;
            buildTree(root->right,inorder,i);  
        }
        TreeNode* bstToGst(TreeNode* root) {
            if(root == NULL)
              return NULL;
            if(root->left == NULL && root->right == NULL)
              return root;
            vector<int>in;
            inorder(root,in); 
            int n=in.size();
            for(int i=n-1;i>=0;i--)
            {
                int currVal = in[i];
                int nextVal = 0;
                if(i+1 < n)
                  nextVal = in[i+1];
                int sum = currVal+nextVal;
                in[i]=sum;  
            }   
            int index = 0;
            buildTree(root,in,index);
            return root;
        }
    };