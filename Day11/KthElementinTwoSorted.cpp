#include <climits>

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    if(m > n) return ninjaAndLadoos(row2, row1, n, m, k);
    if(k == (n + m)) return row2[n - 1];
    int low = max(0, k - m), high = min(k, n);

    while(low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = k - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : row1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : row2[cut2 - 1];
        int r1 = (cut1 == n) ? INT_MAX : row1[cut1];
        int r2 = (cut2 == m) ? INT_MAX : row2[cut2];

        if(l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if(l1 > r2)
        {
            high = cut1 - 1;
        }

        else
        {
            low = cut1 + 1;
        }
    }
    return 0;
}
