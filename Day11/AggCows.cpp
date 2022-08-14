#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int> pos, int c, int dist)
{
    int cows = 1, idx = 0;
    for (int i = 1; i < pos.size(); i++)
    {
        if (pos[i] - pos[idx] >= dist)
        {
            cows++;
            idx = i;
        }
    }
    return cows >= c;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> pos(n);
        for (int &i : pos)
        {
            cin >> i;
        }
        sort(pos.begin(), pos.end());
        int low = pos[0], high = pos[n - 1] - pos[0];

        int res = -1;

        while (low <= high)
        {
            int mid = (low + high) >> 1;

            if (canPlace(pos, c, mid))
            {
                res = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        cout << res << "\n";
    }
    return 0;
}
