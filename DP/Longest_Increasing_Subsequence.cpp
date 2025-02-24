#include <iostream>
#include <vector>

using namespace std;
void findSubsequences(vector<int>& nums, vector<int>& temp, int index) {
    if (temp.size() > 1) {  // Print only non-empty subsequences of length > 1
        for (int num : temp) cout << num << " ";
        cout << endl;
    }

    for (int i = index; i < nums.size(); i++) {
        if (temp.empty() || nums[i] > temp.back()) {
            temp.push_back(nums[i]);       // Include the current element
            findSubsequences(nums, temp, i + 1); // Recur for the next elements
            temp.pop_back();               // Backtrack to remove the last element
        }
    }
}

void printAllIncreasingSubsequences(vector<int>& nums) {
    vector<int> temp;  // Temporary vector to store subsequence
    findSubsequences(nums, temp, 0);
}

int main()
{
    int n;
    cout <<"Enter the value of n : " << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the elements of nums : " << endl;
    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
    }
    //cout << "Ans is " << lengthOfLIS(nums) << endl;
    printAllIncreasingSubsequences(nums);

    return 0;
}