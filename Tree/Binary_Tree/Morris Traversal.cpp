vector<int> inorderTraversal(TreeNode* root) {
    vector<int>ans;
    TreeNode* curr = root;
    while(curr)
    {//left node is null, then visit it and go right
        if(curr->left == nullptr)
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else//left node is not null
        {
            TreeNode* pred = curr->left;//find inorder predecessor
            while(pred->right != curr && pred->right)
               pred = pred->right;
            //pred right node is null then go left after establising link from pred to curr   
            if(pred->right == nullptr)
            {
                pred->right = curr;
                curr = curr->left;
            }   
            else//left is already visited go right after visiting curr node
            {
                pred->right = nullptr;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return ans;
}