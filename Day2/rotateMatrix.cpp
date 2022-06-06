#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int row = 0;
    int col = 0;
    int lastrow = n;
    int lastcol = m;

    int prev, curr;

    while (row < lastrow && col < lastcol)
    {
        if (row + 1 == lastrow || col + 1 == lastcol)
            break;

        prev = mat[row + 1][col];

        for (int i = col; i < lastcol; i++)
        {
            curr = mat[row][i];
            mat[row][i] = prev;
            prev = curr;
        }
        row++;

        for (int i = row; i < lastrow; i++)
        {
            curr = mat[i][lastcol - 1];
            mat[i][lastcol - 1] = prev;
            prev = curr;
        }
        lastcol--;

        if (row < lastrow)
        {
            for (int i = lastcol - 1; i >= col; i--)
            {
                curr = mat[lastrow - 1][i];
                mat[lastrow - 1][i] = prev;
                prev = curr;
            }
        }
        lastrow--;

        if (col < lastcol)
        {
            for (int i = lastrow - 1; i >= row; i--)
            {
                curr = mat[i][col];
                mat[i][col] = prev;
                prev = curr;
            }
        }
        col++;
    }

}
