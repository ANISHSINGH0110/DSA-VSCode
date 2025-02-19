#include <iostream>
#include <vector>
#include <string>
using namespace std;

int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    //P truck
    int pickP = 0;
    int lastHouseP = 0;
    int travelP = 0;
    //M truck
    int pickM = 0;
    int lastHouseM = 0;
    int travelM = 0;
    //G truck
    int pickG = 0;
    int lastHouseG = 0;
    int travelG = 0;

    for(int i=0;i<garbage.size();i++)
    {
        string curr = garbage[i];
        for(int j=0;j<curr.length();j++)
        {
            char ch = curr[j];
            if(ch == 'P')
            {
                pickP++;
                lastHouseP = i;
            }
            else if(ch == 'M')
            {
                pickM++;
                lastHouseM = i;
            }
            else
            {
                pickG++;
                lastHouseG = i;
            }
        }
    }
    for(int i=0;i<lastHouseP;i++)
    {
        travelP += travel[i];
    }
    for(int i=0;i<lastHouseM;i++)
    {
        travelM += travel[i];
    }
    for(int i=0;i<lastHouseG;i++)
    {
        travelG += travel[i];
    }
    int totalTime = (pickP + travelP) + (pickM + travelM) + (pickG + travelG);
    return totalTime;
}

int main()
{    
    cout << "Enter the size of garbage array " << endl;
    int n,m;
    cin >> n;
    cout << "Enter garbage array values : " << endl;
    vector<string>garbage(n);
    for(int i=0;i<n;i++)
    {
        cin >> garbage[i];
    }
    cout << "Enter the size of travel array " << endl;
    cin >> m;
    vector<int>travel(m);
    for(int i=0;i<m;i++)
    {
        cin >> travel[i];
    }
    int total = garbageCollection(garbage,travel);
    cout << "Total time taken to collect garbage is : " << total << endl;
    

    return 0;
}