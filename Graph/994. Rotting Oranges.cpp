class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
          int rows = grid.size(),cols = grid[0].size();
          queue<pair<int,int>>q;
          int freshOranges = 0;
    
          //1 all the rotten oranges to the queue
          for(int i=0;i<rows;i++)
          {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j] == 2)
                  q.push({i,j});
                else if(grid[i][j] == 1)
                  freshOranges++;  
            }
          }  
    
          if(!freshOranges)
             return 0;
          int minutes = 0;
          vector<pair<int,int>>directions = {{0,1},{1,0},{0,-1},{-1,0}};
          //perform bfs
          while(!q.empty())
          {
                int size = q.size();
                bool hasRottenNew  = false;
                for(int i=0;i<size;i++)
                {
                    auto curr = q.front();
                    q.pop();
                    for(auto dir: directions)
                    {
                        int newRow = curr.first+dir.first;
                        int newCol = curr.second+dir.second;
                        if(newRow>=0 && newRow < rows //if adj cell is a fresh
                            && newCol >=0 && newCol <cols
                            && grid[newRow][newCol] == 1)
                        {
                            grid[newRow][newCol] = 2;
                            freshOranges--;
                            q.push({newRow,newCol});//for next level
                            hasRottenNew = true;
                        }    
                    }
                }
                if(hasRottenNew)
                  minutes++; 
          }  
           if(freshOranges > 0)
             return -1;
           return minutes;  
    
        }
    };