#include <iostream>
#include <string>
using namespace std;

bool palindromeCheck(string &str,int s,int e)
{
    if(s >= e)
      return true;
    if(str[s] != str[e])
      return false;
    palindromeCheck(str,s+1,e-1);    
}

int main()
{
    string s;
    cout << "Enter the string : " << endl;
    cin >> s;
    bool ans = palindromeCheck(s,0,s.length()-1);
    if(ans == 1)
      cout << "Palindromic string " << endl;
    else
      cout << "Not a palindromic string " << endl;  

    return 0;
}