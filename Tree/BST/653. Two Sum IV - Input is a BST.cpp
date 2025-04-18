void storeInorder(TreeNode* root,vector<int>&in)
    {
        if(root == NULL)
          return;
        storeInorder(root->left,in);
        in.push_back(root->val);
        storeInorder(root->right,in);  
    }
    bool checkTwoSum(vector<int>arr,int target)
    {
        int n = arr.size();
        int s =0;
        int e = n-1;
        while(s < e)
        {
            int sum = arr[s]+arr[e];
            if(sum == target)
              return true;
            if(sum > target)
              e--;
            if(sum < target)
              s++;    
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        storeInorder(root,inorder);
        bool ans = checkTwoSum(inorder,k);
        return ans;
    }