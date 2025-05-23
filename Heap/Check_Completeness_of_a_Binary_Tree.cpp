#include <bits/stdc++.h>
using namespace std;
bool solve(TreeNode* root)
    {
        queue<TreeNode*>q;
        q.push(root);
        bool nullFound = false;
        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();
            if(front == NULL)
              nullFound = true;
            else
            {
                if(nullFound == true)
                  return false;
                else
                {
                    q.push(front->left);
                    q.push(front->right);
                }  
            }  
        }
        return true;
    }
    bool isCompleteTree(TreeNode* root) {
      return solve(root);  
    }