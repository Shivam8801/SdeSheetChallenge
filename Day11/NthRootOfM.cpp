double multiply(double num, int n)
{
    double res = 1.0;
    for(int i = 1; i <= n; i++)
        res = res * num;
    return res;
}


double findNthRootOfM(int n, long long m) {
    
    double low = 1;
    double high = m;
    double eps = 1e-6;
    
    while(double(high - low) > eps)
    {
        double mid = (low + high) / 2.0;
        
        if(multiply(mid, n) > m)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    return high;
}
