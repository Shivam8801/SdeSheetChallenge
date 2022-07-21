void solver(vector<int> &num, vector<int> &ans, int N, int temp, int sum)
{
    if(temp == N)
    {
        ans.push_back(sum);
        return;
    }
    
    // exclusion
    solver(num, ans, N, temp + 1, sum);
    // inclusion
    solver(num, ans, N, temp + 1, sum + num[temp]);
    return;
}
