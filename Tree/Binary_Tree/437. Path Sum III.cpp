    int ans = 0;
    void pathFromRoot(TreeNode* root,long long sum)
    {
        if(!root)
          return;
        if(sum == root->val)
          ++ans;
        pathFromRoot(root->left,sum-root->val);
        pathFromRoot(root->right,sum-root->val);    
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root)
        {
            pathFromRoot(root,targetSum);
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);
        }
        return ans;
    }