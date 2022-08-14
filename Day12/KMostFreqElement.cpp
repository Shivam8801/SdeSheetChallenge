#include<bits/stdc++.h>
typedef pair<int, int> pi;
  
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int, int> mp;
    for(int i : arr)
        mp[i]++;
    
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for(auto i : mp)
    {
        pq.push(make_pair(i.second, i.first));
        if(pq.size() > k) pq.pop(); 
    }
    vector<int> ans;
    while(!pq.empty())
    {
        pi temp = pq.top();
        ans.push_back(temp.second);
        pq.pop();
    }   
    sort(ans.begin(), ans.end());
    return ans;
}
