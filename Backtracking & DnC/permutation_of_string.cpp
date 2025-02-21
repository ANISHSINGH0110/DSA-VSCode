#include <iostream>
#include <string>
using namespace std;

void printPermutation(string str,int i)
{
    if(i >= str.length())//base case
    {
        cout << str << endl;
        return;
    }
    //ith wale dbe pe sbko mauka dunga
    for(int j=i;j<str.length();j++)
    {
        swap(str[i],str[j]);//chance dene k liye swap kiya tha 
        printPermutation(str,i+1);//baki recursion
        //backtrack
        swap(str[i],str[j]);
    }
}

int main()
{
    string str = "abc";
    int i=0;
    printPermutation(str,i);
    return 0;
}