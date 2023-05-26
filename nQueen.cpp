#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool safe(int row,int col,vector<string> &board,int n)
    {
        int r=row;
        int c=col;

        while(r>=0 && c>=0)
        {
            if(board[r][c]=='Q') return false;
            r--;
            c--;
        }
        
        r=row;
        c=col;
        while(c>=0)
        {
            if(board[r][c]=='Q') return false;
            c--;
        }
        r=row;
        c=col;

        while(r<n && c>=0)
        {
            if(board[r][c]=='Q') return false;
            r++;
            c--;
        }
        return true;
    }

    void solve(int col,vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(safe(row,col,board,n))
            {
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        solve(0,board,ans,n);
        return ans;
    }
};

int main()
{
    int n; // we are taking 4*4 grid and 4 queens
    cout << "Enter the Number of Queens - ";
    cin >> n;
    Solution obj;
    vector<vector<string>> ans = obj.solveNQueens(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Arrangement " << i + 1 << "\n";
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j];
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}