#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
 
class Graph{
    public:
     unordered_map<int,list<pair<int,int>>>adjList;

     void addEdge(int u,int v,int weight,bool direction)
     {
        if(direction == 0) //undirected graph
        {
            adjList[u].push_back({v,weight});
            adjList[v].push_back({u,weight});
        }
        else //directed graph
        {
            adjList[u].push_back({v,weight});
        }
     }

     void printAdjList(int n)
     {
        for(int i=0;i<=n;i++)
        {
            cout << i << " : ";
            cout << "{";
            list<pair<int,int>>temp = adjList[i];
            for(auto j : temp)
            {
                cout << "(" << j.first << "," << j.second << "),";

            }
            cout << "}" << endl;
        }
     }
};

int main()
{
    Graph g;
    g.addEdge(0,1,5,1);
    g.addEdge(0,3,3,1);
    g.addEdge(1,3,7,1);
    g.addEdge(1,2,8,1);
    g.addEdge(3,2,6,1);
    g.addEdge(2,4,9,1);
    // g.addEdge(0,1,5,1);
    // g.addEdge(0,1,5,1);
    g.printAdjList(4);
    return 0;
}