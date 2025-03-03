#include<iostream>
#include<unordered_map>
#include <vector>
#include<list>
#include<algorithm>
#include<queue>
using namespace std;
class Graph{
    public:
      unordered_map<int,list<int>>adjList;
      void addEdge(int u,int v,bool direction)
      {
        if(direction == 0)//undirected graph
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        else
          adjList[u].push_back(v);
      }
      void shortestPathBFS(int src,int dest)
      {
         unordered_map<int,bool>vis;
         unordered_map<int,int>parent;
         queue<int>q;
         q.push(src);
         vis[src] = true;
         parent[src] = -1;
         while(!q.empty())
         {
            int frontNode = q.front();
            q.pop();
            for(auto nbr:adjList[frontNode])
            {
                if(!vis[nbr])
                {
                    q.push(nbr);
                    vis[nbr] = true;
                    parent[nbr] = frontNode;
                }
            }
         }
         vector<int>path;
         int node = dest;
         while(node != -1)
         {
            path.push_back(node);
            node = parent[node];
         }
         reverse(path.begin(),path.end());
         for(auto i:path)
         {
            cout << i << "->";
         }
         cout << endl;
      }

};
int main()
{

    Graph g;
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(2,3,0);
    // g.addEdge(3,5,0);
    // g.addEdge(3,4,0);
    // g.addEdge(4,6,0);

    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    g.addEdge(0,4,1);
    g.addEdge(1,4,1);
    g.addEdge(1,2,1);
    g.addEdge(4,3,1);
    g.addEdge(3,2,1);
    int src,dest;
    cout << "Enter the source : "<< endl;
    cin >> src;
    cout << "Enter the dest : " << endl;
    cin >> dest;

    g.shortestPathBFS(src,dest);
    return 0;
}