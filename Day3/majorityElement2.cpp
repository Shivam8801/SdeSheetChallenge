#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    int e1 = -1, e2 = -1;
    int c1 = 0, c2 = 0;
    int sz = arr.size();
    vector<int> ans;
    
    for(int it : arr)
    {
        if(it == e1) c1++;
        else if (it == e2) c2++;
        
        else if(c1 == 0) 
        {
            e1 = it;
            c1 = 1;
        }
        else if(c2 == 0)
        {
            e2 = it;
            c2 = 1;
        }
        else
        {
            c1--;
            c2--;
        }
    }

    c1 = 0, c2 = 0;
    for(int it : arr)
    {
        if(it == e1) c1++;
        else if(it == e2) c2++;
    }
    
    if(c1 > sz/3) ans.push_back(e1);
    if(c2 > sz/3) ans.push_back(e2);
    return ans;
}
