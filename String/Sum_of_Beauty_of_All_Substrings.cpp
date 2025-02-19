#include <iostream>
#include <limits.h>
#include <unordered_map>
#include <algorithm>
using namespace std;

int beautySum(string s) {
    //by using unordered map

    // int beautySumT = 0;
    // unordered_map<char,int>mp;
    // for(int i=0;i<s.length();i++)
    // {
    //     mp.clear();
    //     for(int j=i;j<s.length();j++)
    //     {
    //         char &ch = s[j];
    //         mp[ch]++;//update in map

    //         int maxi = INT_MIN;
    //         int mini = INT_MAX;
            
    //         //itearte over map and update maxi and mini
    //         for(auto &each:mp)
    //         {
    //             maxi = max(maxi,each.second);
    //             mini = min(mini,each.second);
    //         }
    //         int beauty = maxi-mini;
    //         beautySumT += beauty;
    //     }
    // }
    // return beautySumT;


    //method -2 without map
    
    int beautySumT = 0;

    for(int i=0;i<s.length();i++)
    {
        int mp[256] = {0};
        for(int j=i;j<s.length();j++)
        {
            char &ch = s[j];
            mp[ch]++;//update in map

            int maxi = INT_MIN;
            int mini = INT_MAX;
            
            //itearte over map and update maxi and mini
            for(char ch='a';ch<='z';ch++)
            {
                if(mp[ch] > 0){
                    maxi = max(maxi,mp[ch]);
                    mini = min(mini,mp[ch]);
                }
            }
            int beauty = maxi-mini;
            beautySumT += beauty;
        }
    }
    return beautySumT;
}

int main()
{
    string s;
    cout << "Enter the string : " << endl;
    cin >> s;
    int beauty = beautySum(s);
    cout << "The beauty Sum of all substring is : " << beauty << endl;

    return 0;
}