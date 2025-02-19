#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string removeOccurrences(string s, string part) {
    while(s.find(part) != string ::npos)
    {
        s.erase(s.find(part),part.length());
    }
    return s;
}
int main()
{   
    string s,part;

    cout << "Enter the string: " << endl;
    cin >> s;
    cout << "Enter the part : " << endl;
    cin >> part;
    string ans = removeOccurrences(s,part);
    cout << "String after removing all occurance of substring is : " << ans << endl;
    
    return 0;
}