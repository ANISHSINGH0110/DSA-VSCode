#include <iostream>
#include <vector>
using namespace std;

void mergeSortedArray(int arr[],int n,int brr[],int m,vector<int>&ans)
{
    int i=0; //i->arr
    int j=0; //j->brr

    while(i < n && j < m)
    {
        if(arr[i] < brr[j])
        {
            ans.push_back(arr[i]);
            i++;
        }
        else
        {
            ans.push_back(brr[j]);
            j++;
        }
    }
    while(i < n)
    {
        ans.push_back(arr[i]);
        i++;
    }
    while(j < m)
    {
        ans.push_back(brr[j]);
        j++;
    }

}

int main()
{
    int arr[] = {10,30,50,70};
    int brr[] = {20,40,60,80,90,100};
    int sizeArr = 4;
    int sizeBrr = 6;
    vector<int>ans;
    mergeSortedArray(arr,sizeArr,brr,sizeBrr,ans);
    for(auto i:ans)
    {
        cout << i << " " ;
    }
    return 0;
}