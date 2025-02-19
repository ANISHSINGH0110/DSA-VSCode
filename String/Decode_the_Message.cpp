#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string decodeMessage(string key, string message) {

    unordered_map<char,char>mapping;
    char space = ' ';
    mapping[space] = space;
    char start = 'a';
    int index = 0;

    while(start <= 'z'  &&  index < key.length())
    {
        char keyKaCurrentCharacter = key[index];
        if(mapping.find(keyKaCurrentCharacter) != mapping.end())
          index++;  //agr character ki mapping already hai move to next character
        
        else   //alreardy nhii hai create mapping and move ahead
        {
            mapping[keyKaCurrentCharacter] = start;
            start++;
            index++;
        }    
    }
    //step-2 use mapping and decode message
    string ans = "";
    for(int i=0;i<message.length();i++)
    {
        char msgCharacter = message[i];
        char mappedCharacter = mapping[msgCharacter];
        ans.push_back(mappedCharacter);
    }
    return ans;
    

    // char start = 'a';
    // //create mapping 
    // char mapping[280] = {0};
    // for(char ch:key)
    // {
    //     if(ch != ' ' && mapping[ch] == 0)
    //     {
    //         mapping[ch] = start;
    //         start++;
    //     }
    // }
    // string ans = "";
    // //Decode message
    // for(char ch:message)
    // {
    //     if(ch == ' ')
    //       ans.push_back(' ');
    //     else
    //       ans.push_back(mapping[ch]);  
    // }
    // return ans;
}

int main()
{   
    string key,message;
    cout << "Enter the key : " << endl;
    getline(cin, key); 
    cout << "Enter the message : " << endl;
    getline(cin, message); 
    string decMessage = decodeMessage(key,message);
    cout << "The decoded Message is : " << decMessage << endl;

    return 0;
}