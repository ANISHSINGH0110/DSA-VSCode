#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

void createMapping(string& str)
   {
       char start = 'a';
       char mapping[256] = {0};
       for(auto ch:str)
       {
          mapping[ch] = start;
          start++;
       }
       for(int i=0;i<str.length();i++)
       {
          str[i] = mapping[str[i]];
       }
   }


   void normalise(string &str)
   {
    char start = 'a';
    unordered_map<char,char>mapping;
    for(int i=0;i<str.length();i++)
    {
        char stringKaCharacter = str[i];
        if(mapping.find(stringKaCharacter) == mapping.end())
        {
            mapping[stringKaCharacter] = start;
            start++;
        }
    }
    for(int i=0;i<str.length();i++)
    {
        char mappedCharacter = mapping[str[i]];
        str[i] = mappedCharacter;
    }
   }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
       vector<string>ans;
       createMapping(pattern);
       for(auto s:words)
       {
          string tempString = s;
          createMapping(s);
          if(s == pattern)
            ans.push_back(tempString);
       }
       return ans;



    //    vector<string>ans;
    //    normalise(pattern);
    //    for(int i = 0; i<words.size();i++)
    //    {
    //     string currWord = words[i];
    //     string currWordCopy = currWord;
    //     normalise(currWordCopy);
    //     if(currWordCopy == pattern)
    //       ans.push_back(currWord);
    //    }
    //    return ans;

    }

int main()
{   
    string pattern;
    cout << "Enter pattern : " << endl;
    cin >> pattern;
    vector<string>words(6);
    cout << "Enter words : " << endl;
    for(int i=0;i<words.size();i++)
    {
        cin >> words[i];
    }
    vector<string>ans = findAndReplacePattern(words,pattern);
    cout << "Answer is : " << endl;

    for(auto ch:ans)
    {
        cout << ch << endl;
    }
    
    return 0;
}