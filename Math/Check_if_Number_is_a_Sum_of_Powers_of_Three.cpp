#include<iostream>
using namespace std;
bool checkPowersOfThree(int n) {
    while (n > 0) {
       int rem = n % 3;
       if (rem >= 2) {
           return false;
       }
       n = n / 3;
   }
   return true;
   }
int main()
{
    int n;
    cout << "enter value of n : " << endl;
    cin >> n;
    bool ans = checkPowersOfThree(n);
    if(ans == true)
      cout << "It is possible to represent " << n << " as the sum of distinct powers of three " << endl;
    else
      cout << "It is not possible to represent " << n << " as the sum of distinct powers of three : " << endl;  


}