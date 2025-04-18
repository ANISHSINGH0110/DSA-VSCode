void solve(TreeNode* root,int &ans,TreeNode* &prev)
{
    if(!root)
      return;
    solve(root->left,ans,prev);
    if(prev)
      ans = min(ans,root->val-prev->val);
    prev = root;
    solve(root->right,ans,prev);    
}
int minDiffInBST(TreeNode* root) {
    TreeNode* prev = nullptr;
    int ans = INT_MAX;
    solve(root,ans,prev);
    return ans;
}