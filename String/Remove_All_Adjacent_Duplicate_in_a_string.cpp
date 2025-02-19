#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

string removeDuplicates(string s) {
    // string ans = "";
    // for(int i=0;i<s.length();i++)
    // {
    //     char currCh = s[i];
    //     if(ans.empty())
    //       ans.push_back(currCh);
    //     else if(currCh == ans.back())
    //        ans.pop_back();
    //     else
    //       ans.push_back(currCh);     
    // }
    // return ans;


    //by using stack

    stack<char>st;
    for(int i=0;i<s.length();i++)
    {
        char currCh = s[i];
        if(!st.empty() && currCh == st.top())
           st.pop();
        else
          st.push(currCh);   
    }
    string ans = "";
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    string s;
    cout << "Enter the string: " << endl;
    cin >> s;
    string ans = removeDuplicates(s);

    cout << "String after Removing all adjacent duplicate is : " << endl;
    cout << ans ; 
    
    
    return 0;
}