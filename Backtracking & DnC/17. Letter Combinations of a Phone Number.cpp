#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
void solve(string& digits,vector<string>&ans,unordered_map<char,string>&mp,string output,int i)
{
    if(i >= digits.length())
    {
        if(output.length()>0)
            ans.push_back(output);
        return;  
    }
    //1-case
    char digit = digits[i];
    string mappingString = mp[digit];
    for(char ch:mappingString)
    {
        output.push_back(ch);
        solve(digits,ans,mp,output,i+1);
        //backtrack
        output.pop_back();
    }

}
vector<string> letterCombinations(string digits) {
    vector<string>ans;
    unordered_map<char,string>mp = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},
                                    {'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    int i = 0;
    string output = "";
    solve(digits,ans,mp,output,i);
    return ans;
}

int main()
{
    string digit;
    cout << "Enter digits : " << endl;
    cin >> digit;
    vector<string>ans = letterCombinations(digit);
    for(auto i : ans)
       cout << i << " " << endl;
    int cnt =  (ans.size()%mod);   
    cout << "all possible combination are : " << cnt << endl;
    
    return 0;

}