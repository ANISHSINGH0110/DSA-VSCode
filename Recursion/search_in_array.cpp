#include <iostream>
using namespace std;

void printArray(int arr[],int size,int i)
{
    if(i == size)
      return;
    cout << arr[i] << " ";
    printArray(arr,size,i+1);  
}
bool searchInArray(int arr[],int size,int i,int target)
{
    if(i == size)
      return false;
    if(arr[i] == target)
      return true;
    return searchInArray(arr,size,i+1,target);    
}

int main()
{
    int n;
    cout << "Enter the size of array : " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the element of array : " << endl;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    printArray(arr,n,0);
    cout << endl;
    
    int target;
    cout << "Enter the target element : " << endl;
    cin >> target;
    bool ans = searchInArray(arr,n,0,target);
    if(ans == 1)
      cout << "Element is present in array " << endl;
    else 
      cout << "Element is not present in array " << endl;  

    return 0;
}