class Solution {
    public:
        string minWindow(string s, string t) {
            int n = s.size();
            if(t.size() > n)
              return "";
            unordered_map<char,int>mp;
            for(char &ch :t)
               mp[ch]++;
            int requiredCnt = t.length();
            int i=0,j=0;
            int minWindowSize = INT_MAX;
            int startI = 0; 
            while(j<n)
            {
                char ch = s[j];
                if(mp[ch] > 0)
                  requiredCnt--;
                mp[ch]--;
                while(requiredCnt == 0)
                {
                    int currWind = j-i+1;
                    if(minWindowSize > currWind)
                    {
                        minWindowSize = currWind;
                        startI = i;
                    } 
                    mp[s[i]]++;
                    if(mp[s[i]] > 0)
                    {
                        requiredCnt++;
                    }
                    i++;
                }   
                j++;
            }    
            return minWindowSize == INT_MAX ? "" : s.substr(startI,minWindowSize);
        }
    };