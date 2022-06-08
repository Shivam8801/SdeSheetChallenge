#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    vector<int> idx(256, -1);
    int sz = input.size();
    int max_len = 0;
    int left = 0, right = 0;
    
    while(right < sz)
    {
        if(idx[input[right]] != -1) 
        {
            left = max(left, idx[input[right]] + 1);
        }
        idx[input[right]] = right;
        
        max_len = max(max_len, right - left + 1);
        right++;
    }
    return max_len;
}
