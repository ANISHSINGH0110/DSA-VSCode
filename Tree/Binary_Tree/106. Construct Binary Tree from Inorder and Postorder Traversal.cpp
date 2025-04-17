int getInorderIndex(vector<int>&inorder,int target)
    {
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i] == target)
              return i;
        }
        return -1;
    }
    TreeNode* createTree(vector<int>&inorder,vector<int>&postorder,int &postInd,int inoS,int inoE,int size)
    {
        if(postInd < 0)
          return NULL;
        if(inoS > inoE)
          return NULL;  
        int element = postorder[postInd];
        postInd--;
        TreeNode* root = new TreeNode(element);
        int elementInd = getInorderIndex(inorder,element);
        root->right = createTree(inorder,postorder,postInd,elementInd+1,inoE,size);
        root->left = createTree(inorder,postorder,postInd,inoS,elementInd-1,size);

        return root;  
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postInd = postorder.size()-1;
        int inorderS = 0;
        int inorderE = inorder.size()-1;
        int size = inorder.size();
        TreeNode* root = createTree(inorder,postorder,postInd,inorderS,inorderE,size);
        return root;
    }