int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at + n);
    sort(dt, dt + n);
    
    int i = 0, j = 0, cnt = 0;
    int min_plts = 0;
    while(i < n)
    {
        if(at[i] <= dt[j])
        {
            cnt++;
            i++;
        }
        else
        {
            cnt--;
            j++;
        }
        min_plts = max(cnt, min_plts);
    }
    return min_plts;
}
