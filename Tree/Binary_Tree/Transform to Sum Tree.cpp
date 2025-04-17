int sum(Node* root)
    {
        if(!root)
          return 0;
        if(!root->left && !root->right){
            int temp = root->data;
            root->data = 0;
            return temp;
        }
        int lsum = sum(root->left);
        int rsum = sum(root->right);
        int temp = root->data;
        root->data = lsum+rsum;
        return root->data+temp;
    }
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        // Your code here
        sum(node);
    }