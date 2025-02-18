#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;
unordered_map<int,list<int>>adjList;
class Graph{
    public:
    //   unordered_map<int,list<int>>adjList;

      void addEdge(int u,int v, bool direction)
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
            cout << i << " : ";
            cout << "{" ;
            list<int> temp = adjList[i];
            for(auto j:temp)
            {
               cout << j << ",";
            }
            cout << "}" << endl;
         }
      }
      bool checkCycleDFS(int src,unordered_map<int,bool>&vis,unordered_map<int,list<int>>&adj,int parent)
      {
          vis[src] = true;
          for(auto nbr : adj[src])
          {
              if(!vis[nbr])
              {
                  bool ans = checkCycleDFS(nbr,vis,adj,src);
                  if(ans == true)
                    return true;
                  
              }
              else if(vis[nbr] == true && nbr != parent)
                  return true;
             
          }
          return false;
      }
      bool isCycle(unordered_map<int,list<int>>& adj ,int n) {
          //int n = adj.size();
          bool ans = false;
          unordered_map<int,bool>visited;
          int parent = -1;
          for(int i=0;i<n;i++)
          {
              if(!visited[i])
              {
                  ans = checkCycleDFS(i,visited,adj,parent);
                  if(ans)
                    return true;
              }
          }
          return false;
      }

};

int main()
{
    Graph g;
    //undirected graph creation 
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,4,0);
    g.addEdge(2,3,0);
    g.addEdge(3,4,0);
    //print AdjList
    g.printAdjList(4);
    
    bool ans = g.isCycle(adjList,4);
    if(ans == 1)
      cout << "Cycle is Detected" << endl;
    else
      cout << "Cycle is not Present" << endl;  

    return 0;
}