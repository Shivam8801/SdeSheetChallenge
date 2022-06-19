#include <bits/stdc++.h>

struct meeting
{
    int start;
    int end;
    int pos;
};

bool comparator(struct meeting a, struct meeting b)
{
    if(a.end < b.end) return true;
    else if(a.end > b.end) return false;
    else if(a.pos < b.pos) return true;
    return false;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    
    int sz = end.size();
    struct meeting meet[sz];

    for(int i = 0; i < sz; i++)
    {
        meet[i].start = start[i], meet[i].end = end[i], meet[i].pos = i + 1;
    }
    
    sort(meet, meet + sz, comparator);
    
    vector<int> ans;
    
    int limit = meet[0].end;
    ans.push_back(meet[0].pos);
    
    for(int i = 1; i < end.size(); i++)
    {
        if(meet[i].start > limit)
        {
            limit = meet[i].end;
            ans.push_back(meet[i].pos);
        }
    }
    return ans;
}
