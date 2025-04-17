int getIndexInorder(vector<int>inorder,int target)
    {
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i] == target)
              return i;
        }
        return -1;
    }
    TreeNode* constructTree(vector<int>&preorder,vector<int>&inorder,int &preInd,int inoS,int inoE,int size)
    {
        if(preInd >= size)
          return NULL;
        if(inoS > inoE)
          return NULL;
        int element = preorder[preInd];
        preInd++;
        TreeNode* root = new TreeNode(element);
        int elementInd = getIndexInorder(inorder,element);
        root->left = constructTree(preorder,inorder,preInd,inoS,elementInd-1,size);
        root->right = constructTree(preorder,inorder,preInd,elementInd+1,inoE,size);
        return root;    
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        int inorderS = 0;
        int inorderE = inorder.size()-1;
        int size = inorder.size();
        TreeNode* root = constructTree(preorder,inorder,preIndex,inorderS,inorderE,size);
        return root;
    }