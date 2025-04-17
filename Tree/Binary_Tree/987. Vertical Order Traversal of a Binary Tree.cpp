vector<vector<int>> verticalTraversal(TreeNode* root) {
    // Map to store nodes by their horizontal and vertical levels
    map<int, map<int, vector<int>>> nodes;
    // Queue for BFS traversal: stores node and its horizontal and vertical levels
    queue<pair<TreeNode*, pair<int, int>>> q;
    
    if (root == nullptr) {
        return {};
    }
    
    // Start BFS with root node at horizontal level 0 and vertical level 0
    q.push({root, {0, 0}});
    
    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        TreeNode* frontNode = temp.first;
        int hd = temp.second.first; // horizontal distance
        int lvl = temp.second.second; // vertical level
        
        // Insert node value into the map
        nodes[hd][lvl].push_back(frontNode->val);
        
        // If there's a left child, push it onto the queue with updated levels
        if (frontNode->left) {
            q.push({frontNode->left, {hd - 1, lvl + 1}});
        }
        // If there's a right child, push it onto the queue with updated levels
        if (frontNode->right) {
            q.push({frontNode->right, {hd + 1, lvl + 1}});
        }
    }
    
    // Prepare the result in the required format
    vector<vector<int>> ans;
    for (auto& p : nodes) {
        vector<int> column;
        for (auto& q : p.second) {
            // Sort values in ascending order of node values
            sort(q.second.begin(), q.second.end());
            // Append sorted values to the column
            column.insert(column.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(column);
    }
    
    return ans;
}