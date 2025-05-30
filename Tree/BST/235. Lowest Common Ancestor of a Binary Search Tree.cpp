TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL)
      return NULL;
    if(root->val == p->val)
      return p;
    if(root->val == q->val)
      return q;
    TreeNode* leftAns =  lowestCommonAncestor(root->left,p,q);
    TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);
    if(leftAns == NULL && rightAns == NULL)
      return NULL;
    else if(leftAns == NULL && rightAns != NULL)
      return rightAns;
    else if(leftAns != NULL && rightAns == NULL)
      return leftAns;
    else  //left!=NULL && right!=NULL
      return root;           
}