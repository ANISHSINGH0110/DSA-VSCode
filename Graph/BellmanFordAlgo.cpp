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
        if(direction == 0)//undirected
        {
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
        else //directed
          adjList[u].push_back({v,wt});
    }
    void bellmanFordAlgo(int src,int n)
    {
        vector<int>dist(n,INT_MAX);
        dist[src] = 0;//initial state
        for(int i=0;i<n-1;i++)
        {
            for(auto a:adjList)
            {
                for(auto b:a.second)
                {
                    int u = a.first;
                    int v = b.first;
                    int wt = b.second;
                    if(dist[u] != INT_MAX && dist[u]+wt < dist[v])
                      dist[v] = dist[u]+wt;
                }
            }
        }
        cout << "printing Bellman result : "<< endl;
        for(int i=0;i<n;i++)
        {
            cout << src <<" -> " << i << " = " << dist[i] << endl;
        }
        bool negativeCycle = false;
        for(auto a:adjList)
        {
            for(auto b:a.second)
            {
                int u = a.first;
                int v = b.first;
                int wt = b.second;
                if(dist[u] != INT_MAX && dist[u]+wt < dist[v]){
                    dist[v] = dist[u]+wt;
                    negativeCycle = true;
                }
            }
        }
        if(negativeCycle == true)
          cout << "-ve cycle present " << endl;
        else
           cout << "-ve cycle not present " << endl;  

    }
};
int main()
{
    Graph g;
    g.addEdge(0,1,-1,1);
    g.addEdge(0,2,4,1);
    g.addEdge(1,2,3,1);
    g.addEdge(1,3,2,1);
    g.addEdge(1,4,2,1);
    g.addEdge(4,3,-3,1);
    g.addEdge(3,1,1,1);
    g.bellmanFordAlgo(0,5);    
    return 0;
}