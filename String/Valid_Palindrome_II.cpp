//Given a string s, return true if the s can be palindrome after deleting at most one character from it.

#include <iostream>
#include <string>
using namespace std;
bool checkPalindrome(string s,int i,int j)
{
    while(i<=j)
    {
        if(s[i] != s[j])
          return false;
        else
        {
            i++;
            j--;
        }  
       
    }
    return true;
}
bool validPalindrome(string s) {
    int n = s.length();
    int i = 0;
    int j = n-1;
    while(i <= j)
    {
        if(s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {  //delete ith ch wala element
            bool  ansOne = checkPalindrome(s,i+1,j);
            //delete jth ch wala element
            bool ansTwo = checkPalindrome(s,i,j-1);
            return ansOne || ansTwo;
        }
    }
    return true;
}
int main()
{
    string s;
    cout << "Enter the string : " << endl;
    cin >> s;
    bool ans = validPalindrome(s);
    if(ans == 1)
      cout << "String is Palindromic " << endl;
    else
      cout << "String is not Palindromic " << endl;
       
    return 0;
}