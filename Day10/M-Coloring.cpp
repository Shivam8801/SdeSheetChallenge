bool isValid(vector<vector<int>> &mat, vector<int> &colour, int c, int node, int sz)
{
    for(int i = 0; i < sz; i++)
    {
        if(i != node && mat[node][i] == 1 && colour[i] == c)
        {
            return false;
        }
    }
    return true;
}

bool solver(vector<vector<int>> &mat, vector<int> &colour, int m, int row, int sz)
{
    if(row == sz) return true;
    for(int c = 1; c <= m; c++)
    {
        if(isValid(mat, colour, c, row, sz))
        {
            colour[row] = c;
            if(solver(mat, colour, m, row + 1, sz)) return true;
            colour[row] = 0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int sz = mat.size();
    vector<int> colour(sz, 0);
    return (solver(mat, colour, m, 0, sz)) ? "YES" : "NO";
}
