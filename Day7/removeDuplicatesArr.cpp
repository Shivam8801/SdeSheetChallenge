int removeDuplicates(vector<int> &arr, int n) {   
    if(n == 1) return 1;
    
	int cnt = 0;
    
    for(int i = 0; i < n - 1; i++)
    {
        if (arr[i] != arr[i + 1])
            cnt = cnt + 1;
    }
    return cnt + 1;
}
