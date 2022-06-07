#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	int total = m + n - 2;
    int row = m - 1;
    double ans = 1;
    for(int i = 1; i <= row; i++)
    {
        ans = ans * (total - row + i)/i;
    }
    return (int)ans;
}
