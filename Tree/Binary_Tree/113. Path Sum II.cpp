void solve(TreeNode* root,int target,int sum,vector<int>&path,vector<vector<int>>&ans)
{
    if(root == NULL)
      return ;
    sum += root->val;
    path.push_back(root->val);
    if(root->left == NULL && root->right == NULL)
    {
        if(sum == target)
          ans.push_back(path);
        path.pop_back();
        return;
    }  
    solve(root->left,target,sum,path,ans);
    solve(root->right,target,sum,path,ans);
    path.pop_back();  
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
   vector<vector<int>>ans;
   vector<int>path;
   int sum = 0;
   solve(root,targetSum,sum,path,ans);
   return ans; 
}