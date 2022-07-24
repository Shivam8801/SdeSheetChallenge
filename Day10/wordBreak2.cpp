#include <bits/stdc++.h>
void solver(string &s, vector<string> &dictionary, string temp, vector<string> &ans)
{
    if(s.size() == 0)
    {
        ans.push_back(temp);
        return;
    }
    
    for(int i = 0; i < s.size(); i++)
    {
        string left = s.substr(0, i + 1);
        if(count(dictionary.begin(), dictionary.end(), left))
        {
            string right = s.substr(i + 1);
            solver(right, dictionary, temp + left + " ", ans);
        }           
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> ans;
    solver(s, dictionary, "", ans);
    return ans;
}
