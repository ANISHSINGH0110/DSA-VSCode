class Solution {
    public:
        bool checkBounds(vector<vector<int>>&grid,vector<pair<int,int>>&v)
        {
            int m = grid.size();
            int n = grid[0].size();
            for(auto pt:v)
            {
                if(pt.first < 0 || pt.first >= m || pt.second < 0 ||pt.second >= n)
                  return false;
            }
            return true;
        }
        bool getAllVertices(vector<vector<int>>&grid,vector<pair<int,int>>&v,pair<int,int>c,int& delta)
        {
            pair<int,int>A(c.first-delta,c.second);
            pair<int,int>B(c.first,c.second+delta);
            pair<int,int>C(c.first+delta,c.second);
            pair<int,int>D(c.first,c.second-delta);
            v[0] = A;
            v[1] = B;
            v[2] = C;
            v[3] = D;
            if(checkBounds(grid,v))
              return true;
            return false;  
            
        }
        void getAllSum(vector<vector<int>>&grid,int& cx,int& cy,priority_queue<int>&pq)
        {
            pq.push(grid[cx][cy]);
            int delta = 1;
            vector<pair<int,int>>v(4);
            while(getAllVertices(grid,v,{cx,cy},delta))
            {
                pair<int,int>&A = v[0];
                pair<int,int>&B = v[1];
                pair<int,int>&C = v[2];
                pair<int,int>&D = v[3];
                int cSum = grid[A.first][A.second]+grid[B.first][B.second]+grid[C.first][C.second]+grid[D.first][D.second];
                //All cell btw AB
                for(int i=1;i<(B.first-A.first);i++)
                  cSum += grid[A.first+i][A.second+i];
                 //All cell btw BC
                for(int i=1;i<(C.first-B.first);i++)
                  cSum += grid[B.first+i][B.second-i];
                 //All cell btw CD
                for(int i=1;i<(C.first-D.first);i++)
                  cSum += grid[C.first-i][C.second-i];
                 //All cell btw DA
                for(int i=1;i<(D.first-A.first);i++)
                  cSum += grid[D.first-i][D.second+i]; 
                pq.push(cSum);//RH sum has been pushed
                ++delta;       
            }
        }
        bool canPush(vector<int>&ans,int& top)
        {
            for(auto val:ans)
            {
                if(val == top)
                  return false;
            }
            return true;
        }
        vector<int> getBiggestThree(vector<vector<int>>& grid) {
            vector<int>ans;
            priority_queue<int>pq;
            int m = grid.size();
            int n = grid[0].size();
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    getAllSum(grid,i,j,pq);
                }
            }
            while(!pq.empty() && ans.size() < 3)
            {
                int top = pq.top();
                pq.pop();
                if(canPush(ans,top))
                  ans.push_back(top);
            }
            return ans;
        }
    };