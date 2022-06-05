#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    if(n == 0)
        return 0;
    
    long long max_sum = arr[0], best = arr[0];
    for(int i = 1; i < n; i++)
    {
        long long temp = arr[i];
        max_sum = max(temp, max_sum + temp);
        best = max(max_sum, best);
    }
    return best < 0 ? 0 : best;
}
