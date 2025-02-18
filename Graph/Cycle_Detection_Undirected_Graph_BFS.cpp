#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

unordered_map<int,list<int>>adjList;
class Graph{
    public:
      //unordered_map<int,list<int>>adjList;

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
      bool cycleDetectionUndirectedBFS(int src,unordered_map<int,bool>& visited,unordered_map<int,list<int>>&adj) {
         queue<int> q;
         unordered_map<int,int> parent;
         
         //initial state
         q.push(src);
         visited[src] = true;
         parent[src] = -1;
   
         //main logic
         while(!q.empty()) {
           int frontNode = q.front();
           q.pop();
   
           for(auto nbr: adj[frontNode]) {
             if(!visited[nbr]) {
               q.push(nbr);
               visited[nbr] = true;
               parent[nbr] = frontNode;
             }
             //cycle detection case
             else if(visited[nbr] == true && nbr != parent[frontNode]) {
               //cycle present
               return true;
             } 
           }
         }
         return false;
       }
       bool isCycle(unordered_map<int,list<int>>&adj,int n) {
           bool ans = false;
           unordered_map<int,bool> visited;
           for(int i=0; i<n; i++) {
               if(!visited[i]) {
                  ans = cycleDetectionUndirectedBFS(i,visited,adj);
                 if(ans == true) {
                   break;
                 }
               }
             }
           return ans;
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