#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<int,list<int>>adjList;
class Graph{
    public :
      void addEdge(int u,int v,bool direction)
      {
        if(direction == 0) //undirected graph
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        else //directed graph
        {
            adjList[u].push_back(v);
        }
      }
      void printAdjList(int n)
      {
        for(int i=0;i<=n;i++)
        {
            cout << i << " : " ;
            cout << "{";
            list<int>temp = adjList[i];
            for(auto j : temp)
            {
                cout << j << "," ;
            }
            cout << "}" << endl;
        }
      }
    void topoDFS(int src,unordered_map<int,bool>&visited,unordered_map<int,list<int>>adj,vector<int>&ans)
    {
        visited[src] = true;
        for(auto nbr:adj[src])
        {
            if(!visited[nbr])
              topoDFS(nbr,visited,adj,ans);
        }
        ans.push_back(src);
    }
    void topologicalSort(unordered_map<int,list<int>>adj,int n, vector<int>&ans) {
        unordered_map<int,bool>visited;
        for(int i=0;i<=n;i++)
        {
            if(!visited[i])
              topoDFS(i,visited,adj,ans);
        }
        reverse(ans.begin(),ans.end());
        //return ans;
    }
};
int main()
{   
    Graph g;
    g.addEdge(1,0,1);
    g.addEdge(2,0,1);
    g.addEdge(3,0,1);
    g.printAdjList(3);
    vector<int>ans;
    g.topologicalSort(adjList,3,ans);
    cout << "printing topological sort" << endl;
    for(int i=0;i<4;i++)
    {
        cout << ans[i] << ",";
    }

    return 0;
}