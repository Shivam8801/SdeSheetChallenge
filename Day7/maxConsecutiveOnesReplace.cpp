int longestSubSeg(vector<int> &arr , int n, int k){
    int i = 0, j = 0;
    
    while(i < n)
    {
        if(arr[i] == 0) k--;
        if(k < 0)
        {
            if(arr[j] == 0) k++;
            j++;
        }
        i++;
    }
    return i - j;
}
