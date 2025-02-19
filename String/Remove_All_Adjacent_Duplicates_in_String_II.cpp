#include <iostream>
using namespace std;

bool areLastK_1CharsSame(string& ans,char& currCh,int k_1)
    {
        int it = ans.size()-1;
        for(int i=0;i<k_1;i++)
        {
            if(currCh != ans[it])
              return false;
            it--;  
        }
        return true;
    }
    string removeDuplicates(string s, int k) {
        // //two pointer
        // int i=0,j=0;
        // vector<int>count(s.size());
        // while(j < s.size())
        // {
        //     s[i] = s[j];
        //     count[i] = 1;
        //     if(i>0 && s[i] == s[i-1])
        //       count[i] += count[i-1];
        //     if(count[i] == k)
        //       i -= k;
        //     i++,j++;    
        // }
        // return s.substr(0,i);


        string ans;
        for(int i=0;i<s.size();i++)
        {
            char& newch = s[i];
            if(ans.size() < k-1)
               ans.push_back(newch);
            else
            {
                if(areLastK_1CharsSame(ans,newch,k-1))
                {
                    for(int j=0;j<k-1;++j)
                      ans.pop_back();
                }
                else
                  ans.push_back(newch);
            }   
        }
        return ans;
    }

int main()
{
    string s;
    cout << "Enter the string : " << endl;
    cin >> s;
    int k;
    cout << "Enter the value for k: " << endl;
    cin >> k;

    string st = removeDuplicates(s,k);
    cout << "The string after removing duplicates : " << st << endl;
    return 0;
}