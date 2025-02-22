#include <iostream>
#include <vector>
using namespace std;
/*
Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

perm[i] is divisible by i.
i is divisible by perm[i].
Given an integer n, return the number of the beautiful arrangements that you can construct.
*/

void solve(vector<int>&v,int &n,int &ans,int curr)
{
    if(curr >= n+1)
    {
        for(int i=1;i<=n;i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
        ++ans;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(v[i] == 0 && (curr % i == 0 || i % curr == 0))
        {
            v[i] =curr;
            solve(v,n,ans,curr+1);
            //backtrack
            v[i] = 0;
        }
    }
}
int countArrangement(int n) {
    vector<int>v(n+1,0);
    int ans = 0;
    solve(v,n,ans,1);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the Number : " << endl;
    cin >> n;
    int count = countArrangement(n);
    cout << "countArrangement is : " << count << endl;

    return n;
}