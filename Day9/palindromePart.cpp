vector<vector<string>> ans;

bool checkPal(string a, int start, int end)
{
    while(start > end)
        return true;
    if(a[start] != a[end]) return false;
    return checkPal(a, start + 1, end - 1);
}

void solver(vector<string> temp, string s, int idx)
{
    if(idx == s.size())
    {
        ans.push_back(temp);
        return;
    }
    
    for(int i = idx; i < s.size(); i++)
    {
        if(checkPal(s, idx, i))
        {
            temp.push_back(s.substr(idx, i - idx + 1));
            solver(temp, s, i + 1);
            temp.pop_back();
        }
    }
}


vector<vector<string>> partition(string &s) 
{
    int sz = s.size();
    vector<string> temp;
    solver(temp, s, 0);
    return ans;
}
