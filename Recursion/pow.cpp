#include <iostream>
using namespace std;

int pow(int n)
{
    if(n == 0)
      return 1;
    return 2*pow(n-1);

}

int main()
{

    int n;
    cout << "Enter the number : " << endl;
    cin >> n;
    int p = pow(n);
    cout << "Power of NUmber is : " << p << endl;
    return 0;

}