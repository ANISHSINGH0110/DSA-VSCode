#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
       unordered_map<int,list<int>>adjList;
       void addEdge(int u,int v)
       {
          adjList[u].push_back(v);
       }
       void topoSortDFS(stack<int>&s,int node,unordered_map<int,bool>&vis)
       {
          vis[node] = true;
          for(auto nbr:adjList[node])
          {
            if(!vis[nbr])
              topoSortDFS(s,nbr,vis);
          }
          s.push(node);
       }
       void dfs(int src,unordered_map<int,bool>&vis,unordered_map<int,list<int>>&adjNew)
       {
         vis[src] = true;
         cout << src << " ";
         for(auto nbr:adjNew[src])
         {
            if(!vis[nbr])
              dfs(nbr,vis,adjNew);
         }
       }
       void stronglyComp(int n)
       {
          stack<int>s;
          unordered_map<int,bool>vis;
          for(int i=0;i<n;i++)
          {
            if(!vis[i])
              topoSortDFS(s,i,vis);
          }
          //yaha pr stack mai topo ordering ready hai
          //step-2 : reverse all edge
          unordered_map<int,list<int>>adjNew;
          for(auto i:adjList)
          {
             for(auto j:i.second)
             {
                int u = i.first;
                int v = j;
                adjNew[v].push_back(u);
             }
          }
          int count = 0;
          unordered_map<int,bool>visited;
          while(!s.empty())
          {
            int src = s.top();
            s.pop();
            if(!visited[src])
            {
                cout << "scc: ";
                dfs(src,visited,adjNew);
                cout << endl;
                count++;
            }
          }
          cout << "No of SCC are : " << count << endl;

       }
};

int main()
{
    int n;
    cout << "Enter the number of nodes : " << endl;
    cin >> n;
    Graph g;
    cout << "Enter the edge from a to b : " << endl;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin >> a >> b;
        g.addEdge(a,b);
    }
    g.stronglyComp(n);

    return 0;
}
