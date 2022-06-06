#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> _mergeIntervals;
    int sz = intervals.size();
    if(sz == 0)
        return _mergeIntervals;
    
    sort(intervals.begin(), intervals.end());
    
    vector<int> tempInterval = intervals[0];
    
    for(auto it : intervals)
    {
        if(it[0] <= tempInterval[1])
        {
            tempInterval[1] = max(it[1], tempInterval[1]);
        }
        
        else
        {
            _mergeIntervals.push_back(tempInterval);
            tempInterval = it;
        }
    }
    _mergeIntervals.push_back(tempInterval);
    return _mergeIntervals;
}
