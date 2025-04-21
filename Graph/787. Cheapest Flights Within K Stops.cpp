class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            unordered_map<int,list<pair<int,int>>>grp;//adjList src,dst,price
            for(auto flight:flights)
               grp[flight[0]].push_back({flight[1],flight[2]});
            //pq to select the next city with minm cost   
            priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
            pq.push({0,src,0});
            //each element ->{cost so far,curr city,stops so far}
            //visited array storing minm number of stops to reach a city
            vector<int>vis(n,INT_MAX);
            vis[src] = 0;
            while(!pq.empty())
            {
                auto curr = pq.top();
                pq.pop();
                int cost = curr[0];
                int city = curr[1];
                int stops = curr[2];
                if(city == dst)
                  return cost;
                if(stops > k)
                  continue;
                if(vis[city] != INT_MAX  && vis[city] <stops)
                  continue;
                vis[city] = min(vis[city],stops);
                for(auto &nbr:grp[city])
                {
                    int nextCity = nbr.first;
                    int price = nbr.second;
                    pq.push({cost+price,nextCity,stops+1});
                }  
            }
            return -1;
        }
    };