#include <bits/stdc++.h>
using namespace std;

int main()
{
    //max heap
    // priority_queue<int>q;
    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);

    //min heap
    priority_queue<int,vector<int>,greater<int>>q;
    q.push(40);
    q.push(30);
    q.push(20);
    q.push(10);
    while(!q.empty())
    {
        cout << q.top() << " ";
        q.pop();

    }
    return 0;

}