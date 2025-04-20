class Solution {
    public:
        int minimumEffortPath(vector<vector<int>>& heights) {
            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; //min heap
    
            int row = heights.size();
            int col = heights[0].size();
            vector<vector<int>>dist(row,vector<int>(col,INT_MAX));
            pq.push({0,{0,0}});
            dist[0][0] = 0; //dijestra logic
    
            while(!pq.empty())
            {
                pair<int,pair<int,int>>frontNode = pq.top();
                pq.pop();
                int currAbsDiff = frontNode.first;
                int x = frontNode.second.first;
                int y = frontNode.second.second;
                if(x == row-1 && y == col-1)
                  return dist[x][y];
                else // then do up,down,left,right movement
                {
                    int dx[] = {0,-1,0,1};
                    int dy[] = {-1,0,1,0};
                    for(int i=0;i<4;i++)
                    {
                        int newX = x+dx[i];
                        int newY = y+dy[i];
                        if(newX >= 0 && newY >= 0 && newX < row && newY < col)//if new coordinate are safe
                        {
                            int newAbsDiff = abs(heights[x][y]-heights[newX][newY]);
                            int newMaxDiff = max(currAbsDiff,newAbsDiff);
                            if(newMaxDiff < dist[newX][newY])
                            {
                                dist[newX][newY] = newMaxDiff;
                                pq.push({newMaxDiff,{newX,newY}});
                            }
                        }
                    }
                }  
            }
            return 0;
        }
    };