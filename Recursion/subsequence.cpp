#include <iostream>
#include <string>
using namespace std;

void printSubsequence(string str,int i,string output)
{
    if(i == str.length())
    {
        cout << output << endl;
        return;
    }
    //1-case mera
    char ch = str[i];
    //include ch
    printSubsequence(str,i+1,output+ch);
    //exclude
    printSubsequence(str,i+1,output);

}

int main()
{
    string s;
    cout << "Enter the string " << endl;
    cin >> s;
    string output = "";
    printSubsequence(s,0,output);

    return 0;
}