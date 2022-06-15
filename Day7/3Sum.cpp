#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    
    vector<vector<int>> ans;
    if(n <= 2) return ans;
    
    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++)
    {
        int target = K - arr[i];
        int front = i + 1, back = n - 1;
        while(front < back)
        {
            int two_sum = arr[front] + arr[back];
            if(two_sum > target) back--;
            else if(two_sum < target) front++;
            else
            {
                vector<int> trio(3, 0);
                trio[0] = arr[i];
                trio[1] = arr[front];
                trio[2] = arr[back];
                ans.push_back(trio);
                
                while(front < back && arr[front] == trio[1]) front++;
                while(front < back && arr[back] == trio[2]) back--;
            }
            
        }
        while(i < n-1 && arr[i] == arr[i + 1]) i++;
    }
    return ans;
}
