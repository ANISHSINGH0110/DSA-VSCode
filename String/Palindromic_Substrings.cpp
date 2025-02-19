#include <iostream>
#include <string>
using namespace std;

int expandAroundCenter(string s,int i,int j)
    {
        int count = 0;
        while(i>=0 && j < s.length() && s[i] == s[j])
        {
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int totalCount = 0;
        for(int k=0;k<s.length();k++)
        {
            //odd
            int i = k;
            int j = k;
            int oddLengthCount = expandAroundCenter(s,i,j);

            //even
            i = k;
            j = k+1;
            int evenLengthCount = expandAroundCenter(s,i,j);

            totalCount += oddLengthCount + evenLengthCount;
        }
        return totalCount;
    }

int main()
{
    string s;
    cout << "Enter the string " << endl;
    cin >> s;

    int cnt = countSubstrings(s);

    cout << "The number of palindromic substrings : " << cnt << endl;

    return 0;
}