int getMax(TreeNode* root)
    {
        if(root == NULL)
          return -1;
        while(root->right)
           root = root->right;
        return root->val;     
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
          return NULL;
        if(root->val == key) //found
        {
            if(root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            if(root->left != NULL && root->right == NULL)//with left child only
            {
                TreeNode* leftPart = root->left;
                root->left = NULL;
                delete root;
                return leftPart;
            }
            if(root->left == NULL && root->right != NULL)//with right child only
            {
                TreeNode* rightPart = root->right;
                root->right = NULL;
                delete root;
                return rightPart;
            }
            //with both left and right child
            if(root->left != NULL && root->right != NULL)
            {
                int maxVal = getMax(root->left);
                root->val = maxVal;
                root->left = deleteNode(root->left,maxVal);
                return root;
            }
        }  
        //Not match go left and right
        else
        {
            if(key < root->val)
              root->left = deleteNode(root->left,key);
            else
               root->right = deleteNode(root->right,key);  
        }
        return root;
    }