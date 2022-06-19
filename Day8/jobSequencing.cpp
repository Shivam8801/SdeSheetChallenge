#include <bits/stdc++.h>

bool comparator(vector<int> a, vector<int> b)
{
    return a[1] > b[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{
    int sz = jobs.size();
    int max_dead = 0;
    for(int i = 0; i < sz; i++)
    {
        max_dead = max(jobs[i][0], max_dead);
    }
    
    sort(jobs.begin(), jobs.end(), comparator);
    vector<int> idx(max_dead + 1, -1);
    
    int max_prof = 0;
    for(int i = 0; i < sz; i++)
    {
        if(jobs[i][0] <= max_dead)
        {
            for(int j = jobs[i][0]; j > 0; j--)
            {
                if(idx[j] == -1)
                {
                    idx[j] = i;
                    max_prof += jobs[i][1];
                    break;
                }

            }
        }
    }
    
    return max_prof;
    
}
