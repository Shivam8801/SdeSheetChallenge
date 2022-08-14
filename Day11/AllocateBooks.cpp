#include <algorithm>

bool canDistribute(vector<int>&arr, long long barrier, long long k, long long sz)
{
    long long pages = 0, studentNum = 1;
    for(long long i = 0; i < sz; i++)
    {
        if((arr[i] + pages) > barrier) 
        {
            studentNum++;
            pages = arr[i];
        }
        else
        {
            pages += arr[i];
        }
    }
    
    return studentNum <= k;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	if(n > time.size()) return -1;
    long long low = *max_element(time.begin(), time.end());
    long long high = 0;
    
    for(long long i = 0; i < time.size(); i++){
        high += time[i];
    }
    
    long long res = -1;
    
    while(low <= high)
    {
        long long mid = (low + high) >> 1;
        
        if(canDistribute(time, mid, n, time.size()))
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}
