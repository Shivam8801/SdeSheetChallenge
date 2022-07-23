void solver(string s, int n, vector<string> &ans, int idx)
{
    if(idx == n)
    {
        ans.push_back(s);
        return;
    }
    
    for(int i = idx; i < n; i++)
    {
        swap(s[i], s[idx]);
        solver(s, n, ans, idx + 1);
        swap(s[i], s[idx]);
    }
    return;
}

vector<string> findPermutations(string &s) {
    vector<string> ans;
    solver(s, s.size(), ans, 0);
    return ans;
}
