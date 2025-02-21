#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int,bool>rowCheck;
unordered_map<int,bool>lowerDiagonalCheck;
unordered_map<int,bool>upperDiagonalCheck;
void storeSolution(vector<vector<string>>&ans,vector<vector<char>>&board,int n)
{
        vector<string>tempAns;
        for(int i=0;i<n;i++)
        {
            string output = "";
            for(int j=0;j<n;j++)
            {
                output.push_back(board[i][j]);
            }
            tempAns.push_back(output);
        }
        ans.push_back(tempAns);
    }
    bool isSafe(int row,int col,vector<vector<char>>&board)
    {
        //check for rowCheck
        if(rowCheck[row] == true)
          return false;
        //check for upperDiagonal
        if(upperDiagonalCheck[row-col] == true)
          return false;
        //lowerDiagonal Check
        if(lowerDiagonalCheck[row+col] == true)
          return false;
        return true;      
    }
    void solve(int n,vector<vector<char>>&board,vector<vector<string>>&ans,int col)
    {
        if(col >= n)
        {
            storeSolution(ans,board,n);
            return;
        }
        for(int row = 0;row<n;row++)
        {
            if(isSafe(row,col,board))
            {
                board[row][col] = 'Q';
                rowCheck[row] = true;
                lowerDiagonalCheck[row+col] = true;
                upperDiagonalCheck[row-col] = true;
                //recu
                solve(n,board,ans,col+1);
                //backtrack
                board[row][col] = '.';
                rowCheck[row] = false;
                lowerDiagonalCheck[row+col] = false;
                upperDiagonalCheck[row-col] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        //create board
        vector<vector<char>>board(n,vector<char>(n,'.'));
        //start placing queen with 0th column
        int col = 0;
        rowCheck.clear();
        lowerDiagonalCheck.clear();
        upperDiagonalCheck.clear();
        solve(n,board,ans,col);
        return ans;
    }

int main()
{
    int n;
    cout << "Enter the value of n : " << endl;
    cin >> n;
    vector<vector<string>>ans = solveNQueens(n);
    for(int i=0;i<ans.size();i++)
    {
        cout <<"Solution " << i+1 << endl;
        for(int j=0;j<ans[i].size();j++)
        {
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}