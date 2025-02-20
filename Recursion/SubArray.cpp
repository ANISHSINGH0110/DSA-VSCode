#include <iostream>
#include <vector>
using namespace std;

void printSubArrayUtil(vector<int>&nums,int start,int end)
{
    if(end == nums.size())
      return;
    for(int i=start;i<=end;i++)
    {
        cout << nums[i] << " ";
    }  
    cout << endl;
    printSubArrayUtil(nums,start,end+1);
}

void printSubarray(vector<int>&arr)
{
  for(int s=0;s<arr.size();s++)
  {
    int end = s;
    printSubArrayUtil(arr,s,end);
  }
}

int main()
{
    int n;
    cout << "enter the number of element in array : " << endl;
    cin >> n;
    vector<int>arr(n);
    cout << "Enter elements of array : " << endl;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    cout << "printing subarray : " << endl;
    printSubarray(arr);

    return 0;
}