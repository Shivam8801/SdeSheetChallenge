#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    int rows = mat.size();
    int cols = mat[0].size();
    
    int l = 0, r = rows * cols - 1;
    
    while(l <= r)
    {
        int mid = l + (r - l)/2;
        
        if(mat[mid / cols][mid % cols] == target)
            return true;
        
        if(mat[mid / cols][mid % cols] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return false;
}
