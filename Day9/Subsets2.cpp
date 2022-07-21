#include<bits/stdc++.h>
void solver(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int N, int idx)
{
    ans.push_back(temp);
    for(int i = idx; i < N; i++)
    {
        if(i != idx && nums[i] == nums[i-1]) continue;
        temp.push_back(nums[i]);
        solver(nums, ans, temp, N, i + 1);
        temp.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<int> temp;
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    solver(arr, ans, temp, n, 0);
    return ans;
}
