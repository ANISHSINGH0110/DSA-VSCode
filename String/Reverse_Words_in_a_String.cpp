#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseWords(string s) {
    reverse(s.begin(),s.end());
    int n = s.size();
    int start = 0,end = 0;
    for(int i=0;i<n;i++)
    {
        //skip leading spaces
        while(i<n && s[i] == ' ')
          i++;
        //out of bond check  
        if(i == n)
          break;
        //copy char to right position
        while(i < n && s[i] != ' ')
           s[end++] = s[i++];
        //after copying reverse the individual word
        reverse(s.begin()+start,s.begin()+end);
        //add extra space btw word
        s[end++] = ' ';
        start = end;     

    }
    //resize the final string
    s.resize(end-1);
    return s;
}

int main()
{
    string s;
    cout << "Enter the string : " << endl;
    getline(cin,s);
    string ans = reverseWords(s);
    cout << "String after reverse is : " << ans << endl;
    
    return 0;
}