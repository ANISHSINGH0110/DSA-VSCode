TreeNode* solve(vector<int>&inorder,int s,int e)
    {
        if(s > e)
          return NULL;
        int mid = (s+e)/2;
        int element = inorder[mid];
        TreeNode* root = new TreeNode(element);
        root->left = solve(inorder,s,mid-1);
        root->right = solve(inorder,mid+1,e);
        return root;  
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int s=0;
        int e = nums.size()-1;
        return solve(nums,s,e);
    }