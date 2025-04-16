#include <bits/stdc++.h>
using namespace std;
class Info{
    public:
      int data;
      int rIndex;
      int cIndex;
      Info(int x,int y,int z)
      {
          data = x;
          rIndex = y;
          cIndex = z;
      }
};
class compare{
  public:
    bool operator()(Info* a,Info* b)
    {
        return a->data > b->data;
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        priority_queue<Info*,vector<Info*>,compare>pq;
        vector<int>ans;
        int totalRows = arr.size();
        int totalCols = arr[0].size();
        //process first k element
        for(int row=0;row<totalRows;row++)
        {
            int element = arr[row][0];
            Info* temp = new Info(element,row,0);
            pq.push(temp);
        }
        while(!pq.empty())
        {
            Info* front = pq.top();
            pq.pop();
            int frontData = front->data;
            int front_rInd = front->rIndex;
            int front_cInd = front->cIndex;
            ans.push_back(frontData);
            if(front_cInd+1 < totalCols)
            {
                int element = arr[front_rInd][front_cInd+1];
                Info* temp = new Info(element,front_rInd,front_cInd+1);
                pq.push(temp);
            }
            
        }
        return ans;
    }
};
