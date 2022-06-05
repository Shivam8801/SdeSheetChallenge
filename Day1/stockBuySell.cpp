#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int prof = 0;
    int mini = INT_MAX;
    int sz = prices.size();
    
    for(int i = 0; i < sz; i++)
    {
        mini = min(mini, prices[i]);
        prof = max(prof, prices[i] - mini);
    }
    return prof;
}
