bool isSafe(vector<vector<int>> &board, int r, int c, int n)
{
    for(int row = 0; row < r; row++)
    {
        if(board[row][c] == 1)
            return false;
    }
    
    for(int row = r, col = c; row >= 0 && col >= 0; row-- , col--)
    {
        if(board[row][col] == 1) return false;
    }
    
    for(int row = r, col = c; row >= 0 && col < n; row-- , col++)
    {
        if(board[row][col] == 1) return false;
    }
    return true;
}

void solver(vector<vector<int>> &ans, vector<vector<int>> &board, int n, int row)
{
    if(row == n)
    {
        vector<int> temp;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 1)
                    temp.push_back(1);
                else temp.push_back(0);
            }
        }
        ans.push_back(temp);
        return;
    }
    
    for(int col = 0; col < n; col++)
    {
        if(isSafe(board, row, col, n))
        {
            board[row][col] = 1;
            solver(ans, board, n, row + 1);
            board[row][col] = 0;
        }
    }
}
 
vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> ans;
    if(n == 2 || n == 3) return ans;
    vector<vector<int>> board(n, vector<int> (n, 0));
    solver(ans, board, n, 0);
    return ans;
}
