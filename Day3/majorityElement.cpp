#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
    if(n == 1) return arr[0];
	int cnt = 0;
    int el = 0;
        
    for(int i = 0; i < n; i++)
    {
        if(cnt == 0)
            el = arr[i];

        if(el == arr[i])
            cnt++;

        else
            cnt--;
    }
        
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el)
            cnt++;
    }
    return cnt > n / 2 ? el : -1;
}
