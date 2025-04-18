int widthOfBinaryTree(TreeNode* root) {
    unsigned long long maxWidth = 0;
    if(!root)
      return maxWidth;
    queue<pair<TreeNode*,unsigned long long>>q;
    q.push({root,1});
    while(!q.empty())
    {
       unsigned long long size = q.size();
       //this is curr level no. of nodes
       unsigned long long leftMostNodeIndex = q.front().second;
       unsigned long long rightMostNodeIndex = q.back().second;
       unsigned long long currLevelWidth = rightMostNodeIndex-leftMostNodeIndex+1;
       maxWidth = max(maxWidth,currLevelWidth);
       //traverse overall nodes at the current level
       for(int i=0;i<size;i++)
       {
         auto front = q.front();
         q.pop();
         auto node = front.first;
         auto index = front.second;
         //process it's child and assign then the index
         if(node->left)
           q.push({node->left,2*index});
         if(node->right)
           q.push({node->right,2*index+1});  
       }
    }   
    return maxWidth;
 }