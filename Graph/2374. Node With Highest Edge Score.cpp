class Solution {
    public:
        int edgeScore(vector<int>& edges) {
            int n = edges.size();
            vector<long long>edgeScore(n,0);
            for(int i=0;i<n;i++){
                edgeScore[edges[i]] += i;
            }
    
            int idx = 0;
            long long score = edgeScore[0];
    
            for(int i=0;i<n;i++){
                if(edgeScore[i] > score){
                    score = edgeScore[i];
                    idx = i;
                }
            }
            return idx;
    
        }
    }; 