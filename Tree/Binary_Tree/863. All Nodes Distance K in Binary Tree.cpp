 //step1 create child to parent mapping
 void mapParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parentMap)
 {
     if(!root)
       return ;
     if(root->left)
     {
         parentMap[root->left] = root;
         mapParent(root->left,parentMap);
     }  
     if(root->right)
     {
         parentMap[root->right] = root;
         mapParent(root->right,parentMap);
     }
 }
 vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
     unordered_map<TreeNode*,TreeNode*>parentMap;
     parentMap[root] = nullptr;
     mapParent(root,parentMap);
     unordered_map<TreeNode*,bool>visited;
     queue<TreeNode*>q;
     q.push(target);
     visited[target] = true;
     int currLevel = 0;
     while(!q.empty())
     {
         int size = q.size();
         if(currLevel == k)//ans node should be present in queue itself
           break;
         currLevel++;
         //traverse over all nodes at curr level
         for(int i=0;i<size;i++)
         {
             auto front = q.front();
             q.pop();
             if(front->left && visited.find(front->left) == visited.end())
             {
                 q.push(front->left);//front has its left child and not visited yet
                 visited[front->left] = true;
             }
             if(front->right && visited.find(front->right) == visited.end())
             {
                 q.push(front->right);//front has it's right child and not visited yet
                 visited[front->right] = true;
             }
             //process parent too
             auto parentNodeOfFront = parentMap[front];
             if(parentNodeOfFront && visited.find(parentNodeOfFront) == visited.end())
             {
                 q.push(parentNodeOfFront);
                 visited[parentNodeOfFront] = true;
             }
         }
     }
     vector<int>ans;
     while(!q.empty())
     {
         auto front = q.front();
         q.pop();
         ans.push_back(front->val);
     }
     return ans;
 }