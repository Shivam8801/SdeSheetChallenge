bool isValid(int matrix[9][9], int r, int c, int k)
{
     for(int i = 0; i < 9; i++)
     {
         if(matrix[r][i] == k)
             return false;

         if(matrix[i][c] == k)
             return false;

         if(matrix[3 * (r/3) + i/3][3 * (c/3) + i % 3] == k)
             return false;
     }
        
    return true;
}

bool solver(int matrix[9][9], int row, int col)
{
    if(row == 8 && col == 9)
        return true;
    
    if(col == 9)
    {
        row++;
        col = 0;
    }
    
    if(matrix[row][col] > 0) return solver(matrix, row, col + 1);
    
    for(int k = 1; k <= 9; k++)
    {
        if(isValid(matrix, row, col, k))
        {
            matrix[row][col] = k;
            if(solver(matrix, row, col + 1)) return true;
        }
        matrix[row][col] = 0;
    }   
    return false;  
}

bool isItSudoku(int matrix[9][9]) {
    return solver(matrix, 0, 0);
}
