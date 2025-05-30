void solve(TreeNode* root,int &sum)
    {
        if(root == NULL)
          return ;
        solve(root->right,sum);
        sum += root->val;
        root->val = sum;
        solve(root->left,sum);  
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL)
          return root;
        int sum = 0;
        solve(root,sum);
        return root;  
    }