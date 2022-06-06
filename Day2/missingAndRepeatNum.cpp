#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	bool present[n + 1] = {false};
    pair<int, int> pr;
    
    for(auto i : arr)
    {
        if(!present[i]) present[i] = 1;
        else pr.second = i;
    }
    for(int i = 1; i <= n; i++)
    {
        if(!present[i]) pr.first = i;
    }
    return pr;
}
