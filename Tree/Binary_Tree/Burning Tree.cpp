Node* makeNodetoParentandFindTarget(Node*root,unordered_map<Node*,Node*>&parentMap,int target)
{
    queue<Node*>q;
    Node* targetNode = nullptr;
    q.push(root);
    parentMap[root] = 0;
    while(!q.empty())
    {
        Node* front = q.front();
        q.pop();
        if(front->data == target)
          targetNode = front;
        if(front->left)
        {
            q.push(front->left);
            parentMap[front->left] = front;
        }
        if(front->right)
        {
            q.push(front->right);
            parentMap[front->right] = front;
        }
    }
    return targetNode;
}
int burnTheTree(Node* targetNode,unordered_map<Node*,Node*>&parentMap)
{
    unordered_map<Node*,bool>isBurnt;
    queue<Node*>q;
    int t = 0;
    q.push(targetNode);
    isBurnt[targetNode] = 1;
    while(!q.empty())
    {
        int size = q.size();
        bool isFireSpreded = 0;
        for(int i=0;i<size;++i)
        {
            Node* front = q.front();
            q.pop();
            if(front->left && !isBurnt[front->left])
            {
                q.push(front->left);
                isBurnt[front->left] = 1;
                isFireSpreded = 1;
            }
            if(front->right && !isBurnt[front->right])
            {
                q.push(front->right);
                isBurnt[front->right] = 1;
                isFireSpreded = 1;
            }
            if(parentMap[front] && !isBurnt[parentMap[front]])
            {
                q.push(parentMap[front]);
                isBurnt[parentMap[front]] = 1;
                isFireSpreded = 1;
            }
        }
        if(isFireSpreded)
          ++t;
    }
    return t;
}
int minTime(Node* root, int target) {
    // code here
    unordered_map<Node*,Node*>parentMap;
    Node* targetNode = makeNodetoParentandFindTarget(root,parentMap,target);
    return burnTheTree(targetNode,parentMap);
}