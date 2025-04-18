void inorder(TreeNode* root,vector<int>&num)
    {
        if(root == NULL)
          return;
        inorder(root->left,num);
        num.push_back(root->val);
        inorder(root->right,num);   
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        inorder(root,ans);
        return ans[k-1];
    }