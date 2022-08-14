bool canDistribute(vector<int>&arr, int barrier, int k, int sz)
{
    int pages = 0, studentNum = 1;
    for(int i = 0; i < sz; i++)
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

int Solution::books(vector<int> &A, int B) {
    if(B > A.size()) return -1;
    int low = *max_element(A.begin(), A.end()), high = 0;
    
    for(int i = 0; i < A.size(); i++){
        high += A[i];
    }
    
    int res = -1;
    
    while(low <= high)
    {
        int mid = (low + high) >> 1;
        
        if(canDistribute(A, mid, B, A.size()))
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
