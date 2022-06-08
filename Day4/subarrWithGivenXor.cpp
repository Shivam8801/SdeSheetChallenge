#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    int xorr = 0;
    unordered_map<int, int> mp;
    int cnt = 0;
    
    for(int i : arr)
    {
        xorr = xorr ^ i;
        
        if(xorr == x)
            cnt++;
        if(mp.find(xorr ^ x) != mp.end())
            cnt += mp[xorr ^ x];
        
        mp[xorr] += 1;
    }
    return cnt;
}
