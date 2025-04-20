class Solution {
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            queue<pair<string,int>>q;
            q.push({beginWord,1});
            unordered_set<string>st(wordList.begin(),wordList.end());
            st.erase(beginWord);
            while(!q.empty())
            {
                pair<string,int>frontPair = q.front();
                q.pop();
                string frontString = frontPair.first;
                int frontDistance = frontPair.second;
                if(frontString == endWord)
                {
                    return frontDistance;
                }
                else
                {
                    for(int index=0;index<frontString.length();index++)
                    {
                        char originalChar = frontString[index];
                        for(char ch='a';ch<='z';ch++)
                        {
                            frontString[index] = ch;
                            if(st.find(frontString) != st.end())
                            {
                                q.push({frontString,frontDistance+1});
                                st.erase(frontString);
                            }
                        }
                        frontString[index] = originalChar;
                    }
                }
            }
            return 0;
        }
    };