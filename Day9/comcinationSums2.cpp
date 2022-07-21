#include<bits/stdc++.h>

void solver(vector<vector<int>> &ans, vector<int> &arr, vector<int> &temp, int target, int idx)
{
    if(target == 0)
    {
        ans.push_back(temp);
    }
    for(int i = idx; i < arr.size(); i++)
    {
        if(i > idx && arr[i] == arr[i - 1]) continue;
        temp.push_back(arr[i]);
        solver(ans, arr, temp, target - arr[i], i + 1);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    vector<int> temp;
    solver(ans, arr, temp, target, 0);
    return ans;
}
