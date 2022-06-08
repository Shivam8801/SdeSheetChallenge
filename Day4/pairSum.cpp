#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
    unordered_map<int, int> comp;
    vector<vector<int>> ans;

    for(int i : arr)
    {
        if(comp.find(s - i) != comp.end())
        {
            int copy = comp[s - i];
            while(copy--)
            {
                vector<int> temp;
                int mini = min(i, s - i);
                temp.push_back(mini);
                temp.push_back(s - mini);
                ans.push_back(temp);
            }
        }
        comp[i]++; 
    }
    sort(ans.begin(), ans.end());
    return ans;
}
