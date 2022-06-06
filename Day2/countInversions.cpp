long long merge(long long arr[], long long temp[], int l, int mid, int r)
{
   long long inversion = 0;

   int i = l , k = l;
   int j = mid;

    while ((i <= mid - 1) &&(j <= r))
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];

        else
        {
            temp[k++] = arr[j++];
            inversion += (mid - i);
        }
    }

    while (i <= mid - 1)
    {
        temp[k++] = arr[i++];
    }

    while (j <= r)
    {
        temp[k++] = arr[j++];
    }   

    for (int i = l; i <= r; i++)
    {
        arr[i] = temp[i];
    }

    return inversion;
}

long long _mergeSort(long long arr[], long long temp[], int l, int r)
{
    long long inversion = 0;
    if (l < r)  
    {
        int mid = (l + r) / 2;

        inversion += _mergeSort(arr, temp, l, mid);
        inversion += _mergeSort(arr, temp, mid + 1, r);

        inversion += merge(arr, temp, l, mid + 1, r);
    }

    return inversion;
}

long long getInversions(long long *arr, int n){
	if(n == 0 || n == 1)
        return 0;
        
	long long temp[n];
	long long ans = _mergeSort(arr, temp, 0, n-1);
	return ans;
}
