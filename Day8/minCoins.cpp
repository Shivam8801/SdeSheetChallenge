int findMinimumCoins(int amount) 
{
    int den[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    
    int i = 0, cnt = 0;
    while(amount > 0)
    {
        if(amount - den[i] >= 0)
        {
            amount -= den[i];
            cnt++;
        }
        else i++;
    }
    return cnt;
}
