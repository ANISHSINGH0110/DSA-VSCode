#include <iostream>
#include <vector>
using namespace std;

bool isSafe(char digit,int row,int col,vector<vector<char>>&board)
{
    int n = board.size();
    for(int k=0;k<n;k++)
    {
        if(board[row][k] == digit)//rowCheck
          return false;
        if(board[k][col] == digit)//col check
          return false; 
        if(board[3*(row/3)+k/3][3*(col/3)+k%3] == digit)//3*3 sub-box check
          return false;   
    }
    return true;
}
bool solve(vector<vector<char>>&board)
{
    //1-case
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
        {
            //sirf empty shell fill krnge
            if(board[i][j] == '.')
            {
                //empty shell pr 1-9 tk digits hit and trial
                for(char digit = '1';digit<='9';digit++)
                {
                    //check and put
                    if(isSafe(digit,i,j,board) == true)
                    {
                        //agar safe hai rkhna
                        board[i][j] = digit;
                        //baki recursion
                        bool aageSolveHoPaya = solve(board);
                        if(aageSolveHoPaya == true)
                        {
                            return true;
                        }
                        else
                        {
                            //aage board solve nhi ho paya
                            //backtrack -> sayad glt digit rkh diya
                            board[i][j] = '.';
                        }
                    }
                }
                return false;//iska mtlb koi digit fit nhi ho rha hai piche kuch glt h
            }
        }
    }
    return true; //board completely fill ho gya
}
int main()
{


    char arr[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
   vector<vector<char>>board(9,vector<char>(9));
   for(int i=0;i<9;i++)
   {
     for(int j=0;j<9;j++)
     {
        board[i][j] = arr[i][j];
     }
   }
   bool ans = solve(board);
   if(ans == 1)
     cout << "Possible " << endl;
   else
     cout << "Not possible" << endl;  
   
    return 0;
}