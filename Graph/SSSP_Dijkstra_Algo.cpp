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
        if(direction == 0)//undirected graph
        {
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
        else
        {
            adjList[u].push_back({v,wt});
        }
    }
    void shortestDistanceDijkstra(int src,int n)
    {
        vector<int>dist(n+1,INT_MAX);
        set<pair<int,int>>st;//dist,node
        dist[src] = 0;
        st.insert({0,src});
        while(!st.empty())
        {
            auto topElem = *(st.begin());
            int topNodeDist = topElem.first;
            int topNode = topElem.second;
            st.erase(st.begin());
            for(auto nbr: adjList[topNode])
            {
                int nbrNode = nbr.first;
                int nbrDist = nbr.second;
                if(dist[topNode] + nbrDist < dist[nbrNode])
                {
                    auto result = st.find({dist[nbrNode],nbrNode});
                    if(result != st.end())//found
                      st.erase(result);
                    dist[nbrNode] = dist[topNode]+nbrDist;
                    st.insert({dist[nbrNode],nbrNode});  
                }
            }
        }
        cout << "Printing the Result : " << endl;
        for(int i=0;i<n;i++)
        {
            cout << src <<" -> " << i << " = " << dist[i] << endl;
        }
        cout << endl;
    }
};
int main()
{
    Graph g;
    g.addEdge(0,5,9,0);
    g.addEdge(0,3,6,0);
    g.addEdge(5,4,2,0);
    g.addEdge(5,1,14,0);
    g.addEdge(1,4,9,0);
    g.addEdge(1,2,7,0);
    g.addEdge(2,4,10,0);
    g.addEdge(2,3,15,0);
    g.addEdge(4,3,11,0);
    g.shortestDistanceDijkstra(0,5);

    return 0;
}