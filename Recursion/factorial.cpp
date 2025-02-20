#include <iostream>
using namespace std;

int factorial(int n)
{
    if(n == 0 || n == 1)
      return 1;
    return n*factorial(n-1);  
}

int main()
{
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;

    int fact = factorial(n);

    cout << "The factorial of given number is : " << fact << endl;
    

    return 0;
}