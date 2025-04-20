class Solution {
    public:
        void dfs(int node,vector<int>&edges,vector<bool>& visited,vector<bool>& dfsTracker,vector<int>& dist,int currLength,int &longestCycleLength)
        {
            if(node == -1)
              return;
            visited[node] = true;
            dfsTracker[node] = true;
            dist[node] = currLength;
            int nextNode = edges[node];
            if(nextNode != -1)
            {
                if(!visited[nextNode])
                  dfs(nextNode,edges,visited,dfsTracker,dist,currLength+1,longestCycleLength);
                else if(dfsTracker[nextNode]) //cycle is there
                {
                    int cycleLength = currLength-dist[nextNode]+1;
                    longestCycleLength = max(longestCycleLength,cycleLength);
                }  
            }  
            dfsTracker[node] = false; //backtrack;
        }
        int longestCycle(vector<int>& edges) {
            int n = edges.size();
            vector<bool>visited(n,0);
            vector<bool>dfsTracker(n,0);
            vector<int>dist(n,0);
            int longestCycleLength = -1;
            for(int i=0;i<n;i++)
            {
                if(!visited[i])
                  dfs(i,edges,visited,dfsTracker,dist,0,longestCycleLength);
            }
            return longestCycleLength;
        }
    };