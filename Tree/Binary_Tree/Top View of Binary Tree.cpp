vector<int> topView(Node *root) {
    // code here
    queue<pair<Node*,int>>q;
    q.push(make_pair(root,0));
    unordered_map<int,Node*>distMap;
    int minDist = INT_MAX;
    int maxDist = INT_MIN;
    while(!q.empty())
    {
        pair<Node*,int>frontPair = q.front();
        q.pop();
        No de* frontNode = frontPair.first;
        int hd = frontPair.second;
        minDist = min(minDist,hd);
        maxDist = max(maxDist,hd);
        if(distMap.find(hd) == distMap.end())
          distMap[hd] = frontNode;
        if(frontNode->left != NULL)
          q.push(make_pair(frontNode->left,hd-1));
        if(frontNode->right != NULL)
          q.push(make_pair(frontNode->right,hd+1));
    }
    vector<int>ans;
    for(int i=minDist;i<=maxDist;i++)
    {
        Node* temp = distMap[i];
        ans.push_back(temp->data);
    }
    return ans;
}