bool isSafe(vector<vector<int>> &maze, vector<vector<int>> &visited, int n, int x, int y)
{
    if(x < n && y < n && x >= 0 && y >= 0 && !visited[x][y] && maze[x][y] == 1)
    {
        return true;
    }
    return false;
}

void solver(vector<vector<int>> &maze, vector<vector<int>> &visited, vector<vector<int>> &paths, int n, int x, int y)
{
    if(x == n - 1 && y == n - 1)
    {
        vector<int> temp;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                temp.push_back(visited[i][j]);
            }
        }
        temp.pop_back();
        temp.push_back(1);
        paths.push_back(temp);
        return;
    }
    
    visited[x][y] = 1;
    
    if(isSafe(maze, visited, n, x + 1, y)) 
        solver(maze, visited, paths, n, x + 1, y);
    
    if(isSafe(maze, visited,n, x - 1, y)) 
        solver(maze, visited, paths, n, x - 1, y);
    
    if(isSafe(maze, visited,n, x, y + 1)) 
        solver(maze, visited, paths, n, x, y + 1);
    
    if(isSafe(maze, visited,n, x, y - 1)) 
        solver(maze, visited, paths, n, x, y - 1);
    
    visited[x][y] = 0;

    return;
}


vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n){
    vector<vector<int>> visited(n, vector<int> (n, 0));
    vector<vector<int>> paths;
    if(maze[0][0] == 0) return paths;
    solver(maze, visited, paths, n, 0, 0);
    return paths;
}
