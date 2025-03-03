#include<iostream>
#include<unordered_map>
#include <vector>
#include<list>
#include<algorithm>
#include<limits.h>
#include<stack>
using namespace std;

class Graph{
    public:
      unordered_map<int,list<pair<int,int>>>adjList;
      void addEdge(int u,int v,int wt,bool direction)
      {
         if(direction == 0)//undirected Graph
         {
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
         }
         else//directed
         {
            adjList[u].push_back({v,wt});
         }
      }
      void topoSortDFS(int src,unordered_map<int,bool>&vis,stack<int>&ans)
      {
        vis[src] = true;
        for(auto nbr:adjList[src])
        {
            if(!vis[nbr.first])
            {
                topoSortDFS(nbr.first,vis,ans);
            }
        }
        ans.push(src);

      }
      void ShortestPathDFS(int src)
      {
        stack<int>topoOrder;
        unordered_map<int,bool>vis;
        topoSortDFS(src,vis,topoOrder);
        int n = topoOrder.size();
        vector<int>dist(n,INT_MAX);
        src=topoOrder.top();
        topoOrder.pop();
        dist[src] = 0;
        for(auto nbr:adjList[src])
        {
            int node = nbr.first;
            int wtDis = nbr.second;
            if(dist[src]+wtDis < dist[node])
              dist[node] = dist[src] + wtDis;
        }
        while(!topoOrder.empty())
        {
            int frontNode = topoOrder.top();
            topoOrder.pop();
            for(auto nbr: adjList[frontNode])
            {
                int node = nbr.first;
                int wtDis = nbr.second;
                if(dist[frontNode] + wtDis < dist[node])
                   dist[node] = dist[frontNode] + wtDis;
            }
        }
        cout << "Printing Dist array : "<< endl;
        for(auto i:dist)
        {
            cout << i << " ";
        }
        cout << endl;
      }
};
int main()
{
    Graph g;
    g.addEdge(0,1,5,1);
    g.addEdge(0,2,13,1);
    g.addEdge(0,4,3,1);
    g.addEdge(1,4,1,1);
    g.addEdge(1,2,7,1);
    g.addEdge(4,3,6,1);
    g.addEdge(3,2,2,1);
    g.ShortestPathDFS(0);

    return 0;
}