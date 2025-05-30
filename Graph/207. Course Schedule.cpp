class Solution {
    public:
        bool topoSortBFS(unordered_map<int,list<int>>adj,int n)
        {
            unordered_map<int,int>indegree;
            vector<int>topoOrder;
            for(int i=0;i<n;i++)
            {
                indegree[i] = 0;
            }
            //cal indegree of each node
            for(auto i:adj)
            {
                int u = i.first;
                for(auto j:i.second)
                {
                    int v =j;
                    indegree[v]++;
                }
            }
            //bfs logic
            queue<int>q;
            //initial state
            for(int i=0;i<n;i++)
            {
                if(indegree[i] == 0)
                  q.push(i);
            }
            //main bfs logic
            while(!q.empty())
            {
                int front = q.front();
                topoOrder.push_back(front);
                q.pop();
                //nbr check
                for(auto nbr: adj[front])
                {
                    indegree[nbr]--;
                    if(indegree[nbr] == 0)
                      q.push(nbr);
                }
            }
            //valid or not
            if(topoOrder.size() == n)
              return true;
            return false;  
        }
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            //create adj list
            unordered_map<int,list<int>>adj;
            for(auto i:prerequisites)
            {
                int u = i[1];
                int v = i[0];
                adj[u].push_back(v);
            }
            bool ans = topoSortBFS(adj,numCourses);
            return ans;
        }
    };