#include <bits/stdc++.h>

bool comparator(pair<int, int>a, pair<int, int>b)
{
    double vw1 = (double)a.second / (double) a.first;
    double vw2 = (double)b.second / (double) b.first;
    return vw1 > vw2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(), items.end(), comparator);
    
    double max_val = 0;
    for(int i = 0; i < n; i++)
    {
        if(items[i].first <= w)
        {
            max_val += items[i].second;
            w -= items[i].first;
        }
        
        else
        {
            double remain = ((double) items[i].second / (double) items[i].first) * w;
            max_val += remain;
            break;
        }
    }
    return max_val;
}
