#include <iostream>
using namespace std;

int countInversion(int arr[],int n)
{
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        for(int j =i+1;j<n;j++)
        {
            if(arr[i] > arr[j])
              cnt++;
        }
    }
    return cnt;
}
int main()
{
    int arr[] = {8,4,2,1};
    cout << "Total Inversion in Array is : " << countInversion(arr,4) << endl;

    return 0;
}