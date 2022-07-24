#include <bits/stdc++.h>

int lessThanNum(vector<int> nums, int mid)
{
    int l = 0;
    int h = nums.size() - 1;
    
    while(l <= h)
    {
        int m = (l + h) >> 1;
        if(nums[m] <= mid)
            l = m + 1;
        else
            h = m - 1;
    }
    return l;
}


int getMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0;
    int high = 1e9;
    
    while(low <= high)
    {
        int mid = (low + high) >> 1;
        int cnt = 0;
        for(int i = 0; i < n; i++)
            cnt += lessThanNum(matrix[i], mid);
        
        if(cnt <= (n * m)/2) low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
