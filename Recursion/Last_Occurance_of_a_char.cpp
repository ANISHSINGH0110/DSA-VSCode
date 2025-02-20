#include <iostream>
#include <string>
using namespace std;

void lastOccLTR(string &str,char x,int i,int &ans)
{
    if(i>=str.size())
      return;
    if(str[i] == x)
      ans = i;
    lastOccLTR(str,x,i+1,ans);    
}

int main()
{

    string s;
    cout <<"Enter the string : " << endl;
    cin >> s;
    int ans = -1;
    char ch;
    cout << "Enter the char to find last occurance : "  << endl;
    cin >> ch;
    lastOccLTR(s,ch,0,ans);

    cout << "Last occurance of " << ch << "is : " << ans << endl;

    return 0;
}