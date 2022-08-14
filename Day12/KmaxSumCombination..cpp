#include<queue>
#include<algorithm>
#include<set>

class node
{
    public:
    int data, idx, jdx;
};

struct cmp{
    bool operator()(node a, node b)
    {
        return a.data < b.data;
    }
};

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
	// Write your code here.
    priority_queue<node, vector<node>, cmp> pq;
    set<pair<int, int>> s;
    vector<int> ans;
    
    pq.push({a[n - 1] + b[n - 1], n - 1, n - 1});
    s.insert({n - 1, n - 1});
    
    while(ans.size() != k)
    {
        node top = pq.top();
        pq.pop();
        int dt = top.data, i = top.idx, j = top.jdx;
        ans.push_back(dt);
        if(i > 0 && s.count({i - 1, j}) == 0)
        {
            pq.push({a[i - 1] + b[j], i - 1, j});
            s.insert({i - 1, j});
        }
        
        if(j > 0 && s.count({i, j - 1}) == 0)
        {
            pq.push({a[i] + b[j - 1], i, j - 1});
            s.insert({i, j - 1});
        }
    }
    return ans;
}
