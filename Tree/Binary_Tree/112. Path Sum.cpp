bool solve(TreeNode* root,int target,int sum)
    {
        if(root == NULL)
          return false;
        sum += root->val;
        if(root->left == NULL && root->right == NULL)
        {
            if(sum == target)
              return true;
            else
               return false;  
        }  
        return  solve(root->left,target,sum) || solve(root->right,target,sum);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,targetSum,0);
    }