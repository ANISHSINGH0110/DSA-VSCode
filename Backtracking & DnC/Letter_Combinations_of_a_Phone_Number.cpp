#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve(string& digits,vector<string>&ans,unordered_map<char,string>&mp,string output,int i)
{
    if(i >= digits.length())
    {
        if(output.length() > 0)
          ans.push_back(output);
        return;  
    }
    char digit = digits[i];
    string mappingString = mp[digit];
    for(char ch : mappingString)
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
    string digits;
    cout << "Enter the digits : " << endl;
    cin >> digits;
    vector<string>ans = letterCombinations(digits);
    for(auto i:ans)
    {
        cout << i << " ";
    }

    return 0;
}