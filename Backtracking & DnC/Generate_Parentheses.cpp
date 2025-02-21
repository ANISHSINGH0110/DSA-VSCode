#include <iostream>
#include <vector>
using namespace std;

void solve(int n,vector<string>&ans,string output,int open,int close)
    {
        if(open+close == 2*n)
        {
            ans.push_back(output);
            return;
        }
        if(open < n)
        {
            solve(n,ans,output+"(",open+1,close);
        }
        if(close < open)
        {
            solve(n,ans,output+")",open,close+1);
        }
    }
vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(n,ans,"",0,0);
        return ans;
 }

int main()
{
    int n;
    cout << "Enter the Number : " << endl;
    cin >> n;
    vector<string>ans = generateParenthesis(n);
    for(auto i:ans)
    {
        cout << i << endl;
    }

    return 0;
}