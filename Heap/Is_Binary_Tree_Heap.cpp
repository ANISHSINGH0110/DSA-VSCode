#include <bits/stdc++.h>
using namespace std;
bool solve(struct Node* root)
    {
        queue<Node*>q;
        q.push(root);
        bool nullFound = false;
        while(!q.empty())
        {
            Node* front = q.front();
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
    bool checkCompleteness(struct Node* root) {
      return solve(root);  
    }
    bool checkMaxProperty(struct Node* root)
    {
        if(root == NULL)
           return true;
        if(root->left == NULL && root->right == NULL)
          return true;
        bool leftAns = checkMaxProperty(root->left);
        bool rightAns = checkMaxProperty(root->right);
        bool op1 = true;
        if(root->left && root->data < root->left->data)
          op1 = false;
        bool op2 = true;
        if(root->right && root->data < root->right->data)
          op2 = false; 
        bool currAns = op1 && op2 ;
        if(currAns && leftAns && rightAns)
          return true;
        else
           return false;
          
        
    }
    bool isHeap(struct Node* tree) {
        // code here
        bool completeness = checkCompleteness(tree);
        bool maxProperty = checkMaxProperty(tree);
        if(completeness && maxProperty)
          return true;
        else
           return false;
    }