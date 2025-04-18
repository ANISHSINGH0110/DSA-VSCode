pair<int,int>solve(Node* root)
    {
        if(!root)
          return {0,0};
        auto left = solve(root->left);
        auto right = solve(root->right);
        //sum including the node
        int a = root->data + left.second+right.second;
        //sum excluding the node
        int b = max(left.first,left.second)+max(right.first,right.second);
        return {a,b};
    }
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        // Add your code here
        auto ans = solve(root);
        return max(ans.first,ans.second);
    }