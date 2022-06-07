#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
	int ans = 1;
    long long _x = x, _n = n, _m = m;
    _x %= _m;
    
    while(_n)
    {
        if(_n & 1)
        {
            ans = (ans * _x) % _m;
        }
         _x = (_x * _x) % _m;
         _n >>= 1;
    }
    
    return ans; 
}
