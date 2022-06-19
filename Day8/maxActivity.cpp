#include <bits/stdc++.h>

struct activity{
    int start;
    int end;
};

bool comparator(struct activity a, struct activity b)
{
    return a.end < b.end;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    int sz = start.size();
    struct activity act[sz];
    
    for(int i = 0; i < sz; i++)
    {
        act[i].start = start[i];
        act[i].end = finish[i];
    }
    
    sort(act, act + sz, comparator);
    int limit = act[0].end, cnt = 1;
    
    for(int i = 1; i < sz; i++)
    {
        if(act[i].start >= limit)
        {
            limit = act[i].end;
            cnt++;
        }
    }
    return cnt;
}
