int findLeftHeight(TreeNode* root)
    {
        int cnt =0;
        while(root)
        {
            cnt++;
            root = root->left;
        }
        return cnt;
    }
    int findRightHeight(TreeNode* root)
    {
        int cnt = 0;
        while(root)
        {
            cnt++;
            root= root->right;
        }
        return cnt;
    }
    int countNodes(TreeNode* root) {
        if(!root)
          return 0;
        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);
        if(lh == rh)
          return (1 << lh)-1;
        int lAns = countNodes(root->left);
        int rAns = countNodes(root->right);
        return 1+lAns+rAns;    
    }