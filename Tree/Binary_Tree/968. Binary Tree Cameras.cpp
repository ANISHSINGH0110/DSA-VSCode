int solve(TreeNode* root,int &cameras)
{
    if(!root)//all nodes are assumed to covered
      return 1;
    int left = solve(root->left,cameras);
    int right = solve(root->right,cameras);
    if(left == 0 || right == 0)//either node are not covered
    {
        cameras++;
        return 2;//my cam is installed
    }  
    if(left == 2 || right == 2)
      return 1;//i am covered by my child
    return 0; // I'm not covered 
}
int minCameraCover(TreeNode* root) {
    int cameras = 0;
    int rootState = solve(root,cameras);
    if(rootState == 0)
      cameras++;
    return cameras;  
}