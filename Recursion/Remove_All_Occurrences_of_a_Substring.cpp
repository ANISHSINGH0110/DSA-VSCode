#include <iostream>
#include <algorithm>
using namespace std;

void removeOcc(string& s, string &part)
{
    int found = s.find(part);
    if(found != string :: npos)
    {
        string left = s.substr(0,found);
        string right = s.substr(found+part.length(),s.size());
        s = left + right;
        removeOcc(s,part);
    }
    else
      return;
}

int main()
{
    string str,part;
    cout << "Enter the string : " << endl;
    cin >> str;
    cout << "Enter the part : " << endl;
    cin >> part;
    removeOcc(str,part);
    cout << "string after removing part is : " << str << endl;

    return 0;
}