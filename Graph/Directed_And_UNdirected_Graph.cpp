#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph{
    public:
      unordered_map<int,list<int>>adjList;

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

};

int main()
{
    Graph g;
    // //directed graph  creation
    // g.addEdge(0,1,1);
    // g.addEdge(0,2,1);
    // g.addEdge(1,5,1);
    // g.addEdge(2,3,1);
    // g.addEdge(5,4,1);
    // g.addEdge(3,4,1);
    // g.addEdge(4,6,1);
    // g.addEdge(4,8,1);
    // g.addEdge(8,7,1);
    // //print adjList of directed graph
    // g.printAdjList(8);

    //undirected graph creation 
    g.addEdge(0,1,0);
    g.addEdge(0,2,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(2,4,0);
    g.addEdge(3,4,0);
    g.addEdge(4,5,0);
    g.addEdge(3,5,0);
   //print adjList
   g.printAdjList(5);
    return 0;
}