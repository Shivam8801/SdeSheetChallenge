string kthPermutation(int n, int k) {
    k--;
    int fact = 1;
    vector<int> nums;
    for(int i = 1; i < n; i++)
    {
        nums.push_back(i);
        fact *= i;
    }
    nums.push_back(n);
    
    string ans = "";
    while(true)
    {
        ans += to_string(nums[k/fact]);
        nums.erase(nums.begin() + k/fact);
        if(nums.size() == 0) break;
        k = k % fact;
        fact /= nums.size();
    }
    return ans;
}
