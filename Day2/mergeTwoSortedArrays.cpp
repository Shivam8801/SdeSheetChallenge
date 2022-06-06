#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	int a3 = arr1.size() - 1;
    int a1 = arr1.size() - arr2.size() - 1;
    int a2 = arr2.size() - 1;
    
    while(a1 >= 0 || a2 >= 0)
    {
        if(arr1[a1] > arr2[a2])
        {
            arr1[a3] = arr1[a1];
            a1--;
            a3--;
        }
        else
        {
            arr1[a3] = arr2[a2];
            a2--;
            a3--;
        }
    }
    if(a2 < 0)
    {
        while(a3 >= 0)
        {
            arr1[a3] = arr1[a1];
            a1--;
            a3--;
        }    
    }
    else
    {
        while(a3 >= 0)
        {
            arr1[a3] = arr2[a2];
            a2--;
            a3--;
        }  
    }
    return arr1;
}
