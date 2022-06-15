#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    int left = 0, right = n - 1;
    long leftmax = 0, rightmax = 0;
    long cnt = 0;
    
    while(left <= right)
    {
        if(arr[left] < arr[right])
        {
            if(arr[left] > leftmax)
                leftmax = arr[left];
            else
                cnt += leftmax - arr[left];
            left++;
        }
        
        else
        {
            if(arr[right] > rightmax)
                rightmax = arr[right];
            else
                cnt += rightmax - arr[right];
            right--;
        }
        
    }
    return cnt;
}
