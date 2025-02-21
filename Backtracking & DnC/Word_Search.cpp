#include <iostream>
#include <vector>
using namespace std;

bool solve(vector<vector<char>>&board,string word,int row,int col,int i)
{
    if(i == word.size())
      return true;
    if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()
        ||board[row][col] != word[i] || board[row][col] == '%')  
    {
        return false;
    }  
    char temp = board[row][col];
    board[row][col] = '%';//visited
    bool found = solve(board,word,row-1,col,i+1)//up
                 || solve(board,word,row+1,col,i+1)//down
                 || solve(board,word,row,col-1,i+1)//left
                 || solve(board,word,row,col+1,i+1);//right
    //unvisited
    board[row][col] = temp;
    return found;             
}
bool exist(vector<vector<char>>& board, string word) {
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size();j++)
        {
            if(solve(board,word,i,j,0))
              return true;
        }
    }
    return false;
}

int main()
{
    char arr[3][4] = {{'A','B','C','E'},
                    {'S','F','C','S'},
                    {'A','D','E','E'}};
    vector<vector<char>>board(3,vector<char>(4));
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            board[i][j] = arr[i][j];
        }
    } 
    string word = "ABCCED";
    bool ans = exist(board,word);
    if(ans == 1)
      cout << "Word is present " << endl;
    else
      cout << "Word is not present " << endl;       

    return 0;
}