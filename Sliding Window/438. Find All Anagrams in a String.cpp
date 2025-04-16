class Solution {
    public:
         bool allZeroes(vector<int>&cnt)
        {
            for(auto i:cnt)
            {
                if(i != 0)
                  return false;
            }
            return true;
        }
        vector<int> findAnagrams(string txt, string pat) {
             int n = txt.size();
            vector<int>cnt(26,0);
            //cnt freq of each ch in pat
            for(int i=0;i<pat.size();i++)
            {
                char ch = pat[i];
                cnt[ch-'a']++;
            }
            int i=0;
            int j=0;
            vector<int>ans;
            int k=pat.size();
            while(j<n)
            {
                cnt[txt[j]-'a']--;
                if(j-i+1 == k)
                {
                    if(allZeroes(cnt))
                      ans.push_back(i);
                    cnt[txt[i]-'a']++;
                    i++;
                }
               j++;
            }
            return ans;
        }
    };