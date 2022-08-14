vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    priority_queue<int, vector<int>, greater<int>> mini;
    vector<int> ans;
    for(int i = 0; i < q.size(); i++)
    {
        if(q[i].size() > 1)
        {
            mini.push(q[i][1]); 
        }
        else
        {
            ans.push_back(mini.top());
            mini.pop();
        }
    }
    return ans;
}
