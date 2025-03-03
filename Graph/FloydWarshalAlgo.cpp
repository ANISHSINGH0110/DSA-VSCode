#include<iostream>
#include<unordered_map>
#include <vector>
#include<list>
#include<algorithm>
#include<limits.h>
#include<set>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<pair<int,int>>>adjList;
    void addEdge(int u,int v,int wt,bool direction)
    {
        if(direction == 0) //undirected 
        {
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
        else//directed
        {
            adjList[u].push_back({v,wt});
        }
    }
    void floydWarshalAlgo(int n)
    {
      vector<vector<int>>dist(n,vector<int>(n,1e9));
      for(int i=0;i<n;i++)//diagonal pe zero rkh do
         dist[i][i] = 0;
       //copy all dist from graph to matrix  
       for(auto a:adjList)
       {
          for(auto b: a.second)
          {
             int u = a.first;
             int v = b.first;
             int wt = b.second;
             dist[u][v] = wt;
          }
       } 
       //main logic
       for(int helper =0;helper<n;helper++)
       {
          for(int u=0;u<n;u++)
          {
            for(int v=0;v<n;v++)
            {
                dist[u][v] = min(dist[u][v],dist[u][helper]+dist[helper][v]);
            }
          }
       } 
       cout << "Printing result of floyd warshall : "<< endl;
       for(int i=0;i<n;i++)
       {
          for(int j=0;j<n;j++)
          {
            cout << dist[i][j] << ",";
          }
          cout << endl;
       }
    }
};
int main()
{
    Graph g;
    g.addEdge(0,2,-2,1);
    g.addEdge(1,0,4,1);
    g.addEdge(2,3,2,1);
    g.addEdge(3,1,-1,1);
    g.addEdge(1,2,3,1);
    g.floydWarshalAlgo(4);
    return 0;
}