class Solution {
    public:
        void store(int i,int dist , vector<int>&edge,vector<int>&path){
            if(i != -1 && path[i] == -1){
               path[i] = dist;
               store(edge[i],dist+1,edge,path);
            }
        }
        int closestMeetingNode(vector<int>& edges, int node1, int node2) {
            int ans = -1;
            int minDis = INT_MAX;
            int n = edges.size();
            vector<int>path1(n,-1);
            vector<int>path2(n,-1);
            store(node1,0,edges,path1);
            store(node2,0,edges,path2);
    
            for(int i=0;i<n;i++){
                if(min(path1[i],path2[i]) >= 0 && max(path1[i],path2[i]) < minDis){
                    minDis = max(path1[i],path2[i]);
                    ans = i;
                }
            }
            return ans;
        }
    };