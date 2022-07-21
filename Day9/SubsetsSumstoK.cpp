vector<vector<int>> ans;

void solver(vector<int> &arr, vector<int> &temp, int sum, int idx)
{
    if(sum == 0)
        {   
            ans.push_back(temp);
        }
        
        for(int i = idx; i < arr.size(); i++)
        {
            temp.push_back(arr[i]);
            solver(arr, temp, sum - arr[i], i + 1);
            temp.pop_back();
        }
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<int> temp;
    solver(arr, temp, k, 0);
    return ans;
}



